/* GDB-friendly replacement for <locale.h>.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef COMMON_GDB_LOCALE_H
#define COMMON_GDB_LOCALE_H

#ifdef HAVE_LOCALE_H
# include <locale.h>
#endif
#ifdef ENABLE_NLS
#undef ENABLE_NLS
#endif
#ifdef ENABLE_NLS
# include <libintl.h>
# define _(String) gettext (String)
# ifdef gettext_noop
#  define N_(String) gettext_noop (String)
# else
#  define N_(String) (String)
# endif
#else
# define _(String) (String)
# define N_(String) (String)
#endif

#ifdef HAVE_LANGINFO_CODESET
#include <langinfo.h>
#endif

#endif /* COMMON_GDB_LOCALE_H */

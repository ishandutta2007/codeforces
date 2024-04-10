#include <stdio.h>
#include <string.h>

int main()
{
     char s[100005];
     char c[100005];
     char t[6][6] = {"lios", "liala", "etr", "etra", "initis", "inites"};
     int x = 0, y = 0, z = 0, f = 0, i, j;
     int a[6] = {4, 5, 3, 4, 6, 6};

     fgets(s, 100005, stdin);

     s[strlen(s) - 1] = '\0';

     for (i = 0; i < strlen(s); i++) {
	  int p = 0, q = 0;

	  for (j = i; j < strlen(s); j++) {
	       if (s[j] == ' ' || s[j] == '\0') break;

	       c[p++] = s[j];
	  }

	  c[p] = '\0';

	  i = j;

	  for (j = 0; j < 6; j++) {
	       if (p < a[j]) continue;

	       if (strncmp(&c[p - a[j]], t[j], a[j]) == 0) break;
	  }

	  if (j == 6) {
	       puts("NO");

	       return 0;
	  }

	  if (s[i] == '\0' && x + y + z == 0) {
	       puts("YES");

	       return 0;
	  }

	  switch (j) {
	  case 0 : if (f == 2 || y > 0 || z > 0) {
		    q = 1;
	       } else {
		    x++;
		    f = 1;
	       }
	       break;
	  case 1 : if (f == 1 || y > 0 || z > 0) {
		    q = 1;
	       } else {
		    x++;
		    f = 2;
	       }
	       break;
	  case 2 : if (f == 2 || y > 0 || z > 0) {
		    q = 1;
	       } else {
		    y++;
		    f = 1;
	       }
	       break;
	  case 3 : if (f == 1 || y > 0 || z > 0) {
		    q = 1;
	       } else {
		    y++;
		    f = 2;
	       }
	       break;
	  case 4 : if (f == 2 || y == 0) {
		    q = 1;
	       } else {
		    z++;
		    f = 1;
	       }
	       break;
	  case 5 : if (f == 1 || y == 0) {
		    q = 1;
	       } else {
		    z++;
		    f = 2;
	       }
	       break;
	  }

	  if (q == 1) {
	       puts("NO");

	       return 0;
	  }
     }

     if (y == 0) {
	  puts("NO");
     } else {
	  puts("YES");
     }

     return 0;
}
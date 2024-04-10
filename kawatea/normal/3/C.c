#include <stdio.h>

int main()
{
     char s[3][4];
     int i, j;
     int a[2] = {0};
     int b[2] = {0};

     for (i = 0; i < 3; i++) scanf("%s", s[i]);

     for (i = 0; i < 3; i++) {
	  for (j = 0; j < 3; j++) {
	       if (s[i][j] == '0') {
		    a[0]++;
	       } else if (s[i][j] == 'X') {
		    a[1]++;
	       }
	  }
     }

     if (a[0] > 4 || a[1] > 5 || a[0] > a[1] || a[1] > a[0] + 1) {
	  puts("illegal");

	  return 0;
     }

     for (i = 0; i < 3; i++) {
	  if (s[i][0] == s[i][1] && s[i][1] == s[i][2]) {
	       if (s[i][0] == '0') {
		    b[0]++;
	       } else if (s[i][0] == 'X') {
		    b[1]++;
	       }
	  }

	  if (s[0][i] == s[1][i] && s[1][i] == s[2][i]) {
	       if (s[0][i] == '0') {
		    b[0]++;
	       } else if (s[0][i] == 'X') {
		    b[1]++;
	       }
	  }
     }

     if (s[0][0] == s[1][1] && s[1][1] == s[2][2]) {
	  if (s[0][0] == '0') {
	       b[0]++;
	  } else if (s[0][0] == 'X') {
	       b[1]++;
	  }
     }

     if (s[0][2] == s[1][1] && s[1][1] == s[2][0]) {
	  if (s[0][2] == '0') {
	       b[0]++;
	  } else if (s[0][2] == 'X') {
	       b[1]++;
	  }
     }

     if (b[0] > 0 && b[1] > 0) {
	  puts("illegal");

	  return 0;
     }

     if (b[0] > 0) {
	  if (a[0] < a[1]) {
	       puts("illegal");
	  } else {
	       puts("the second player won");
	  }

	  return 0;
     }

     if (b[1] > 0) {
	  if (a[0] == a[1]) {
	       puts("illegal");
	  } else {
	       puts("the first player won");
	  }

	  return 0;
     }

     if (a[0] + a[1] == 9) {
	  puts("draw");

	  return 0;
     }

     if (a[0] == a[1]) {
	  puts("first");
     } else {
	  puts("second");
     }

     return 0;
}
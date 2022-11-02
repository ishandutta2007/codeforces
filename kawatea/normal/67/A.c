#include <stdio.h>

int max(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, c = 1, i, j;
     char s[1000];
     int a[1000] = {0};

     scanf("%d", &n);
     scanf("%s", s);

     for (i = 0; i < n - 1; i++) {
	  if (s[i] == 'L') {
	       c++;
	  } else if (s[i] == 'R') {
	       break;
	  }
     }

     a[0] = c;

     for (i = 1; i < n; i++) {
	  if (s[i - 1] == 'L') {
	       c = 1;

	       for (j = i; j < n - 1; j++) {
		    if (s[j] == 'L') {
			 c++;
		    } else if (s[j] =='R') {
			 break;
		    }
	       }

	       a[i] = c;
	  } else if (s[i - 1] == '=') {
	       a[i] = a[i - 1];
	  } else {
	       c = 1;

	       for (j = i; j < n - 1; j++) {
		    if (s[j] == 'L') {
			 c++;
		    } else if (s[j] == 'R') {
			 break;
		    }
	       }

	       a[i] = max(c, a[i - 1] + 1);
	  }
     }

     for (i = 0; i < n; i++) {
	  printf("%d", a[i]);

	  if (i < n - 1) putchar(' ');
     }

     putchar('\n');

     return 0;
}
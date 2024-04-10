#include <stdio.h>
#include <string.h>

int main()
{
     int n, i;
     char s1[100001], s2[100001];
     int a[2] = {0};

     scanf("%s", s1);
     scanf("%s", s2);

     n = strlen(s1);

     for (i = 0; i < n; i++) {
	  if (s1[i] != s2[i]) {
	       if (s1[i] == '4') {
		    a[0]++;
	       } else {
		    a[1]++;
	       }
	  }
     }

     if (a[0] > a[1]) {
	  printf("%d\n", a[0]);
     } else {
	  printf("%d\n", a[1]);
     }

     return 0;
}
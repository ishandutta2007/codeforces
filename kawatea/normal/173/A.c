#include <stdio.h>
#include <string.h>

int a[1000001][2];

int main()
{
     int n, m, k, p, q, i;
     char s1[1001], s2[1001];

     scanf("%d", &n);
     scanf("%s", s1);
     scanf("%s", s2);

     m = strlen(s1);
     k = strlen(s2);

     for (i = 0; i < m * k; i++) {
	  a[i + 1][0] = a[i][0];
	  a[i + 1][1] = a[i][1];

	  if (s1[i % m] != s2[i % k]) {
	       if ((s1[i % m] == 'R' && s2[i % k] == 'P') || (s1[i % m] == 'P' && s2[i % k] == 'S') || (s1[i % m] == 'S' && s2[i % k] == 'R')) {
		    a[i + 1][0]++;
	       } else {
		    a[i + 1][1]++;
	       }
	  }
     }

     m *= k;

     p = n / m * a[i][0] + a[n % m][0];
     q = n / m * a[i][1] + a[n % m][1];

     printf("%d %d\n", p, q);

     return 0;
}
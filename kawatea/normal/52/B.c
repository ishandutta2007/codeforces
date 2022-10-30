#include <stdio.h>

int main()
{
     int n, m, i, j, k;
     long long sum = 0;
     char s[1000][1001];
     int a[1000][4] = {0};
     int b[1000][4] = {0};

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       if (s[i][j] == '*') {
		    for (k = 0; k < 4; k++) {
			 a[i][k]++;
			 b[j][k]++;
		    }
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       if (s[i][j] == '*') {
		    sum += (a[i][0] - 1) * (b[j][0] - 1);
		    a[i][0]--;
		    b[j][0]--;
	       }
	  }

	  for (j = m - 1; j >= 0; j--) {
	       if (s[i][j] == '*') {
		    sum += (a[i][1] - 1) * (b[j][1] - 1);
		    a[i][1]--;
		    b[j][1]--;
	       }
	  }
     }

     for (i = n - 1; i >= 0; i--) {
	  for (j = 0; j < m; j++) {
	       if (s[i][j] == '*') {
		    sum += (a[i][2] - 1) * (b[j][2] - 1);
		    a[i][2]--;
		    b[j][2]--;
	       }
	  }

	  for (j = m - 1; j >= 0; j--) {
	       if (s[i][j] == '*') {
		    sum += (a[i][3] - 1) * (b[j][3] - 1);
		    a[i][3]--;
		    b[j][3]--;
	       }
	  }
     }

     printf("%I64d\n", sum);

     return 0;
}
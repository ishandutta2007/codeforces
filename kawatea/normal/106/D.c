#include <stdio.h>

int d[1000][1000][4];

int main()
{
     int n, m, k, i, j;
     char s[1000][1001];
     int a[26][2];

     for (i = 0; i < 26; i++) {
	  for (j = 0; j < 2; j++) {
	       a[i][j] = -1;
	  }
     }

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
	  for (j = 1; j < m; j++) {
	       if (s[i][j - 1] != '#') d[i][j][0] = d[i][j - 1][0] + 1;
	  }

	  for (j = m - 2; j >= 0; j--) {
	       if (s[i][j + 1] != '#') d[i][j][1] = d[i][j + 1][1] + 1;
	  }
     }

     for (i = 0; i < m; i++) {
	  for (j = 1; j < n; j++) {
	       if (s[j - 1][i] != '#') d[j][i][2] = d[j - 1][i][2] + 1;
	  }

	  for (j = n - 2; j >= 0; j--) {
	       if (s[j + 1][i] != '#') d[j][i][3] = d[j + 1][i][3] + 1;
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
		    a[s[i][j] - 'A'][0] = i;
		    a[s[i][j] - 'A'][1] = j;
	       }
	  }
     }

     scanf("%d", &k);

     for (i = 0; i < k; i++) {
	  char c[2];
	  int x;

	  scanf("%s %d", c, &x);

	  for (j = 0; j < 26; j++) {
	       if (a[j][0] == -1) continue;

	       switch (c[0]) {
	       case 'N' : if (d[a[j][0]][a[j][1]][2] >= x) {
			 a[j][0] -= x;
		    } else {
			 a[j][0] = a[j][1] = -1;
		    }
		    break;
	       case 'S' : if (d[a[j][0]][a[j][1]][3] >= x) {
			 a[j][0] += x;
		    } else {
			 a[j][0] = a[j][1] = -1;
		    }
		    break;
	       case 'W' : if (d[a[j][0]][a[j][1]][0] >= x) {
			 a[j][1] -= x;
		    } else {
			 a[j][0] = a[j][1] = -1;
		    }
		    break;
	       case 'E' : if (d[a[j][0]][a[j][1]][1] >= x) {
			 a[j][1] += x;
		    } else {
			 a[j][0] = a[j][1] = -1;
		    }
	       }
	  }
     }

     for (i = 0; i < 26; i++) {
	  if (a[i][0] >= 0) break;
     }

     if (i == 26) {
	  puts("no solution");
     } else {
	  for (i = 0; i < 26; i++) {
	       if (a[i][0] >= 0) putchar('A' + i);
	  }
	  puts("");
     }

     return 0;
}
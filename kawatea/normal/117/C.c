#include <stdio.h>

char s[5000][5001];
int a[5000][5000], e[5000][5000];
int p[5000], b[5000], c[5000], d[5005];
int n, f;

void dfs(int x)
{
     int i, j, k;

     b[x] = 1;

     if (f == 1) return;

     for (i = 0; i < p[x]; i++) {
          if (b[e[x][i]] == 0) {
               c[e[x][i]] = x;
               dfs(e[x][i]);

               if (f == 1) return;
          } else if (b[e[x][i]] == 1) {
               int q = 0, t = e[x][i];

               f = 1;

               d[q++] = t;
               while (x != t) {
                    d[q++] = x;
                    x = c[x];
               }
               d[q++] = t;

               for (j = 0; j < q - 1; j++) {
                    for (k = 0; k < n; k++) {
                         if (a[d[j]][k] == 1 && a[k][d[j + 1]] == 1) {
                              printf("%d %d %d\n", d[j] + 1, k + 1, d[j + 1] + 1);

                              return;
                         }
                    }
               }
          }
     }

     b[x] = 2;
}

int main()
{
     int i, j;

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
          for (j = 0; j < n; j++) {
	       if (s[i][j] == '1') {
		    a[i][j] = 1;
		    e[i][p[i]++] = j;
	       }
          }
     }

     for (i = 0; i < n; i++) {
          if (b[i] == 0) {
               dfs(i);

               if (f == 1) return 0;
          }
     }

     puts("-1");

     return 0;
}
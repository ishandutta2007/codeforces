#include <stdio.h>

int a[2000];

int dfs(int x)
{
     if (a[x] == -1) return 1;

     return dfs(a[x]) + 1;
}

int main()
{
     int n, max = 0, i;

     scanf("%d", &n);

     for (i = 0; i < n; i++) a[i] = -1;

     for (i = 0; i < n; i++) {
	  int p;

	  scanf("%d", &p);

	  if (p != -1) a[i] = p - 1;
     }

     for (i = 0; i < n; i++) {
	  int d = dfs(i);

	  if (d > max) max = d;
     }

     printf("%d\n", max);

     return 0;
}
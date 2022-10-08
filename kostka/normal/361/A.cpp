#include<cstdio>

const int MAXN = 107;
static int tab[MAXN][MAXN];

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      tab[i][j] = (k/n);
  for(int i=0; i<n; i++)
    tab[i][i] += k%n;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
      printf("%d ", tab[i][j]);
    printf("\n");
  }
  return 0;
}
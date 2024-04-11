#include "bits/stdc++.h"

using namespace std;

const int MAXN = 2007;
int tab[MAXN];

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++)
    scanf("%d", tab+i);
  sort(tab, tab + n);
  reverse(tab, tab + n);
  long long wyn = 0;
  for(int i=0; i<n; i+=k)
    wyn += 2*(tab[i]-1);
  printf("%I64d\n", wyn);
  return 0;
}
#include "bits/stdc++.h"

using namespace std;

int tab[1007];
long long koszt[1007];
vector <int> G[1007];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++)
    scanf("%d", &tab[i]);
  long long wyn = 0;
  while(m--)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    wyn += min(tab[a],tab[b]);
  }
  printf("%lld\n", wyn);
}
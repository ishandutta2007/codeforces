#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
int tab[MAXN], tmp[MAXN], tab2[MAXN], tmp2[MAXN], pref[MAXN];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++)
    scanf("%d", &tab2[i]);
  for(int i=0; i<m; i++)
    scanf("%d", &tmp2[i]);
  for(int i=1; i<n; i++)
    tab[i] = tab2[i] - tab2[i-1];
  for(int i=1; i<m; i++)
    tmp[i-1] = tmp2[i] - tmp2[i-1];
  m--;
  pref[1]=0;
  int ost = 0, ile = 0;
  for(int i=1; i<m; i++)
  {
    while(ost>0 && tmp[ost]!=tmp[i])
      ost = pref[ost];
    if(tmp[ost]==tmp[i])
      ost++;
    pref[i+1]=ost;
  }
  ost = 0;
  for(int j=0; j<n; j++)
  {
    while(ost>0 && tmp[ost]!=tab[j])
      ost = pref[ost];
    if(tmp[ost]==tab[j])
      ost++;
    if(ost==m)
    {
      ile++;
      ost = pref[ost];
    }
  }
  bool czy = true;
  for(int i=0; i<m; i++)
    if(tab[i]!=tmp[i])
      czy = false;
  if(czy)
    ile--;
  //printf("%d\n", czy);
  if(m==0)
    printf("%d\n", n);
  else
    printf("%d\n", ile);
  return 0;
}
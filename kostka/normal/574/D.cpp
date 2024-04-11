#include "bits/stdc++.h"

using namespace std;

int n;
const int MAXN = 100007;
int tab[MAXN];
int lef[MAXN], rig[MAXN];

int check(int x)
{
  lef[0] = -x;
  rig[n+1] = -x;
  for(int i=1; i<=n; i++)
    lef[i] = min(lef[i-1]+1, tab[i]); 
  for(int i=n; i>=1; i--)
    rig[i] = min(rig[i+1]+1, tab[i]);
  int res = min(lef[1], rig[1]);
  for(int i=2; i<=n; i++) 
    res = max(res, min(lef[i], rig[i]));
  return res;
}

int main()
{
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> tab[i];
  cout << check(0) << "\n";
  return 0;
}
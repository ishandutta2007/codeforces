#include "bits/stdc++.h"

using namespace std;

const int MOD = 1000003;

int pot(int a, int b)
{
  if(!b)
    return 1;
  int x = pot(a, b/2);
  int y = (1LL*x*x)%MOD;
  if(b%2 == 0)
    return y;
  else
    return (1LL*a*y)%MOD;
}

int odw(int a)
{
  return pot(a, MOD-2);
}

const int MAXC = 700000;
int sil[MAXC], odwsil[MAXC];

int binomial(int a, int b)
{
  int res = sil[a];
  res = (1LL*res*odwsil[b])%MOD;
  res = (1LL*res*odwsil[a-b])%MOD;
  return res;
}

int main()
{
  int n, c;
  cin >> n >> c;
  sil[0] = 1;
  for(int i=1; i<=n+c; i++)
    sil[i] = (1LL * sil[i-1] * i) % MOD;
  odwsil[n+c] = odw(sil[n+c]);
  for(int i=n+c; i>0; i--)
    odwsil[i-1] = (1LL * odwsil[i] * i) % MOD;
  //assert((1LL * sil[5] * odwsil[5])%MOD == 1);
  cout << (binomial(n+c, c) - 1 + MOD)%MOD << "\n";
}
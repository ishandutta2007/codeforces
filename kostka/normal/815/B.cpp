//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9+7;

const int MAXN = 200000;
int a[MAXN], war[MAXN], nwar[MAXN];

int sil[MAXN], odw[MAXN];

int pot(int a, int b)
{
  if(b == 0)
    return 1;
  int w = pot(a, b/2);
  int w2 = (1LL*w*w)%MOD;
  if(b%2)
    return (1LL*a*w2)%MOD;
  else
    return w2;
}

void preprocessing(int n)
{
  sil[0] = 1;
  for(int i=1; i<=n; i++)
    sil[i] = (1LL * sil[i-1] * i) % MOD;
  odw[n] = pot(sil[n], MOD-2);
  for(int i=n-1; i>=0; i--)
    odw[i] = (1LL * odw[i+1] * (i+1)) % MOD;
  //assert((1LL * odw[3] * sil[3]) % MOD == 1);
}

int comb(int n, int k)
{
  return ((1LL * sil[n] * odw[n-k] % MOD) * odw[k]) % MOD;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  preprocessing(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  if(n%4)
  {
    int kt = (n-1)/2/2*2;
    for(int i=0; i<=2*kt; i+=2)
      war[i] = comb(kt,i/2);
    int kroki = (n-2*kt-1);
    while(kroki--)
    {
      for(int i=1; i<=n; i++)
      {
        if(i%2)
          nwar[i] = war[i-1];
        else
          nwar[i] = -war[i-1];
      }
      for(int i=0; i<=n; i++)
        war[i] = (war[i] + nwar[i])%MOD;
    }
  }
  else
  {
    int kt = n/2-1;
    for(int i=0; i<n; i+=2)
      war[i] = comb(kt,i/2);
    for(int i=1; i<n; i+=2)
      war[i] = -comb(kt,i/2);
  }
  long long res = 0;
  for(int i=0; i<n; i++)
  {
    res += (1LL * war[i] * a[i]);
    res %= MOD;
    res += MOD;
    res %= MOD;
  }
  cout << res << "\n";
  return 0;
}
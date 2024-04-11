//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 5000007;
int pri[MAXN];
long long fun[MAXN];
const int MOD = 1e9+7;

void sito(int n)
{
  for(int i=2; i*i<=n; i++)
    if(pri[i] == 0)
      for(int j=i*i; j<=n; j+=i)
        if(pri[j] == 0)
          pri[j] = i;
  for(int i=2; i<=n; i++)
    if(pri[i] == 0)
      pri[i] = i;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t, l, r;
  cin >> t >> l >> r;
  sito(r);

  for(int i=2; i<=r; i++)
  {
    int groups = i/pri[i];
    int howmany = pri[i];
    fun[i] = fun[groups] + (1LL * howmany * (howmany-1)/2) % MOD * groups % MOD;
    fun[i] %= MOD;
  }
  long long res = 0, tt = 1;
  for(int i=l; i<=r; i++)
  {
    res = (fun[i] * tt % MOD + res) % MOD;
    tt = (tt * t) % MOD;
  }
  cout << res << "\n";
  return 0;
}
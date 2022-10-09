//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 4007,
          MOD = 1000*1000*1000+7;
int dp[MAXN][MAXN];
long long res[MAXN];

int binom()
{
  for(int i=0; i<=4000; i++)
  {
    dp[i][0] = 1;
    for(int j=1; j<=i; j++)
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
  }
}

long long foo(int n)
{
  if(res[n])
    return res[n];
  res[n] = 1;
  for(int i=1; i<n; i++)
  {
    res[n] += 1LL*(1LL+dp[n-1][i])*foo(i);
    res[n] %= MOD;
  }
  return res[n];
}

int main()
{
  binom();
  int n;
  cin >> n;
  cout << foo(n) << "\n";
  return 0;
}
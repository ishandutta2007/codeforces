//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 107;
const int INF = 1e9 + 7;
int w[MAXN];
int dp[MAXN][3];

bool cmp(int a, int b)
{
  return a<b;
}

int main()
{
  int n;
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> w[i];
  for(int i=1; i<=n; i++)
    dp[i][0] = dp[i][1] = dp[i][2] = INF;
  for(int i=1; i<=n; i++)
  {
    if(w[i] & 2)
      dp[i][2] = min({dp[i][2], dp[i-1][1], dp[i-1][0]});
    if(w[i] & 1)
      dp[i][1] = min({dp[i][1], dp[i-1][2], dp[i-1][0]});
    dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
  }
  cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
  return 0;
}
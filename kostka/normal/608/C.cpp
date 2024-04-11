//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <pair <int, int> > X;

const int MAXN = 100007;
int dp[MAXN];

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    X.emplace_back(a,b);
  }
  X.emplace_back(-1000007, 0);
  sort(X.begin(), X.end());
  dp[0] = 0;
  for(int i=1; i<(int)X.size(); i++)
  {
    int alive = (upper_bound(X.begin(), X.end(), make_pair(X[i].first - X[i].second, -1)) - X.begin());
    dp[i] = dp[alive-1] + 1;
  }
  int res = 0;
  for(int i=0; i<(int)X.size(); i++)
    res = max(res, dp[i]);
  cout << n-res << "\n";
  return 0;
}
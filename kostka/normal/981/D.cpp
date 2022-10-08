//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

int n, k;
vector <ll> A;

ll sum(int a, int b) {
  return A[b] - A[a-1];
}

bool check(ll x) {
  bool dp[k+7][n+7];
  for(int i=0; i<=k; i++) for(int j=0; j<=n; j++) dp[i][j] = false;
  dp[0][0] = true;
  for(int i=1; i<=k; i++) {
    for(int b=1; b<=n; b++) {
      for(int a=0; a<b; a++) {
        if(!dp[i-1][a]) continue;
        if((x & sum(a+1,b)) == x)
          dp[i][b] = true;
      }
    }
  }
  return dp[k][n];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  A.resize(n+7);
  for(int i=1; i<=n; i++) {
    cin >> A[i];
    A[i] += A[i-1];
  }
  ll res = 0;
  for(int i=62; i>=0; i--) {
    if(check(res | 1LL<<i)) {
      res |= 1LL<<i;
    }
  }
  cout << res << "\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
vector<int> child[200000];
ll dp[200000][3];

ll inv(ll a) {
  ll p = mod-2, r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

void rec(int p) {
  if (child[p].empty()) {
    dp[p][2] = 1;
  } else {
    dp[p][0] = 1;
    dp[p][2] = 1;
    for (int i : child[p]) {
      rec(i);
      (dp[p][0] *= dp[i][0]+dp[i][2]) %= mod;
      (dp[p][1] += (dp[i][1]+dp[i][2])*inv(dp[i][0]+dp[i][2])) %= mod;
      (dp[p][2] *= dp[i][0]+dp[i][1]+dp[i][2]*2) %= mod;
    }
    dp[p][1] = dp[p][1]*dp[p][0]%mod;
    (dp[p][2] -= dp[p][1]+dp[p][0]) %= mod;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    child[p].push_back(i);
  }
  rec(0);
  cout << ((dp[0][0]+dp[0][2])%mod+mod)%mod << endl;
}
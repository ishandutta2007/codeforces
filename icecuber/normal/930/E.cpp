#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9+7;
const int nax = 4e5+10;

int l[2][nax], r[2][nax];
int reach[nax][2];
ll dp[nax][2];

ll bin_pow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

int main() {
  int k, n[2];
  cin >> k >> n[0] >> n[1];

  //Positions we want to calculate dp
  vector<int> pos;
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n[t]; i++) {
      cin >> l[t][i] >> r[t][i];
      l[t][i]--;
      pos.push_back(l[t][i]);
      pos.push_back(r[t][i]);
    }
  }

  pos.push_back(0);
  pos.push_back(k-1);
  pos.push_back(k);
  pos.push_back(k+1);
  sort(pos.begin(), pos.end());
  pos.resize( unique(pos.begin(),pos.end())-pos.begin() );

  /*pos.clear();
  for (int i = 0; i <= k+1; i++)
  pos.push_back(i);*/
  int m = pos.size();

  auto find = [&](int v) {
    int i = lower_bound(pos.begin(), pos.end(), v) - pos.begin();
    assert(pos[i] == v);
    return i;
  };
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < m; i++)
      reach[i][t] = -1;
    for (int i = 0; i < n[t]; i++) {
      int&ref = reach[find(r[t][i])][t];
      ref = max(ref, find(l[t][i]));
    }
  }

  int subi[2] = {-1,-1};
  ll sum = 1;
  for (int i = 0; i+1 < m; i++) {
    ll sub[2];
    for (int t = 0; t < 2; t++) {
      subi[t] = max(subi[t], reach[i][t]);
      sub[t] = subi[t] > -1 ? dp[subi[t]][!t] : 0;
    }
    for (int t = 0; t < 2; t++) {
      dp[i][t] = (sum-sub[t])%mod;
    }
    int d = pos[i+1]-pos[i];
    ll subs = sub[0]+sub[1];
    sum = (bin_pow(2,d)*(sum-subs)+subs) % mod;
    //cout << dp[i][0] << ' ' << dp[i][1] << ' ' << pos[i] << endl;
  }

  ll ans = 0;
  for (int t = 0; t < 2; t++) {
    ans += dp[m-2][t]-dp[m-3][t];
  }
  cout << (ans%mod+mod)%mod << endl;
}
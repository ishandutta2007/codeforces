#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segTree {
  vector<ll> ma;
  int n;
  segTree(int n_) {
    n = 1;
    while (n < n_+10) n *= 2;
    ma.assign(n*2, -1e18);
  }
  ll queryMax(int a, int b, int l, int r, int i) {
    if (a <= l && b >= r) {
      return ma[i];
    } else if (a >= r || b <= l) return -1e18;
    int m = (l+r)/2;
    return max(queryMax(a,b,l,m,i*2), queryMax(a,b,m,r,i*2+1));
  }
  ll queryMax(int a, int b) {
    assert(a >= 0 && a <= n);
    assert(b >= 0 && b <= n);
    return queryMax(a, b, 0, n, 1);
  }
  void update(int a, ll v, int l, int r, int i) {
    if (a == l && r == a+1) {
      ma[i] = max(ma[i], v);
    } else if (a >= r || a+1 <= l) return;
    else {
      int m = (l+r)/2;
      update(a,v,l,m,i*2);
      update(a,v,m,r,i*2+1);
      ma[i] = max(ma[i*2], ma[i*2+1]);
    }
  }
  void update(int p, ll v) {
    assert(p >= 0 && p < n);
    update(p, v, 0, n, 1);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll&v : a) cin >> v;
    vector<ll> acc(n+1);
    for (int i = 0; i < n; i++)
      acc[i+1] = acc[i]+a[i];

    map<ll,int> comp;
    for (int i = 0; i <= n; i++) comp[acc[i]];

    int m = 0;
    for (auto&[x,y] : comp) y = m++;
    segTree tree(m);

    vector<ll> dp(n+1, -1e18);
    dp[0] = 0;

    tree.update(comp[0], 0);

    for (int i = 1; i <= n; i++) {
      int ai = comp[acc[i]];
      ll val = tree.queryMax(0,ai);
      dp[i] = max(dp[i], i+val);

      if (a[i-1] < 0) {
        dp[i] = max(dp[i], dp[i-1]-1);
      } else if (a[i-1] == 0) {
        dp[i] = max(dp[i], dp[i-1]);
      }
      tree.update(ai, dp[i]-i);
    }
    cout << dp[n] << endl;
  }
}
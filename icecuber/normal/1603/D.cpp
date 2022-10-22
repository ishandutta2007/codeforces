#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5+10, kax = 20;
ll dp[kax][nax];
int phi[nax];

int c(int l, int r) {
  int ans = 0;
  /*for (int i = l; i < r; i++) {
    for (int j = l; j <= i; j++) {
      if (gcd(i,j) >= l) ans++;
    }
  }*/
  for (int i = l; i < r; i++) {
    for (int k = 1; i*k < r; k++) {
      ans += phi[k];
    }
  }
  return ans;
}

struct bruteTree {
  vector<ll> data;
  bruteTree(int n) {
    data.resize(n);
  }
  void add(int r, ll v) {
    for (int i = 0; i < r; i++) data[i] += v;
  }
  ll min(int r) {
    ll ret = 1e18;
    for (int i = 0; i < r; i++) ret = ::min(ret, data[i]);
    return ret;
  }
};

struct segTree {
  vector<ll> off, mi;
  int n;
  segTree(int n_) {
    n = 1;
    while (n <= n_) n *= 2;
    off.resize(n*2);
    mi.resize(n*2);
  }
  void add(int r, ll v) {
    for (int i = r+n; i > 1; i >>= 1) {
      if (i&1) off[i-1] += v;
      mi[i>>1] = ::min(mi[i]+off[i],mi[i^1]+off[i^1]);
    }
  }
  ll min(int r) {
    ll ret = 1e18;
    for (int i = r+n; i > 1; i >>= 1) {
      if (i&1) ret = ::min(ret, mi[i-1]+off[i-1]);
      ret += off[i>>1];
    }
    return ret;
  }
  ll operator[](int i) {
    i += n;
    ll ret = 0;
    while (i) {
      ret += off[i];
      i >>= 1;
    }
    return ret;
  }
};

int main() {
  /*segTree tree(10);
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
  tree.add(1, 1);
  for (int i = 0; i < 10; i++) cout << tree[i] << ' ';
  cout << endl;
  return 0;*/

  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 1; i < nax; i++) phi[i] = i;
  for (int i = 2; i < nax; i++) {
    if (phi[i] != i) continue;
    for (int j = i; j < nax; j += i) phi[j] -= phi[j]/i;
  }

  /*for (int l = 1; l < 100; l++)
    for (int r = l; r < 100; r++)
      assert(!c(l,r));
  exit(0);*/
  vector<vector<array<int,2>>> inv(nax);
  for (int l = 1; l < nax; l++) {
    for (int k = 1; k*l+1 < nax; k++) {
      inv[k*l+1].push_back({l,phi[k]});
    }
  }
  for (int i = 2; i < nax; i++) dp[0][i] = 1e11;

  for (int k = 1; k < kax; k++) { 
    /*for (int r = 1; r < nax; r++) {
      dp[k][r] = 1e11;
      for (int l = 1; l < r; l++) {
        dp[k][r] = min(dp[k][r], dp[k-1][l]+c(l,r)); 
      }
      //cout << k << ' ' << r << ": " << dp[k][r] << endl;
    }
    continue;*/
    //bruteTree tree(nax+1);
    segTree tree(nax+1);
    for (int i = 1; i < nax; i++) {
      tree.add(i+1, dp[k-1][i]);
      tree.add(i, -dp[k-1][i]);
      for (auto [l,c] : inv[i])
        tree.add(l+1,c);
      dp[k][i] = min(tree.min(i), ll(1e11));
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    k = min(k, kax-1);
    cout << dp[k][n+1] << endl;
  }
}
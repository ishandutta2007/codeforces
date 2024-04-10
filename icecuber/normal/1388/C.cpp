#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TestCase {
  vector<vector<int>> node;
  vector<ll> here, h, psum;
  int ok;
  TestCase() {
    int n, m;
    cin >> n >> m;
    node.resize(n);
    here.resize(n);
    psum.resize(n);
    h.resize(n);
    for (ll&v : here) cin >> v;
    for (ll&v : h) cin >> v;
    ok = 1;
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      assert(a >= 0 && b >= 0 && a < n && b < n);
      node[a].push_back(b);
      node[b].push_back(a);
    }
    dfs(0, -1);
    cout << (ok ? "YES" : "NO") << endl;
  }
  void dfs(int p, int par) {
    psum[p] = here[p];
    ll minhappy = 0;
    for (int i : node[p]) {
      if (i == par) continue;
      dfs(i, p);
      minhappy += (h[i]+psum[i])/2;
      psum[p] += psum[i];
    }
    ll happy = (h[p]+psum[p])/2;
    if ((h[p]+psum[p])%2 || happy < minhappy || happy < 0 || happy > psum[p]) ok = 0;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) TestCase tc;
}
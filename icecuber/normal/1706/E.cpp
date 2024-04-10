#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> par(n);
    vector<set<int>> s(n);
    for (int i = 0; i < n; i++) {
      par[i] = i;
      s[i] = {i};
    }
    auto find = [&](int p) {
      while (p != par[p]) p = par[p];
      return p;
    };
    const int lods = 20;
    vector<vector<int>> sparse(lods, vector<int>(n-1));
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      a = find(a);
      b = find(b);
      if (a == b) continue;
      if (s[a].size() < s[b].size()) swap(a,b);
      for (int p : s[b]) {
        if (s[a].count(p-1)) sparse[0][p-1] = i+1;
        if (s[a].count(p+1)) sparse[0][p] = i+1;
      }
      for (int p : s[b]) {
        s[a].insert(p);
      }
      par[b] = a;
    }
    for (int l = 0; l+1 < lods; l++) {
      for (int i = 0; i+(2<<l) < n; i++) {
        sparse[l+1][i] = max(sparse[l][i], sparse[l][i+(1<<l)]);
      }
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      if (l == r) {
        cout << 0 << ' ';
        continue;
      }
      int lod = 0;
      while (2<<lod <= r-l) lod++;
      cout << max(sparse[lod][l], sparse[lod][r-(1<<lod)]) << ' ';
    }
    cout << endl;
  }
}
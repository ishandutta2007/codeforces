#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), p(n);
    map<ll,ll> inc;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> p[i];
      inc[x[i]-p[i]] += 1;
      inc[x[i]     ] -= 2;
      inc[x[i]+p[i]] += 1;
    }
    map<ll,int> ind;
    vector<ll> y;
    for (auto [x,c] : inc) {
      ind[x] = y.size();
      y.push_back(x);
    }
    int k = y.size();

    const int lods = 12;
    vector<vector<array<ll,3>>> sparse(lods, vector<array<ll,3>>(k));
    ll acc = 0, dacc = 0, prv = 0;
    for (auto [x,c] : inc) {
      acc += (x-prv)*dacc;
      sparse[0][ind[x]] = {acc, acc-x, acc+x};
      dacc += c;
      prv = x;
    }
    for (int l = 0; l+1 < lods; l++) {
      for (int i = 0; i+(2<<l) <= k; i++) {
        for (int j = 0; j < 3; j++) {
          sparse[l+1][i][j] = max(sparse[l][i][j], sparse[l][i+(1<<l)][j]);
        }
      }
    }
    auto query = [&](int l, int r, int j) {
      assert(l >= 0 && r <= k && l <= r);
      if (l == r) return ll(-1e18);
      int lod = 0;
      while (2<<lod <= r-l && lod < lods-1) lod++;
      if (lod == lods-1) {
        ll ret = sparse[lod][r-(1<<lod)][j];
        for (int i = l; i+(1<<lod) <= r; i += (1<<lod)) {
          ret = max(ret, sparse[lod][i][j]);
        }
        return ret;
      }
      return max(sparse[lod][l][j], sparse[lod][r-(1<<lod)][j]);
    };
    for (int i = 0; i < n; i++) {
      ll ax = x[i]-p[i], bx = x[i], cx = x[i]+p[i];
      int a = ind[ax];
      int b = ind[bx];
      int c = ind[cx];
      cout << (max({query(0,a,0), query(a,b,1)+ax, query(b,c,2)-cx, query(c,k,0)}) <= m);
    }
    cout << endl;
  }
}
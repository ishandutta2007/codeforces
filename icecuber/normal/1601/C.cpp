#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segTree {
  int n;
  vector<int> mi, off;
  segTree(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    mi.resize(n*2);
    off.resize(n*2);
  }
  void add(int r, int v) {
    assert(r >= 0 && r < n);
    for (int i = r+n; i > 1; i >>= 1) {
      if (i&1) {
        off[i-1] += v;
      }
      mi[i>>1] = min(mi[i]+off[i], mi[i^1]+off[i^1]);
    }
  }
  void add(int l, int r, int v) {
    //cout << "add " << l << ' ' << r << ' ' << v << endl;
    add(r, v);
    add(l, -v);
  }
  int operator[](int p) {
    int r = 0;
    for (int i = p+n; i; i >>= 1) r += off[i];
    return r;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<array<int,2>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0];
      a[i][1] = i;
    }
    sort(a.begin(), a.end());

    vector<int> b(m);
    for (int&v : b) cin >> v;
    sort(b.begin(), b.end());

    segTree tree(n+10);

    tree.add(0, n+1, -1e8);
    ll ans = 0;
    //cout << "A " << a.size() << endl;
    for (auto [v,i] : a) {
      tree.add(i+1, n+1, 1);
    }
    int l = -1, r = 0;
    for (int v : b) {
      while (l+1 < n && a[l+1][0] < v) {
        tree.add(0, a[l+1][1]+1, 1);
        l++;
      }
      while (r < n && a[r][0] <= v) {
        tree.add(a[r][1]+1, n+1, -1);
        r++;
      }
      /*cout << tree.mi[1] << endl;
      for (int i = 0; i <= n; i++) cout << tree[i]+1e8 << ' ';
      cout << endl;*/
      ans += tree.mi[1]+1e8;
    }

    segTree tree2(n+10);
    for (auto [v,i] : a) {
      tree2.add(i, 1);
      ans += tree2[i];
    }

    cout << ans << endl;
  }
}
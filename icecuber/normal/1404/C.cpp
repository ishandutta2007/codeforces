#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fentree {
  vector<int> data;
  int n;
  Fentree(int n_) {
    n = n_;
    data.resize(n);
  }
  void add(int i, int v) {
    for (i += 5; i < n; i += i&-i) data[i] += v;
  }
  int sum(int i) {
    int r = 0;
    for (i += 5; i; i -= i&-i) r += data[i];
    return r;
  }
};

struct Segtree {
  vector<ll> mi, off;
  int n;
  Segtree(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    mi.resize(n*2);
    off.resize(n*2);
  }
  void add(int r, int v) {
    for (int i = r+n; i > 1; i >>= 1) {
      if (i&1) {
	off[i-1] += v;
      }
      mi[i>>1] = min(mi[i]+off[i], mi[i^1]+off[i^1]);
    }
  }
  void add(int l, int r, int v) {
    add(r, v);
    add(l,-v);
  }
  pair<int,int> findRMin() {
    int i = 1;
    ll acc = 0;
    while (i < n) {
      if (mi[i*2+1]+off[i*2+1] == mi[i]) i = i*2+1;
      else i = i*2;
      acc += off[i];
    }
    return {i-n,acc};
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  const int off = 1e7;

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = i+1-a[i];
    if (a[i] < 0) a[i] = off;
  }
  vector<vector<array<int,2>>> query(n);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    query[x].push_back({y,i});
  }


  Segtree tree(n+10);
  for (int i = 0; i < n; i++)
    tree.add(i,i+1,a[i]);
  Fentree ftree(n+10);

  vector<int> ans(q);
  for (int i = n-1; i >= 0; i--) {
    tree.add(i,i+1, -off);
    //cout << i << endl;
    while (1) {
      auto [p,v] = tree.findRMin();
      if (v > -off) break;
      //cout << p << ' ' << v << endl;
      assert(v == -off);
      //cout << p << ' ';
      ftree.add(p,1);
      tree.add(p,p+1, off);
      tree.add(p,n,-1);
    }
    //cout << endl;
    for (auto [y,qi] : query[i]) {
      ans[qi] = ftree.sum(n-y-1);
    }
  }
  for (int v : ans) cout << v << '\n';
}
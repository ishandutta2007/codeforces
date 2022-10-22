#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(array<ll,2> a, array<ll,2> b) {
  return a[0]*b[1] < b[0]*a[1];
}

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
  int T;
  cin >> T;
  while (T--) {
    int N, m;
    cin >> N >> m;
    vector<array<ll,2>> a(N);
    for (auto&[v,c] : a) cin >> v, c = 1;
    sort(a.rbegin(), a.rend());
    a.resize(m);
    reverse(a.begin(), a.end());

    vector<array<ll,2>> group(m), student;
    for (int i = 0; i < m; i++) {
      int k;
      cin >> k;
      group[i][1] = k;
      while (k--) {
        ll b;
        cin >> b;
        group[i][0] += b;
        student.push_back({i, b});
      }
    }

    //vector<int> data(n);
    Segtree tree(m+10);
    auto add = [&](int j, int v) {
      tree.add(j+1, -v);
      //for (int i = 0; i < j; i++) data[i] += v;
    };
    auto OK = [&]() {
      return tree.mi[1] >= 0;
      /*int ok = 1;
      for (int i = 0; i < m; i++) 
        ok &= (data[i] <= 0);
      return ok;*/
    };

    for (int i = 1; i <= m; i++) add(i-1,-1);
    for (int i = 0; i < m; i++) {
      int j = lower_bound(a.begin(), a.end(), group[i], comp)-a.begin();
      add(j,1);
    }

    string ans;
    for (auto [i,b] : student) {
      int j0 = lower_bound(a.begin(), a.end(), group[i], comp)-a.begin();
      add(j0,-1);

      array<ll,2> ngroup = {group[i][0]-b, group[i][1]-1};
      int j1 = lower_bound(a.begin(), a.end(), ngroup, comp)-a.begin();
      add(j1,1);

      ans += '0'+OK();
      add(j0,1);
      add(j1,-1);
    }
    cout << ans << endl;
  }
}
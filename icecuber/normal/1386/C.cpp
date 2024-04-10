#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<pair<int,int>> edges;

struct Undo {
  int pa, pb, isgood;
  char type;
};

struct Union {
  int li, ri;
  int isgood;
  vector<int> par, sz, diff;
  vector<Undo> history;

  void l() {
    auto [a,b] = edges[min(li++,(int)edges.size()-1)];
    join(a,b);
    history.back().type = 'L';
  }
  void r() {
    auto [a,b] = edges[max(ri--,0)];
    join(a,b);
    history.back().type = 'R';
  }

  Union(int n, int m) {
    li = 0, ri = m-1;
    isgood = 1;
    par.resize(n), sz.resize(n), diff.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i, sz[i] = 1, diff[i] = 0;
    }
  }
  pair<int,int> find(int p) {
    if (p == par[p]) return {p, 0};
    auto [pa, c] = find(par[p]);
    return {pa, c^diff[p]};
  }
  void join(int a, int b) {
    auto [pa, ca] = find(a);
    auto [pb, cb] = find(b);
    if (sz[pa] < sz[pb]) swap(pa,pb),swap(ca,cb);
    history.push_back({pa, pb, isgood, '?'});
    if (pa == pb && ca == cb) isgood = 0;
    if (pa != pb) {
      par[pb] = pa;
      diff[pb] = (ca == cb);
      sz[pa] += sz[pb];
    }
  }
  void undo() {
    assert(history.size());
    Undo u = history.back();
    history.pop_back();
    if (u.pa != u.pb) {
      par[u.pb] = u.pb;
      sz[u.pa] -= sz[u.pb];
    }
    isgood = u.isgood;
    if (u.type == 'L') li--;
    else if (u.type == 'R') ri++;
    else assert(0);
  }
  int good() {
    return isgood && ri-li >= -1;
  }
};


int reach[nax];
void f(Union&u, int l, int r, int base = 0) {
  if (l == r) return;
  int m = (r-l)/2;
  for (int i = 0; i < m; i++) u.r();
  int y = 0;
  while (u.good()) u.l(), y++;
  reach[l+m] = base+y;
  for (int i = 0; i < y; i++)
    u.undo();
  u.r();
  f(u, l+m+1, r, base);
  for (int i = 0; i < m+1; i++)
    u.undo();
  for (int i = 0; i < y; i++)
    u.l();
  f(u, l, l+m, base+y);
  for (int i = 0; i < y; i++)
    u.undo();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  edges.resize(m);
  for (auto&[a,b] : edges) {
    cin >> a >> b;
    a--, b--;
  }

  {
    Union u(n, m);
    f(u, 0, m);
    assert(u.history.empty());
  }

  /*{
    for (int i = 0; i < m; i++) {
      Union u(n, m);
      int y = 0;
      for (int j = 0; j < i; j++) u.r();
      while (u.good()) u.l(), y++;
      cout << y << ' ';
    }
    cout << endl;
    return 0;
  }
  for (int i = 0; i < m; i++)
    cout << reach[i] << ' ';
  cout << endl;
  return 0;
  */
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    cout << (!(reach[m-r] > l) ? "YES" : "NO") << endl;

    /*Union u(n, m);
    for (int i = 0; i < m-r; i++) u.r();
    for (int i = 0; i < l; i++) u.l();
    assert(u.good() == (reach[m-r] > l));*/
  }
}
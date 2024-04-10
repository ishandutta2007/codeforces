#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

const int n = 1<<19;

ll par[n*2], szx[n*2], szy[n*2];

int find(int x) {
  int p = par[x];
  if (p == par[p]) return p;
  else return find(par[p]);
}

ll ans = 0;
struct Event {
  pair<int,int> p;
  int pa, pb;
  ll ans0;
  void run() {
    ans0 = ans;
    pa = find(p.x), pb = find(p.y+n);
    if (pa == pb) return;
    ans -= szx[pa]*szy[pa];
    ans -= szx[pb]*szy[pb];
    if (szx[pa]+szy[pa] < szx[pb]+szy[pb]) swap(pa,pb);
    par[pb] = pa;
    szx[pa] += szx[pb];
    szy[pa] += szy[pb];
    ans += szx[pa]*szy[pa];
  }
  void undo() {
    if (pa == pb) return;
    ans -= szx[pa]*szy[pa];
    par[pb] = pb;
    szx[pa] -= szx[pb];
    szy[pa] -= szy[pb];
    ans += szx[pa]*szy[pa];
    ans += szx[pb]*szy[pb];
    assert(ans == ans0);
  }
};

vector<Event> tree[n*2];
void add(pair<int,int> p, int a, int b, int l = 0, int r = n, int i = 1) {
  if (l >= b || r <= a) return;
  if (l >= a && r <= b) {
    tree[i].push_back({p});
    return;
  }
  int mid = l+r>>1;
  add(p, a, b, l, mid, i*2);
  add(p, a, b, mid, r, i*2+1);
}

int q;
void calc(int i) {
  for (Event&e : tree[i])
    e.run();
  if (i >= n && i < q+n)
    cout << ans << ' ';
  if (i < n) {
    calc(i*2);
    calc(i*2+1);
  }
  reverse(tree[i].begin(), tree[i].end());
  for (Event&e : tree[i])
    e.undo();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < n*2; i++) par[i] = i, szx[i] = i<n, szy[i] = i>=n;

  cin >> q;
  map<pair<int,int>, int> m;
  for (int i = 0; i < q; i++) {
    pair<int,int> p;
    cin >> p.x >> p.y;
    if (!m.count(p)) m[p] = i;
    else {
      add(p, m[p], i);
      m.erase(p);
    }
  }
  for (auto p : m)
    add(p.first, p.second, q);
  calc(1);
  cout << endl;
}
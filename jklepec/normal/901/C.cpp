#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 3e5 + 5, off = 1 << 19;

int par[MAXN];
bool bio[MAXN];
bool visited[MAXN];

vector<int> e[MAXN];
vector<point> vek;

int n, m;
vector<int> dude[MAXN];

void dfs(int u, int v) {
  par[v] = u;
  if(bio[v]) {
    if(visited[v]) return;
    point p = {v, v};
    int V = v;

    V = par[V];
    visited[v] = true;

    while(V != v) {

      visited[V] = true;

      p.first = min(p.first, V);
      p.second = max(p.second, V);

      V = par[V];
    }
    dude[p.second].push_back(p.first);
    return;
  }

  bio[v] = true;

  for(auto w: e[v]) {
    if(w != u)
    dfs(v, w);
  }
}

ll T[2 * off], P[2 * off];
void prop(int x, int range) {
  if(P[x] != 0) {
    T[x] += P[x] * range;
    if(x < off) {
      P[x * 2] += P[x];
      P[x * 2 + 1] += P[x];
    }
    P[x] = 0;
  }
}

ll get(int x, int a, int b, int lo, int hi) {
  prop(x, hi - lo);
  if(lo >= a && hi <= b)
    return T[x];
  if(lo >= b || hi <= a)
    return 0;

  int mid = (lo + hi) >> 1;
  return get(x * 2, a, b, lo, mid) + get(x * 2 + 1, a, b, mid, hi);
}

void upd(int x, int a, int b, int lo, int hi) {
  prop(x, hi - lo);
  if(lo >= a && hi <= b) {
    P[x] ++;
    prop(x, hi - lo);
    return;
  }
  if(lo >= b || hi <= a)
    return;

  int mid = (lo + hi) >> 1;
  upd(x * 2, a, b, lo, mid);
  upd(x * 2 + 1, a, b, mid, hi);

  T[x] = T[x * 2] + T[x * 2 + 1];
}

vector<point> queries[MAXN];

ll sol[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;

  REP(i, m) {
    int x, y; cin >> x >> y;
    x --; y --;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  REP(i, n) {
    if(!bio[i])
    dfs(i, i);
  }
  int q; cin >> q;
  REP(i, q) {
    int x, y; cin >> x >> y;
    queries[y - 1].push_back({x - 1, i});
  }

  int mx = -1;

  REP(i, n) {
    for(auto x: dude[i])
      mx = max(mx, x);
    upd(1, mx + 1, i + 1, 0, off);
    for(auto p: queries[i]) {
      sol[p.second] = get(1, p.first, i + 1, 0, off);
    }
  }

  REP(i, q)
    cout << sol[i] << "\n";
}
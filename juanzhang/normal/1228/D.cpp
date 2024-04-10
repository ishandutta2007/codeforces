#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 3e5 + 10;
int n, m;

vector <int> e[maxn];

typedef pair <int, int> pii;
const int P1 = 1e9 + 7, P2 = 1e9 + 9;
int base;

struct Hash {
  int v1, v2;

  Hash() {}
  Hash(int x, int y) : v1(x), v2(y) {}

  void print() {
    printf("#(%d %d)\n", v1, v2);
  }

  void get(Hash &o, int x) {
    v1 = (1ll * o.v1 * base + x) % P1;
    v2 = (1ll * o.v2 * base + x) % P2;
  }
  
  bool operator < (const Hash &o) const {
    return v1 < o.v1 || (v1 == o.v1 && v2 < o.v2);
  }

  bool operator == (const Hash &o) const {
    return v1 == o.v1 && v2 == o.v2;
  }
};

#define iter map <Hash, vector <int> > :: iterator

map <Hash, vector <int> > M;

int tot, par[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  if ((x = find(x)) != ((y = find(y)))) {
    tot++, par[x] = y;
  }
}

int main() {
  base = rnd();
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    unite(u, v);
    e[u].push_back(v), e[v].push_back(u);
  }
  if (tot != n - 1) {
    return puts("-1"), 0;
  }
  for (int i = 1; i <= n; i++) {
    sort(e[i].begin(), e[i].end());
    Hash h(0, 0);
    for (int v : e[i]) {
      h.get(h, v);
    }
    M[h].push_back(i);
  }
  if (M.size() != 3) {
    return puts("-1"), 0;
  }
  int now = 0;
  static int ans[maxn];
  for (iter it = M.begin(); it != M.end(); ++it) {
    now++;
    vector <int> &vec = it -> second;
    for (int x : vec) {
      ans[x] = now;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
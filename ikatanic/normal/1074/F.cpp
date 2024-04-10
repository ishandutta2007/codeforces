#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1 << 18;
const int inf = 1e9;

const int offset = 1 << 18;

struct Tournament {
  int T[2 * MAXN];
  int S[2 * MAXN];
  int K[2 * MAXN];

  void init() {
    for (int i = 0; i < 2 * offset; ++i) T[i] = 0, S[i] = 0;
    for (int  i = offset; i < 2*offset; ++i) K[i] = 1;
    for (int i = offset - 1; i > 0; --i) {
      K[i] = K[i*2] + K[i*2+1];
    }
  }

  void propagate(int i) {
    int l = i * 2, r = l + 1;
    if (S[i]) {
      S[l] += S[i], S[r] += S[i];
      T[l] += S[i], T[r] += S[i];
      S[i] = 0;
    }
  }

  void merge(int i) {
    int l = i * 2, r = l + 1;
    if (T[l] > T[r])
      T[i] = T[l] + S[i], K[i] = K[l];
    else if (T[r] > T[l])
      T[i] = T[r] + S[i], K[i] = K[r];
      else {
        T[i] = T[l] + S[i], K[i] = K[l] + K[r];
      }
  }

  void add(int i, int lo, int hi, int a, int b, int k) {
    if (lo >= b || hi <= a) return;
    if (lo >= a && hi <= b) {
      S[i] += k;
      T[i] += k;
      return;
    }
    propagate(i);

    add(i * 2, lo, (lo + hi) / 2, a, b, k);
    add(i * 2 + 1, (lo + hi) / 2, hi, a, b, k);

    merge(i);
  }

  pair<int, int> get(int i, int lo, int hi, int a, int b) {
    if (lo >= b || hi <= a) return make_pair(-inf, 0);
    if (lo >= a && hi <= b) return make_pair(T[i], K[i]);
    propagate(i);

    auto l = get(i * 2, lo, (lo + hi) / 2, a, b);
    auto r = get(i * 2 + 1, (lo + hi) / 2, hi, a, b);
    if (l.first == r.first) return {l.first, l.second + r.second};
    return max(l, r);
  }

  void add(int a, int b, int k) { add(1, 0, offset, a, b, k); }

  pair<int, int> getmax(int a, int b) { return get(1, 0, offset, a, b); }
} T;

vector<int> E[MAXN];

int dad[MAXN];
int st[MAXN], fin[MAXN];
int tick;

set<pair<int, int>> extra;

const int MAX = MAXN;
const int LG = 19;

int L[MAX][LG];
int parent[MAX], depth[MAX];

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int j = LG - 1; j >= 0; --j)
    if (depth[u] - (1 << j) >= depth[v]) u = L[u][j];
  if (u == v) return u;
  for (int j = LG - 1; j >= 0; --j)
    if (L[u][j] != L[v][j]) u = L[u][j], v = L[v][j];
  return L[u][0];
}

int climb(int x, int depth) {
  for (int j = 0; j < LG; ++j)
  if (depth & (1 << j)) x = L[x][j];
  return x;
}


void update(int u, int v) {
  int k = -1;
  pair<int, int> p = {u, v};
  if (extra.count(p)) {
    k = -1;
    extra.erase(p);
  } else {
    k = +1;
    extra.insert(p);
  }

  int c = lca(u, v);

  if (c != u && c != v) {
    T.add(st[u], fin[u], k);
    T.add(st[v], fin[v], k);
  } else {
    if (c == v) swap(u, v);

    int w = climb(v, depth[v] - depth[u] - 1);

    T.add(st[0], fin[0], k);
    T.add(st[w], fin[w], -k);
    T.add(st[v], fin[v], k);
  }
}

void dfs(int x, int d) {
  st[x] = tick++;
  parent[x] = d;
  for (int y : E[x]) {
    if (y != d) {
      depth[y] = depth[x] + 1;
      dfs(y, x);
    }
  }
  fin[x] = tick;
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int N, Q;
  cin >> N >> Q;

  T.init();

  for (int i = 0; i < N - 1; ++i) {
    int A, B;
    cin >> A >> B;
    --A, --B;

    E[A].push_back(B);
    E[B].push_back(A);
  }

  dfs(0, 0);

  for (int i = 0; i < N; ++i) L[i][0] = parent[i];
  for (int j = 1; j < LG; ++j)
    for (int i = 0; i < N; ++i) L[i][j] = L[L[i][j - 1]][j - 1];

  while (Q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    if (u > v) swap(u, v);

    update(u, v);

    pair<int, int> q = T.getmax(st[0], fin[0]);

    int ret = q.first == (int)extra.size() ? q.second : 0;
    cout << ret << "\n";
  }
  return 0;
}
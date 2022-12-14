#include <bits/stdc++.h>
using namespace std;

inline int getint() {
  static char c;
  while ((c = getchar()) < '0' || c > '9');

  int res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') {
    res = res * 10 + c - '0';
  }
  return res;
}

const int MaxN = 1000000;
const int MaxM = MaxN - 1;
const int INF = 0x3f3f3f3f;

int n, q;

struct halfEdge {
  int v;
  halfEdge *next;
};
halfEdge adj_pool[MaxM * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN + 1];

inline void addEdge(const int &u, const int &v) {
  adj_tail->v = v, adj_tail->next = adj[u];
  adj[u] = adj_tail++;
}

int global = INF;
int init[MaxN + 1];

int fa[MaxN + 1];

void dfs(const int &u) {
  for (halfEdge *e = adj[u]; e; e = e->next) {
    if (e->v != fa[u]) {
      fa[e->v] = u;
      init[e->v] = min(init[u], e->v);
      dfs(e->v);
    }
  }
}

bool book[MaxN + 1];

inline void update_global(const int &u) {
  global = min(global, u);
}

inline void update(int u) {
  for (int v = u; !book[v]; v = fa[v]) {
    update_global(v);
  }
  book[u] = true;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    int u = getint(), v = getint();
    addEdge(u, v);
    addEdge(v, u);
  }

  int last = 0;
  while (q--) {
    int t = getint();
    int u = (getint() + last) % n + 1;

    if (t == 2) {
      printf("%d\n", last = min(global, init[u]));
    } else {
      if (!init[1]) {
        init[u] = u;
        dfs(u);
        book[u] = true;
      } else {
        update(u);
      }
    }
  }

  return 0;
}
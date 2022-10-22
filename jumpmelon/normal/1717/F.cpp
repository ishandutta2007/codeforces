#include <bits/stdc++.h>

using namespace std;

template <typename CapT = int>
class NetworkFlow {
private:
  int vc, vs, vt, *Head;
  struct edge {
    int v, next; 
    CapT f;
  };
  std::vector<edge> E;

  int *Cur, *Dep;

  bool BFS();
  CapT DFS(int u, CapT inf);

public:
  NetworkFlow(int vc_, int vs_, int vt_);
  ~NetworkFlow();
  int addEdge(int u, int v, CapT f);
  CapT maxFlow();
  CapT getFlow(int p) const;
};

template <typename CapT>
NetworkFlow<CapT>::NetworkFlow(int vc_, int vs_, int vt_) : vc(vc_), vs(vs_), vt(vt_) {
  Head = new int[vc];
  memset(Head, -1, sizeof(int[vc]));
}

template <typename CapT>
NetworkFlow<CapT>::~NetworkFlow() {
  delete[] Head;
}

template <typename CapT>
bool NetworkFlow<CapT>::BFS() {
  queue<int> Q;
  memset(Dep, -1, sizeof(int[vc]));
  Dep[vt] = 0;
  Q.push(vt);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int p = Head[u]; ~p; p = E[p].next)
      if (E[p ^ 1].f && Dep[E[p].v] == -1) {
        Dep[E[p].v] = Dep[u] + 1;
        Q.push(E[p].v);
      }
  }
  return Dep[vs] != -1;
}

template <typename CapT>
CapT NetworkFlow<CapT>::DFS(int u, CapT inf) {
  if (u == vt)
    return inf;
  int curf = 0;
  for (int &p = Cur[u]; ~p; p = E[p].next)
    if (E[p].f && Dep[u] == Dep[E[p].v] + 1) {
      int f = DFS(E[p].v, min(E[p].f, inf - curf));
      curf += f;
      E[p].f -= f;
      E[p ^ 1].f += f;
      if (curf == inf)
        break;
    }
  return curf;
}

template <typename CapT>
int NetworkFlow<CapT>::addEdge(int u, int v, CapT f) {
  E.push_back({v, Head[u], f});
  Head[u] = (int)E.size() - 1;
  E.push_back({u, Head[v], 0});
  Head[v] = (int)E.size() - 1;
  return (int)E.size() - 2;
}

template <typename CapT>
CapT NetworkFlow<CapT>::maxFlow() {
  CapT tot = 0;
  Cur = new int[vc];
  Dep = new int[vc];
  while (BFS()) {
    memcpy(Cur, Head, sizeof(int[vc]));
    tot += DFS(vs, std::numeric_limits<CapT>::max());
  }
  delete[] Cur;
  delete[] Dep;
  return tot;
}

template <typename CapT>
CapT NetworkFlow<CapT>::getFlow(int p) const {
  return E[p ^ 1].f;
}

void solve() {
  static const int MAXN = 10000, MAXM = 10000;
  static int S[MAXN + 1], A[MAXN + 1];
  static struct { int v, u; } L[MAXM];

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &S[i]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &A[i]);
  for (int i = 0; i < m; i++)
    scanf("%d%d", &L[i].v, &L[i].u);
  
  static int Pr[MAXN + 1];
  for (int i = 0; i < m; i++) {
    Pr[L[i].v]++;
    Pr[L[i].u]--;
  }

  static int ENum[MAXM];
  int vc = n + 4, vs = 0, vt = n + 1, s0 = n + 2, t0 = n + 3;
  NetworkFlow<int> *g = new NetworkFlow<int>(vc, vs, vt);
  
  int tot = 0;
  g->addEdge(t0, s0, INT_MAX);

  for (int i = 1; i <= n; i++) {
    g->addEdge(vs, i, m);
    g->addEdge(s0, vt, m);
    tot += m;
    if (S[i]) {
      if ((A[i] - Pr[i]) % 2 != 0) {
        puts("NO");
        return;
      }
      int f = m + (A[i] - Pr[i]) / 2;
      g->addEdge(i, vt, f);
      g->addEdge(vs, t0, f);
      tot += f;
    } else {
      g->addEdge(i, t0, INT_MAX);
    }
  }

  for (int i = 0; i < m; i++)
    ENum[i] = g->addEdge(L[i].v, L[i].u, 1);

  if (g->maxFlow() != tot) {
    puts("NO");
    return;
  }

  puts("YES");
  for (int i = 0; i < m; i++) {
    if (g->getFlow(ENum[i]))
      printf("%d %d\n", L[i].v, L[i].u);
    else
      printf("%d %d\n", L[i].u, L[i].v);
  }

  delete g;
}

int main() {
  solve();
  return 0;
}
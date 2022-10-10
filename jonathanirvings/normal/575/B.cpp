#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

const int N = 1e5 + 6;

const int K = 1e6 + 5;

const int MOD = (int)1e9 + 7;

int two[K];

struct BIT {
  vector<int> tree;
  BIT(int n) : tree(n + 1, 0) {} 

  void internalUpdate(int x, int val) {
    for (int i = x + 1; i < (int)tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  void update(int l, int r) {
    if (l > r) return;
    internalUpdate(l, 1);
    internalUpdate(r + 1, -1);
  }

  int query(int x) {
    int ret = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
      ret += tree[i];
    }
    return ret;
  }
};

int n;
vector<pii> adj[N];
int head[N];
int pathIndex[N];
int pathID[N];
int pathSize[N];
int size[N];
int par[N];
int depth[N];
int pathCounter = 0;
BIT *tree[N];
BIT *tree2[N];

inline void dfs(int u, int parent) {
  par[u] = parent;
  size[u] = 1;
  for (auto it : adj[u]) {
    if (it.first != parent) {
      depth[it.first] = depth[u] + 1;
      dfs(it.first, u);
      size[u] += size[it.first];
    }
  }
}

inline void hld(int u) {
  if (head[u] == -1) {
    head[u] = u;
    pathID[u] = pathCounter++;
    pathIndex[u] = 0;
  }
  pathSize[pathID[u]]++;
  int heavy = -1;
  for (auto it : adj[u]) {
    if (it.first == par[u]) {
      continue;
    }
    if (heavy == -1 || size[it.first] > size[heavy]) {
      heavy = it.first;
    }
  }
  if (heavy != -1) {
    head[heavy] = head[u];
    pathID[heavy] = pathID[u];
    pathIndex[heavy] = pathIndex[u] + 1;
  }
  for (auto it : adj[u]) {
    if (it.first != par[u]) {
      hld(it.first);
    }
  }
}

int findLCA(int u, int v) {
  while (pathID[u] != pathID[v]) {
    if (depth[head[u]] > depth[head[v]]) {
      u = par[head[u]];
    } else {
      v = par[head[v]];
    }
  }
  return depth[u] < depth[v] ? u : v;
}

void init() {
  two[0] = 1;
  for (int i = 1; i < K; i++) {
    two[i] = (two[i - 1] * 2) % MOD;
  }
}

inline void update(int u, int anc) {
  while (pathID[u] != pathID[anc]) {
    tree[pathID[u]]->update(0, pathIndex[u]);
    u = par[head[u]];
  }
  tree[pathID[u]]->update(pathIndex[anc] + 1, pathIndex[u]);
}

inline void update2(int u, int anc) {
  while (pathID[u] != pathID[anc]) {
    tree2[pathID[u]]->update(0, pathIndex[u]);
    u = par[head[u]];
  }
  tree2[pathID[u]]->update(pathIndex[anc] + 1, pathIndex[u]);
}

int main() {
  init();
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, p;
    scanf("%d%d%d", &u, &v, &p);
    u--; v--;
    adj[u].push_back({v, 0});
    adj[v].push_back({u, p});
  }
  dfs(0, -1);
  memset(head, -1, sizeof(head));
  hld(0);
  for (int i = 0; i < n; i++) {
    if (head[i] == i) {
      tree[pathID[i]] = new BIT(pathSize[pathID[i]]);
      tree2[pathID[i]] = new BIT(pathSize[pathID[i]]);
    }
  }
  int k;
  scanf("%d", &k);
  int pos = 0;
  while (k--) {
    int v;
    scanf("%d", &v);
    v--;
    int lca = findLCA(pos, v);
    update2(pos, lca);
    update(v, lca);
    pos = v;
  }
  int ans = 0;
  for (int u = 0; u < n; u++) {
    for (auto it : adj[u]) {
      int v = it.first;
      int p = it.second;
      if (p == 1) {
        if (v == par[u]) {
          int q = tree2[pathID[u]]->query(pathIndex[u]);
          assert(q < K);
          ans += two[q] - 1;
          if (ans >= MOD) ans -= MOD;
        } else {
          int q = tree[pathID[v]]->query(pathIndex[v]);
          assert(q < K);
          ans += two[q] - 1;
          if (ans >= MOD) ans -= MOD;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
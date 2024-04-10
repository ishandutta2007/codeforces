 #include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 1e5 + 10;
int n, q;

int h[maxn];

struct edges {
  int nxt, to, w;
} E[maxn << 1];

void addline(int u, int v, int w) {
  static int cnt = 1;
  E[++cnt] = edges{h[u], v, w}, h[u] = cnt;
}

ll dis[maxn], val[maxn];

void dfs(int u, int f) {
  for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (v != f) {
      dis[v] = dis[u] + E[i].w, dfs(v, u);
    }
  }
}

int getmax(int u) {
  dis[u] = 0, dfs(u, 0);
  int res = u;
  rep(i, 1, n) if (dis[res] < dis[i]) res = i;
  return res;
}

int tid[maxn];
bool vis[maxn];
int par[maxn], sum[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  if ((x = find(x)) != (y = find(y))) {
    if (sum[x] < sum[y]) swap(x, y);
    par[y] = x, sum[x] += sum[y];
  }
}

int main() {
  cin >> n;
  rep(i, 2, n) {
    int u = read(), v = read(), w = read();
    addline(u, v, w), addline(v, u, w);
  }
  int S = getmax(1);
  int T = getmax(S);
  rep(i, 1, n) val[i] = dis[i];
  getmax(T);
  rep(i, 1, n) chkmax(val[i], dis[i]);
  cin >> q;
  rep(i, 1, n) tid[i] = i;
  sort(tid + 1, tid + n + 1, [] (int x, int y) {
    return val[x] > val[y];
  });
  while (q--) {
    ll len;
    cin >> len;
    int res = 0;
    rep(i, 1, n) par[i] = i, sum[i] = 1, vis[i] = 0;
    for (int i = 1, j = 1; i <= n; i++) {
      int u = tid[i], v = tid[j];
      for (int p = h[u]; p; p = E[p].nxt) {
        int v = E[p].to;
        if (vis[v]) unite(u, v);
      }
      while (j < i && val[v] - val[u] > len) {
        sum[find(v)]--, v = tid[++j];
      }
      chkmax(res, sum[find(u)]), vis[u] = 1;
    }
    cout << res << endl;
  }
  return 0;
}
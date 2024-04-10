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
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef pair <int, int> pii;
const int maxn = 4e5 + 10;
int n, m, k, p[maxn];

pii G[maxn];

vector <int> E[maxn];

bool vis[maxn];
int sum[maxn], dis[maxn];

void bfs(int S) {
  memset(dis, 0x3f, sizeof dis);
  dis[S] = 0, sum[S] = 1;
  static int Q[maxn];
  int l = 1, r = 1;
  Q[1] = S;
  while (l <= r) {
    int u = Q[l++];
    for (int v : E[u]) {
      if (dis[v] == dis[u] + 1) {
        sum[v] += sum[u];
        if (sum[v] > 1) sum[v] = 2;
      } else if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1, sum[v] = sum[u], Q[++r] = v;
      }
    }
  }
}

int main(){
  cin >> n >> m;
  rep(i, 1, m) {
    int u = read(), v = read();
    E[v].push_back(u);
    G[i] = {u, v};
  }
  cin >> k;
  rep(i, 1, k) p[i] = read();
  bfs(p[k]);
  memset(sum, 0, sizeof sum);
  rep(i, 1, m) {
    int u = G[i].first, v = G[i].second;
    sum[u] += dis[u] == dis[v] + 1;
  }
  int mn = 0, mx = 0;
  rep(i, 1, k - 1) {
    if (dis[p[i]] == dis[p[i + 1]] + 1) {
      mx += sum[p[i]] > 1;
    } else {
      mx++, mn++;
    }
  }
  printf("%d %d\n", mn, mx);
  return 0;
}
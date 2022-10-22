#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline long long read() {
  #define nc getchar()
  long long x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <ll, int> pii;
const int maxn = 8e5 + 10;
int n, m;

int S;
int h[maxn];
ll dis[maxn];

struct edges {
  int nxt, to; ll w;
} E[maxn];

void addline(int u, int v, ll w) {
  static int cnt = 1;
  E[++cnt] = edges{h[u], v, w}, h[u] = cnt;
}

priority_queue <pii, vector <pii>, greater <pii> > Q;

void dijkstra() {
  memset(dis, 0x3f, sizeof dis);
  dis[S] = 0;
  Q.push(pii(0, S));
  while (!Q.empty()) {
    pii p = Q.top();
    int u = p.second;
    Q.pop();
    if (dis[u] < p.first) continue;
    for (int i = h[u]; i; i = E[i].nxt) {
      int v = E[i].to;
      if (dis[v] > dis[u] + E[i].w) {
        dis[v] = dis[u] + E[i].w, Q.push(pii(dis[v], v));
      }
    }
  }
}

int main() {
  cin >> n >> m;
  rep(i, 1, m) {
    int u = read(), v = read();
    ll w = read();
    addline(u, v, 2 * w);
    addline(v, u, 2 * w);
  }
  S = n + 1;
  rep(i, 1, n) {
    ll x = read();
    addline(S, i, x);
  }
  dijkstra();
  rep(i, 1, n) printf("%I64d ", dis[i]);
  return 0;
}
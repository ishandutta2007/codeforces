#include <bits/stdc++.h>

#define IL __inline__ __attribute__((always_inline))

#define For(i, a, b) for (int i = a, i##end = b; i <= i##end; ++ i)
#define FOR(i, a, b) for (int i = a, i##end = b; i < i##end; ++ i)
#define Rep(i, a, b) for (int i = a, i##end = b; i >= i##end; -- i)
#define REP(i, a, b) for (int i = a - 1, i##end = b; i >= i##end; -- i)

typedef long long LL;

template <class T>
IL bool chkmax(T &a, const T b) {
  return a < b ? ((a = b), 1) : 0;
}

template <class T>
IL bool chkmin(T &a, const T b) {
  return a > b ? ((a = b), 1) : 0;
}

template <class T>
IL T mymax(const T a, const T b) {
  return a > b ? a : b;
}

template <class T>
IL T mymin(const T a, const T b) {
  return a < b ? a : b;
}

template <class T>
IL T myabs(const T &a) {
  return a > 0 ? a : -a;
}

const int INF = 0X3F3F3F3F;
const double EPS = 1E-10, PI = acos(-1.0);

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define OK DEBUG("Passing [%s] in LINE %d...\n", __FUNCTION__, __LINE__)
#define F first
#define S second
/*************************header*************************/

const int MAXN = 500 + 5, MAXM = 5000 + 5;

int d, s;

struct Graph {
  int dist[MAXN][MAXM], pre_edge[MAXN][MAXM], cnt;
  std::pair <int, int> pre_node[MAXN][MAXM];
  bool vis[MAXN][MAXM];
  
  void BFS() {
    static std::pair <int, int> que[MAXN * MAXM];
    memset(dist, 63, sizeof dist);
    int l = 1, r = 0;
    que[++ r] = std::make_pair(0, s);
    vis[0][s] = 1;
    while (l <= r) {
      std::pair <int, int> u = que[l ++];
      For(i, 0, 9) {
        std::pair <int, int> temp = std::make_pair((u.F * 10 + i) % d, u.S - i);
        if (u.S >= i && !vis[temp.F][temp.S]) {
          vis[temp.F][temp.S] = 1;
          pre_node[temp.F][temp.S] = u;
          pre_edge[temp.F][temp.S] = i;
          dist[temp.F][temp.S] = dist[u.F][u.S] + 1;
          que[++ r] = temp;
        }
      }
    }
  }
  
  void print() {
    if (!vis[0][0]) {
      puts("-1");
      return;
    }
    static int stack[MAXM];
    int top = 0;
    std::pair <int, int> cur = std::make_pair(0, 0), end = std::make_pair(0, s);
    while (cur != end) {
      stack[++ top] = pre_edge[cur.F][cur.S];
      cur = pre_node[cur.F][cur.S];
    }
    Rep(i, top, 1)
      printf("%d", stack[i]);
    puts("");
  }
} G;

int main() {
  scanf("%d%d", &d, &s);
  G.BFS();
  G.print();
  return 0;
}
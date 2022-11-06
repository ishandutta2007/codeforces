#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (int i = (a); i >= (b); --i)
#define dbg(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
template <typename T, typename U>
inline bool smax(T& x, const U& y) {
  return y > x ? (x = y, 1) : 0;
}
template <typename T, typename U>
inline bool smin(T& x, const U& y) {
  return y < x ? (x = y, 1) : 0;
}
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define X first
#define Y second
inline int read() {
  int w = 0, p = 0;
  char c;
  while (!isdigit(c = getchar()))
    if (c == '-') p = 1;
  while (isdigit(c)) w = (w << 1) + (w << 3) + (c ^ '0'), c = getchar();
  return p ? -w : w;
}
const int N = 1e5 + 5;
int n, m, head[N], v[N << 1], nxt[N << 1], w[N << 1], tot, in[N], cnt, dep[N],
    up[25][N], top, id[N];
ll d[N];
inline void add(int x, int y, int z) {
  v[++tot] = y, nxt[tot] = head[x];
  head[x] = tot;
  w[tot] = z;
}
void dfs(int x) {
  REP(i, 1, top) up[i][x] = up[i - 1][up[i - 1][x]];
  id[in[x] = ++cnt] = x;
  dep[x] = dep[up[0][x]] + 1;
  for (int i = head[x]; i; i = nxt[i])
    if (!in[v[i]]) up[0][v[i]] = x, d[v[i]] = d[x] + w[i], dfs(v[i]);
}
int lca(int x, int y) {
  if (dep[x] != dep[y]) {
    if (dep[x] < dep[y]) swap(x, y);
    REP(i, 0, top) if (dep[x] - dep[y] >> i & 1) x = up[i][x];
  }
  if (x == y) return x;
  DEC(i, top, 0) if (up[i][x] != up[i][y]) x = up[i][x], y = up[i][y];
  return up[0][x];
}
inline ll dis(int x, int y) {
  return d[id[x]] + d[id[y]] - 2 * d[lca(id[x], id[y])];
}
set<int> s;
typedef set<int>::iterator iter;
iter t1, t2, t3;
inline int ne(iter t) { return ++t == s.end() ? *s.begin() : *t; }
inline int pr(iter t) { return t == s.begin() ? *s.rbegin() : *--t; }
int main() {
  n = read();
  top = __lg(n) + 1;
  REP(i, 2, n) {
    int x = read(), y = read(), z = read();
    add(x, y, z), add(y, x, z);
  }
  dfs(1);
  ll sum = 0;
  m = read();
  while (m--) {
    char ss[2];
    scanf("%s", ss);
    if (ss[0] == '?') {
      printf("%lld\n", sum / 2);
      continue;
    }
    int x = in[read()];
    if ((t1 = s.find(x)) != s.end()) {
      int p = pr(t1), t = ne(t1);
      s.erase(t1);
      if (s.size() <= 1)
        sum = 0;
      else {
        sum += dis(p, t) - dis(p, x) - dis(t, x);
      }
    } else {
      s.insert(x);
      if (s.size() == 1) {
        sum = 0;
        continue;
      }
      if (s.size() == 2)
        sum = dis(*s.begin(), *s.rbegin()) << 1;
      else {
        t1 = t2 = s.find(x);
        if (x != *s.begin()) sum += dis(x, *--t1);
        if (x != *s.rbegin()) sum += dis(x, *++t2);
        if (x == *s.begin())
          sum += dis(x, *s.rbegin()) - dis(*t2, *s.rbegin());
        else if (x == *s.rbegin())
          sum += dis(x, *s.begin()) - dis(*t1, *s.begin());
        else
          sum -= dis(*t1, *t2);
      }
    }

  }
  return 0;
}
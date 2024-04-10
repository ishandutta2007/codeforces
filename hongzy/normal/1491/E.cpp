#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int N = 4e5 + 10;

struct edge { int v, nxt; } e[N << 1];
int n, ec, f[N], pos[N], hd[N];
void add(int u, int v) {
  e[ec] = {v, hd[u]}; hd[u] = ec ++;
}
int w[N], rt, size, sz[N], del[N];
void findrt(int u, int fa = 0) {
  sz[u] = 1; w[u] = 0;
  for(int i = hd[u], v; ~i; i = e[i].nxt) if(!del[i >> 1] && (v = e[i].v) != fa) {
    findrt(v, u); sz[u] += sz[v];
    w[u] = max(w[u], sz[v]);
  }
  w[u] = max(w[u], size - sz[u]);
  if(!rt || w[u] < w[rt]) rt = u;
}
int oksz, node, p[N], pe[N];
void dfs(int u, int fa = 0) {
  sz[u] = 1; p[u] = fa;
  for(int i = hd[u], v; ~i; i = e[i].nxt) if(!del[i >> 1]) {
    if((v = e[i].v) != fa) {
      dfs(v, u); sz[u] += sz[v];
    } else pe[u] = i >> 1;
  }
  if(sz[u] == oksz) {
    node = u;
  }
}
bool pd(int id, int sz) {
  if(sz <= 1) return 1;
  if(!~pos[sz]) return 0;
  rt = 0; size = sz; findrt(id);
  node = -1; oksz = f[pos[sz] - 2]; dfs(rt, 0); int u = node;
  if(!~u) return 0;
  del[pe[u]] = 1;
  int v = p[u];
  return pd(u, f[pos[sz] - 2]) && pd(v, f[pos[sz] - 1]);
}
int main() {
  scanf("%d", &n);
  fill(pos, pos + n + 1, -1);
  fill(hd + 1, hd + n + 1, -1);
  f[0] = f[1] = 1; pos[1] = 1;
  rep(i, 2, 64) {
    f[i] = f[i - 1] + f[i - 2];
    if(f[i] > int(2e5)) break ;
    pos[f[i]] = i;
  }
  int u, v;
  rep(i, 1, n - 1) {
    scanf("%d%d", &u, &v); add(u, v); add(v, u);
  }
  puts(pd(1, n) ? "YES" : "NO");
  return 0;
}
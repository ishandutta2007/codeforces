#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef long long ll;

const int N = 1e5 + 15;
const int mod = 1e9 + 7;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline void upd(int &x, const int &y) { (x += y) >= mod ? x -= mod : 0; }

struct Edge {
   int v, w, nxt;
} e[N * 4];
int n, m, ec, ans[2], sz[N], hd[N], deg[N], ch[N][2];
vector<int> vec[N];
void clr() { fill(hd + 1, hd + n + 1, -1); }
void add(int u, int v, int w) {
   e[ec] = (Edge) {v, w, hd[u]}; hd[u] = ec ++; deg[v] ++;
}
int cur[2], skip = -405, seq[N], s;
bool vis[N];
void dfs(int u) {
   if(vis[u]) return ;
   seq[++ s] = u; vis[u] = 1; //printf("%d,", u);
   for(int i = hd[u]; ~ i; i = e[i].nxt) dfs(e[i].v);
}
int tp, dp[N][2][2], t[2][2], numx, numy;
void Dp(int u, int pre = -404) {
   memset(dp[u], 0, sizeof dp[u]);
   if(deg[u] == 1 && u != tp) {
      if(skip >= 0) {
         dp[u][numy][numy] = 1;
         return ;
      }
      dp[u][0][0] = 1;
      if(sz[u] == 2)
         dp[u][1][1] = 1;
      return ;
   }
   for(int i = hd[u]; ~ i; i = e[i].nxt) if(i / 2 != pre / 2) {
      if(i / 2 == skip / 2) continue ;
      int v = e[i].v, w = e[i].w; Dp(v, i);
      rep(x, 0, 1) rep(y, 0, 1) {
         if(w) {
            upd(dp[u][1][y ^ (!x) ^ 1], dp[v][x][y]);
            upd(dp[u][0][y], dp[v][x][y]);
         } else {
            upd(dp[u][1][y ^ 1], dp[v][x][y]);
            upd(dp[u][0][y ^ (!x)], dp[v][x][y]);
         }
      }
   }
   if(u == tp && sz[u] == 2) {
      memset(t, 0, sizeof t);
      rep(x, 0, 1) rep(y, 0, 1) {
         if(skip >= 0) {
            if(numx) upd(t[1][y ^ (!x)], dp[u][x][y]);
            else upd(t[x][y], dp[u][x][y]);
            continue ;
         }
         upd(t[x][y], dp[u][x][y]);
         upd(t[x | 1][y ^ (!x)], dp[u][x][y]);
      }
      memcpy(dp[u], t, sizeof t);
   }
}
void solve(int u) {
   if(hd[u] == -1) {
      vis[u] = 1;
      if(sz[u] == 2 && ch[u][0] + ch[u][1] == 0) cur[0] = 0, cur[1] = 2; //xi or (-xi)
      else if(sz[u] == 1 || (sz[u] == 2 && ch[u][0] == ch[u][1])) cur[0] = cur[1] = 1; //xi / xi or xi
      else cur[0] = 1, cur[1] = 3; //xi or xj
   } else {
      s = 0; dfs(u); int rt = -1;
      rep(i, 1, s) if(deg[seq[i]] == 1) { rt = seq[i]; break ; }
      if(~ rt) {
         Dp(tp = rt);
         cur[0] = add(dp[tp][0][0], dp[tp][1][0]);
         cur[1] = add(dp[tp][0][1], dp[tp][1][1]);
      } else {
         skip = hd[u]; int bt = e[hd[u]].v, w = e[hd[u]].w;
         deg[bt] --;
         cur[0] = cur[1] = 0; numx = 0, numy = w ? 0 : 1; Dp(tp = u);
         upd(cur[0], add(dp[tp][0][0], dp[tp][1][0]));
         upd(cur[1], add(dp[tp][0][1], dp[tp][1][1]));
         numx = 1; numy = w ? 1 : 0; Dp(tp);
         upd(cur[0], add(dp[tp][0][0], dp[tp][1][0]));
         upd(cur[1], add(dp[tp][0][1], dp[tp][1][1]));
         skip = -404; deg[bt] ++;
      }
   }

   int n0 = ((ll) cur[1] * ans[1] + (ll) cur[0] * ans[0]) % mod;
   int n1 = ((ll) cur[1] * ans[0] + (ll) cur[0] * ans[1]) % mod;
   ans[0] = n0; ans[1] = n1;
}
int main() {
   scanf("%d%d", &n, &m); ans[0] = 1; clr();
   rep(i, 1, n) {
      int op; scanf("%d", &op); sz[i] = op;
      rep(j, 0, op - 1) {
         int x; scanf("%d", &x); vec[abs(x)].pb(x > 0 ? i : -i);
         ch[i][j] = x;
      }
   }
   int pw = 1 + 0;
   rep(i, 1, m) if(vec[i].size() == 2) {
      int u = vec[i][0], v = vec[i][1];
      if(abs(u) == abs(v)) continue ;
      int w = (u > 0) == (v > 0); //w = 1:1w = 0:1
      add(abs(u), abs(v), w); add(abs(v), abs(u), w);
   } else if(!vec[i].size()) {
      pw = add(pw, pw);
   }
   rep(i, 1, n) if(!vis[i]) solve(i);
   ans[1] = 1ll * ans[1] * pw % mod;
   printf("%d\n", ans[1]);
   return 0;
}
#include <algorithm>
#include <cstring>
#include <cstdio>
#define fs first
#define sc second
#define pii pair<int, int>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
typedef long long ll;
using namespace std;
const int N = 1 << 22 | 5;
struct Node { int x, y; } a[N];
int n;
struct Edge { int v, nxt; } e[N];
int ec, d[N], hd[N], ans[N], len;
void clr(int n) { fill(hd + 1, hd + n + 1, 0); fill(d + 1, d + n + 1, 0); ec = 0; }
void add(int u, int v) { e[++ ec] = (Edge) {v, hd[u]}; hd[u] = ec; }
void addd(int u, int v) { add(u, v); add(v, u); ++ d[u]; ++ d[v]; }
bool vis[N];
void fleury(int u) {
   for(int &i = hd[u]; i; ) {
      int v = e[i].v, num = (i + 1) >> 1, dir = i & 1;
      i = e[i].nxt;
      if(vis[num]) continue ;
      vis[num] = 1; fleury(v);
      if(v <= n) {
         ans[++ len] = v;
      }
   }
}
bool chk(int k) {
   int A = (1 << k) - 1;
   clr(n + (1 << k));
   rep(i, 1, n) {
      addd(i, n + 1 + (a[i].x & A));
      addd(i, n + 1 + (a[i].y & A));
   }
   rep(i, 1, n + (1 << k)) if(d[i] & 1) return 0;
   fill(vis, vis + ec + 1, 0);
   len = 0; fleury(n + 1 + (a[1].x & A)); //len -= 2;
   if(len != n) return 0;
   reverse(ans + 1, ans + n + 1);
   printf("%d\n", k);
   static int val[N]; val[0] = (a[1].x & A);
   if(val[0] == (a[ ans[1] ].x & A)) printf("%d %d ", 2*ans[1] - 1, 2*ans[1]), val[1] = a[ans[1]].y & A;
   else printf("%d %d ", 2*ans[1], 2*ans[1] - 1), val[1] = a[ans[1]].x & A;
   rep(i, 2, n) {
      if((a[ans[i]].x & A) == val[i - 1]) {
         val[i] = a[ans[i]].y & A;
         printf("%d %d ", 2*ans[i]-1, 2*ans[i]);
      } else {
         val[i] = a[ans[i]].x & A;
         printf("%d %d ", 2*ans[i], 2*ans[i] - 1);
      }
   }
   return 1;
}
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d%d", &a[i].x, &a[i].y);
   per(i, 20, 0) if(chk(i)) return 0;
   return 0;
}
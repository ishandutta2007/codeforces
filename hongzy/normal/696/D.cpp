#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
template<typename T> void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<typename T> void chkmin(T &x, const T &y) { if(x > y) x = y; }
typedef long long ll;

const ll INF = 8e18 + 10;
const int N = 205;
struct Node {
   ll a[N][N]; int n, m;
   Node operator * (const Node &b) const {
      Node ans; ans.n = n; ans.m = b.m;
      rep(i, 1, ans.n) rep(j, 1, ans.m) {
         ans.a[i][j] = - INF;
         rep(k, 1, m) if(a[i][k] > -INF && b.a[k][j] > -INF) {
            chkmax(ans.a[i][j], a[i][k] + b.a[k][j]);
         }
      }
      return ans;
   }
} fir, tr;
int n, id = 1, ch[N][26], val[N], fail[N], a[N];
ll L;
Node Pow(Node a, ll b) {
   Node ans = a; b --;
   for(; b >= 1; b >>= 1, a = a * a)
      if(b & 1) ans = ans * a;
   return ans;
}
void insert(char *s, int va) {
   int u = 1;
   for(; *s; s ++) {
      int &v = ch[u][*s - 'a'];
      u = v ? v : v = ++ id;
   }
   val[u] += va;
}
void build() {
   queue<int> q; int v = 0; fail[1] = 1;
   rep(i, 0, 25) if(v = ch[1][i]) {
      q.push(v); fail[v] = 1;
   } else ch[1][i] = 1;
   while(q.size()) {
      int u = q.front(); q.pop(); val[u] += val[fail[u]];
      rep(i, 0, 25) if(v = ch[u][i]) {
         q.push(v); fail[v] = ch[fail[u]][i];
      } else ch[u][i] = ch[fail[u]][i];
   }
}
int main() {
   scanf("%d%lld", &n, &L);
   rep(i, 1, n) scanf("%d", a + i);
   static char str[N];
   rep(i, 1, n) {
      scanf("%s", str);
      insert(str, a[i]);
   }
   build();
   fir.n = 1; fir.m = tr.n = tr.m = id;
   rep(i, 2, id) fir.a[1][i] = -INF;
   rep(i, 1, id) rep(j, 1, id) tr.a[i][j] = -INF;
   rep(i, 1, id) {
      int v = 0;
      rep(j, 0, 25) {
         v = ch[i][j];
         if(tr.a[i][v] == -INF) {
            tr.a[i][v] = 0;
         }
         tr.a[i][v] += val[v];
      }
   }
   fir = fir * Pow(tr, L);
   printf("%lld\n", *max_element(fir.a[1] + 1, fir.a[1] + id + 1));
   return 0;
}
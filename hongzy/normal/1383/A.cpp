#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}

template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

const int N = 4e5 + 10;

int n;
char s[N], t[N];
bool vis[21][21], mark[21];
int main() {
   int te; scanf("%d", &te);
   while(te --) {
      scanf("%d%s%s", &n, s + 1, t + 1);
      bool tag = 1;
      rep(i, 1, n) if(t[i] < s[i]) tag = 0;
      if(!tag) { puts("-1"); continue ; }
      rep(i, 1, 20) {
         rep(j, 1, 20) vis[i][j] = 0;
         mark[i] = 0;
      }
      rep(i, 1, n) if(s[i] != t[i]) {
         vis[s[i] - 'a' + 1][t[i] - 'a' + 1] = 1;
         vis[t[i] - 'a' + 1][s[i] - 'a' + 1] = 1;
      }
      int ans = 20;
      function<void(int)> dfs = [&](int u) {
         mark[u] = 1;
         rep(i, 1, 20) if(vis[u][i] && !mark[i]) {
            dfs(i);
         }
      };
      rep(i, 1, 20) if(!mark[i]) ans --, dfs(i);
      printf("%d\n", ans);
   }
   return 0;
}
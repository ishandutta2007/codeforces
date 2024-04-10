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
// mt19937_64 
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
char s[110];
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      int n, q;
      scanf("%d%d%s", &n, &q, s + 1);
      int l[2], r[2];
      l[0] = l[1] = n + 1; r[0] = r[1] = 0;
      rep(i, 1, n) {
         s[i] -= '0';
         chkmin(l[s[i]], i);
         chkmax(r[s[i]], i);
      }
      rep(i, 1, q) {
         int x, y;
         scanf("%d%d", &x, &y);
         if(l[s[x]] < x || r[s[y]] > y) puts("YES");
         else puts("NO");
      }
   }
   return 0;
}
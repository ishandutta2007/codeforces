#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
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

typedef vector<int> vi;
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

inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, m, sum[N], mxl[N], mnl[N], mxr[N], mnr[N];
char s[N];
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      scanf("%d%d", &n, &m);
      scanf("%s", s + 1);
      mxl[0] = mnl[0] = 0;
      rep(i, 1, n) {
         sum[i] = sum[i - 1] + (s[i] == '+' ? 1 : -1);
         mxl[i] = max(mxl[i - 1], sum[i]);
         mnl[i] = min(mnl[i - 1], sum[i]);
      }
      mxr[n + 1] = mnr[n + 1] = 0;
      per(i, n, 1) {
         mxr[i] = max(mxr[i + 1], 0) + (s[i] == '+' ? 1 : -1);
         mnr[i] = min(mnr[i + 1], 0) + (s[i] == '+' ? 1 : -1);
      }
      rep(i, 1, m) {
         int l, r;
         scanf("%d%d", &l, &r);
         int l0 = mnl[l - 1], r0 = mxl[l - 1];
         // printf("[%d, %d]\n", l0, r0);
         int r1 = sum[l - 1] + max(0, mxr[r + 1]);
         int l1 = sum[l - 1] + min(0, mnr[r + 1]);
         printf("%d\n", max(r1, r0) - min(l1, l0) + 1);
      }
   }
   return 0;
}
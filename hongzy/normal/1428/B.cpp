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

const int N = 6e5 + 10;
const int INF = 2e9 + 10;

int qpow(int a, int b, int mod) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, ans;
char s[N];
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      scanf("%d%s", &n, s + 1);
      ans = 0;
      bool tag1 = 1, tag2 = 1;
      rep(i, 1, n) if(s[i] == '<') tag1 = 0;
      rep(i, 1, n) if(s[i] == '>') tag2 = 0;
      if(tag1 || tag2) ans = n;
      else {
         rep(i, 1, n) if(s[i] == '-' || s[i == n ? 1 : i + 1] == '-') ans ++;
      }
      printf("%d\n", ans);
   }
   return 0;
}
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

const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
const int N = 1e6 + 10;
int n, k, cnt1[N], cnt[N];
char a[N], b[N];
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      scanf("%d%d%s%s", &n, &k, a + 1, b + 1);
      for(int i = 0; i < 26; i ++) cnt1[i] = cnt[i] = 0;
      rep(i, 1, n) cnt1[a[i] - 'a'] ++, cnt[b[i] - 'a'] ++;
      bool tag(1);
      rep(i, 0, 25) {
         if(cnt1[i] == cnt[i]) continue ;
         if(cnt1[i] < cnt[i]) {
            tag = 0; break ;
         }
         if((cnt1[i] - cnt[i]) % k || i == 25) {
            tag = 0; break ;
         }
         cnt1[i + 1] += cnt1[i] - cnt[i];
      }
      puts(tag ? "Yes" : "No");
   }
   return 0;
}
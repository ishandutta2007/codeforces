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
const int N = 512;
int n, m, ans[N], a[N][N];
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      scanf("%d%d", &n, &m);
      rep(i, 2, n + m) ans[i] = 0;
      rep(i, 1, n) rep(j, 1, m) {
         scanf("%d", a[i] + j);
         ans[i + j] ^= a[i][j];
      }
      int cnt = 0;
      rep(i, 2, n + m) cnt += ans[i] > 0;
      puts(cnt ? "Ashish" : "Jeel");
   }   
   return 0;
}
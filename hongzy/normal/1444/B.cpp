#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 998244353;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<long long> ran(0, 1ll << 62);
void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
int n, a[N];
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int fac[N], fav[N]; 
int C(int n, int m) {
   return n < m || n < 0 || m < 0 ? 0 : 1ll * fac[n] * fav[m] % mod * fav[n - m] % mod;
}
void binom(int n) {
   fac[0] = 1;
   for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
   fav[n] = qpow(fac[n], mod - 2);
   for(int i = n; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mod;
}
int main() {
   scanf("%d", &n); binom(n * 2);
   rep(i, 1, 2*n) {
   	scanf("%d", a + i);
	}
	sort(a + 1, a + 2*n + 1);
	ll ans = 0, all = C(2 * n, n);
	rep(i, 1, 2 * n) { //n=i-1
		if(n - 1 <= i - 1 - 1) {
			ans = (ans + a[i]) % mod;
		} else {
			ans = (ans - a[i]) % mod;
		}
	}
	ans = ans * all % mod;
	ans = (ans % mod + mod) % mod;
	cout << ans << endl;
   return 0;
}
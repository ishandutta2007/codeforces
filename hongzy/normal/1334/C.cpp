#include <bits/stdc++.h>
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
 
const int N = 6e5 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int T, n;
ll a[N], b[N], sum[N];
int main() {
	scanf("%d", &T);
	while(T --) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) {
			scanf("%lld%lld", a + i, b + i);
			a[i + n] = a[i]; b[i + n] = b[i];
		}
		for(int i = 1; i <= 2 * n; i ++) {
			sum[i] = sum[i - 1] + max(0ll, a[i] - b[i - 1]);
		}
		ll ans = 2e18;
		for(int i = 1; i <= n; i ++) {
			ans = min(ans, sum[i + n - 1] - sum[i] + a[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long double ldb;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
template <typename T>
T range(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rnd);
}

const int N = 5e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}

int n, m, p[N];
ll c[N];
uint val[N], h[N];
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i ++) {
			scanf("%lld", c + i); h[i] = 0; p[i] = i;
			val[i] = range<uint>(233, 1e9 + 7);
		}
		for(int i = 1; i <= m; i ++) {
			int u, v; scanf("%d%d", &u, &v); h[v] ^= val[u];
		}
		sort(p + 1, p + n + 1, [] (int x, int y) {
			return h[x] < h[y];
		});
		ll ans = 0, sum = 0;
		for(int i = 1; i <= n; i ++) {
			if(h[p[i]]) sum += c[p[i]];
			if(i == n || h[p[i]] != h[p[i + 1]]) {
				ans = __gcd(ans, sum); sum = 0;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 200005;
const int mod = 1e9+7;

int n, f[N], rf[N];

int pow_mod(int x, int k) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return ans;
}

int C(int n, int m) {
	if (n < m) return 0;
	return 1ll * f[n] * rf[n - m] % mod * rf[m] % mod;
}

int main() {
	f[0] = 1; for (int i = 1; i < N; i++) f[i] = 1ll * f[i - 1] * i % mod;
	rf[N - 1] = pow_mod(f[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; i--) rf[i] = 1ll * rf[i + 1] * (i + 1) % mod;
	scanf("%d", &n);
	printf("%lld\n", (2ll * C(2 * n - 1, n - 1) - n + mod) % mod);
	return 0;
}
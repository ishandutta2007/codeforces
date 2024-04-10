#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int maxn = 2e5 + 5;
const int mod = 998244353;
int n, k;
int fc[maxn], ifc[maxn];

int qp(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = x * 1LL * x % mod)
		if (n & 1) ans = ans * 1LL * x % mod;
	return ans;
}

int C(int n, int m) {
	if (m < 0 || m > n) return 0;
	return fc[n] * 1LL * ifc[m] % mod * ifc[n - m] % mod;
}

int main() {
	rep(i, maxn) fc[i] = i ? fc[i - 1] * 1LL * i % mod : 1;
	ifc[maxn - 1] = qp(fc[maxn - 1], mod - 2);
	for (int i = maxn - 1; i; -- i) ifc[i - 1] = ifc[i] * 1LL * i % mod;
	scanf("%d %d", &n, &k);
	if (k >= n) { puts("0"); return 0; }
	if (k == 0) { printf("%d\n", fc[n]); return 0; }
	int ans = 0;
	rep(i, n - k + 1) {
		int cur = C(n, n - k);
		cur = cur * 1LL * C(n - k, i) % mod;
		cur = cur * 1LL * qp(n - k - i, n) % mod;
		if (i & 1) (ans += mod - cur) %= mod;
		else (ans += cur) %= mod;
	}
	printf("%lld\n", ans * 2LL % mod);
	return 0;
}
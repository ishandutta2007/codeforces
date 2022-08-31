#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll inv2 = (mod + 1) / 2;

ll qpow(ll a, ll n) {
	ll r = 1;
	for (; n; n >>= 1) {
		if (n & 1) r = r * a % mod;
		a = a * a % mod;
	}
	return r;
}

const int N = 510;
ll a[N][N];
int p[N], cnt[N];
int n;

void solve() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			if (a[i][j] < 0) a[i][j] += mod;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) if (a[j][i]) {
				for (int k = 0; k <= n; k++) {
					swap(a[i][k], a[j][k]);
				}
				break;
			}
		int inv = qpow(a[i][i], mod - 2);
		for (int k = 0; k <= n; k++) a[i][k] = a[i][k] * inv % mod;
		for (int j = i + 1; j < n; j++) if (a[j][i]) {
				int r = a[j][i];
				for (int k = 0; k <= n; k++) {
					a[j][k] = (a[j][k] - r * a[i][k]) % mod;
					if (a[j][k] < 0) a[j][k] += mod;
				}
			}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			a[j][n] = (a[j][n] - a[j][i] * a[i][n]) % mod;
			if (a[j][n] < 0) a[j][n] += mod;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i][i] = 1;
		if (i != n - 1) {
			a[i][i + 1] = (a[i][i + 1] - inv2) % mod;
			a[i][0] = (a[i][0] - i * inv2) % mod;
			a[i][n] = inv2;
		}
	}
	solve();
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
		if (p[i] != -1) cnt[p[i] - 1]++;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) if (p[i] == -1)
			ans = (ans + a[cnt[i]][n]) % mod;
	printf("%lld\n", ans);
}
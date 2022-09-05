#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

const int N = 2e5 + 5, D = 998244353;
s64 pow_mod(s64 x, int y = D - 2) {
	s64 ans = 1;
	while (y) {
		if (y & 1) ans = ans * x % D;
		x = x * x % D;
		y >>= 1;
	}
	return ans;
}
s64 fac[N], ifac[N], p[N];
int cnt[N], b[N], s[N];
void add(int i, int v, s64 x) {
	for (; i < N; i += i & -i) {
		s[i] += v;
		p[i] = p[i] * x % D;
	}
}
pair<int, s64> query(int i) {
	int sum = 0;
	s64 prod = 1;
	for (; i; i -= i & -i) {
		sum += s[i];
		prod = prod * p[i] % D;
	}
	return { sum, prod };
}
s64 C(int n, int m) {
	return fac[n] * ifac[m] % D * ifac[n - m] % D;
}
s64 work(int v) {
	auto [ps, pp] = query(v - 1);
	if (!ps) return 0;
	auto [ts, tp] = query(N - 1);

	return fac[ps] * fac[ts - ps] % D * tp % D * C(ts - 1, ps - 1) % D;
}

int main() {
#ifdef kcz
	freopen("1.in", "r", stdin); //freopen("1.out","w",stdout);
#endif
	fac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % D;
	ifac[N - 1] = pow_mod(fac[N - 1]);
	for (int i = N - 1; i; --i) ifac[i - 1] = ifac[i] * i % D;
	for (int i = 1; i < N; ++i) p[i] = 1;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	for (int i = 1; i < N; ++i) add(i, cnt[i], ifac[cnt[i]]);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", b + i);
	}
	s64 ans = 0;
	for (int i = 0; i < m; ++i) {
		if (i == n) {
			++ans;
			break;
		}
		int v = b[i + 1];
		ans += work(v);
		if (cnt[v] == 0) break;
		--cnt[v];
		add(v, -1, ifac[cnt[v]] * fac[cnt[v] + 1] % D);
	}
	cout << ans % D << endl;
}
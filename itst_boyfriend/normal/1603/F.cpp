// stop making trivial q-binomial problems.
#include <iostream>

typedef unsigned long long ull;

const int N = 10000010, P = 998244353;

const int INV2 = (P + 1) / 2;

int mpow(int x, int k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

int pw[N], prd[N], iprd[N], ii[N], vi[N];
int v1[N], v2[N];

void pre(int n) {
	pw[0] = 1; for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 2 % P;
	prd[0] = 1; for (int i = 1; i <= n; ++i) prd[i] = prd[i - 1] * (pw[i] - 1ULL) % P;
	iprd[n] = mpow(prd[n], P - 2); for (int i = n; i; --i) iprd[i - 1] = iprd[i] * (pw[i] - 1ULL) % P;
	ii[0] = 1;
	int iv = 1;
	for (int i = 1; i <= n; ++i) { ii[i] = ii[i - 1] * (ull)iv % P; iv = iv * (ull)INV2 % P; }
	vi[0] = 1;
	int v = 1;
	for (int i = 1; i <= n; ++i) { vi[i] = vi[i - 1] * (ull)v % P; v = v * 2 % P; }
}

void work(int k, int* val) {
	for (int i = 0; i <= k; ++i) val[i] = prd[k] * (ull)iprd[i] % P * iprd[k - i] % P;
}

int bin[N];
void binoms(int n, int k) {
	int pw = mpow(2, n);
	bin[0] = 1;
	int pr = 1;
	for (int i = 1; i <= k; ++i) {
		pr = pr * (pw - 1ULL) % P;
		pw = pw * (ull)INV2 % P;
		bin[i] = pr * (ull)vi[i] % P;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	pre(1e7);

	int T; std::cin >> T;
	while (T--) {
		int n, k, x; std::cin >> n >> k >> x;
		int ans;
		if (x == 0) {
			int v = mpow(2, k), w = 1;
			ans = 1;
			for (int i = 0; i != n; ++i) {
				ans = ans * ull(P + v - w) % P;
				if (ans == 0) break;
				w = w * 2 % P;
			}
		} else {
			work(k, v1); work(k - 1, v2);
			for (int i = 1; i <= k; ++i) v1[i] = (v1[i] + P - v2[i - 1]) % P;
			binoms(n, k);
			ans = 0;
			for (int i = 0; i <= k; ++i) ans = (ans + bin[i] * (ull)v1[i]) % P;
		}
		std::cout << ans << '\n';
	}

	return 0;
}
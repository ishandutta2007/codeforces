// Hydro submission #628789e74b7a66f002ac8afa@1653049831630
#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 2005
#define P 1000000007

int n, a[N], v[N], fac[N], inv[N];
vector<int> c;

int Pow(int x, int k, int r = 1) {
	for (; k; k >>= 1, x = x * x % P) {
		if (k & 1) r = r * x % P;
	}
	return r;
}

int C(int n, int m) {
	if (!m) return 1;
	return fac[n] * inv[m] % P * inv[n - m] % P;
}

signed main() {
	fac[0] = 1;
	for (int i = 1; i < N; i ++) {
		fac[i] = fac[i - 1] * i % P;
	}
	inv[N - 1] = Pow(fac[N - 1], P - 2);
	for (int i = N - 2; ~i; i --) {
		inv[i] = inv[i + 1] * (i + 1) % P;
	}
	n = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
		if (a[i] == -1) {
			c.push_back(i);
		} else v[a[i]] = 1;
	}
	int ped = 0, res = 0;
	for (auto x : c) {
		if (!v[x]) ped ++;
	}
	for (int i = 0; i <= ped; i ++) {
		int now = C(ped, i) * fac[c.size() - i] % P;
		(res += (((i & 1) ? -1 : 1) * now % P + P) % P) %= P;
	}
	printf("%lld\n", res);
	return 0;
}
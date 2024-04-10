// Hydro submission #62878a087a0749f0176f9d71@1653049865427
#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 4010
#define P 1000000009

int n, w, b, m, f[N][N], fac[N];

signed main() {
	fac[0] = 1;
	for (int i = 1; i < N; i ++) {
		fac[i] = fac[i - 1] * i % P;
	}
	n = read(), w = read(), b = read(), m = max(w, b);
	for (int j = 1; j <= m; j ++) f[1][j] = 1;
	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % P;
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			(f[i][j] *= fac[j]) %= P;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 2; j <= n; j ++) {
			(res += f[i + (n - j + 1)][w] * f[j - i - 1][b] % P) %= P;
		}
	}
	printf("%lld\n", res);
	return 0;
}
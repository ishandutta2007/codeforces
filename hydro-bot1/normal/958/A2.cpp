// Hydro submission #627633f4100a2135bc3646fc@1651913716915
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
#define B 1919
#define P 998244353

int n, m, pw[N], iv[N], a[N], b[N][N], c[N], nex[N];
char s[N][N], t[N][N];

int Pow(int x, int k, int r = 1) {
	for (; k; k >>= 1, x = x * x % P) {
		if (k & 1) r = r * x % P;
	}
	return r;
}

int geh(int i, int l, int r) {
	return (b[i][r] - b[i][l - 1] + P) % P * iv[l - 1] % P;
}

signed main() {
	pw[0] = iv[0] = 1;
	for (int i = 1; i < N; i ++) {
		pw[i] = pw[i - 1] * B % P;
		iv[i] = Pow(pw[i], P - 2);
	}

	n = read(), m = read();
	for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= m; i ++) scanf("%s", t[i] + 1);

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			(a[i] += (s[i][j] & 31) * pw[j - 1]) %= P; 
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			b[i][j] = (b[i][j - 1] + (t[i][j] & 31) * pw[j - 1]) % P; 
		}
	}

	for (int i = 2, j = 0; i <= n; i ++) {
		while (j && a[i] != a[j + 1]) j = nex[j];
		nex[i] = (j += (a[i] == a[j + 1]));
	}

	for (int k = 1; k + m - 1 <= n; k ++) {
		for (int j = 1; j <= m; j ++) {
			c[j] = geh(j, k, k + m - 1);
		}
		for (int i = 1, j = 0; i <= n; i ++) {
			while (j && (a[i] != c[j + 1])) j = nex[j];
			if (a[i] == c[j + 1]) j ++;
			if (j == m) return printf("%lld %lld\n", i - m + 1, k), 0;
		}
	}
	return 0;
}
// Hydro submission #62878a974b7a66f002ac8ca6@1653050008161
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 40
#define Q 1000000007

int n, s, a[N], res = 0;

int F(int x, int s = 0) {
	while (x) { x -= x & -x; s ++; }
	return (s & 1) ? -1 : 1;
}
int Qow(int x, int k, int r = 1) {
	for (; k; k >>= 1, x = x * x % Q) {
		if (k & 1) r = r * x % Q;
	}
	return r;
}
int C(int n, int m) {
	int r = 1, x = 1;
	for (int i = 1; i <= m; i ++) {
		x = x * (i % Q) % Q;
		r = r * ((n - i + 1) % Q) % Q;
	}
	return r * Qow(x, Q - 2) % Q;
}

signed main() {
	n = read(), s = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	for (int i = 0; i < 1 << n; i ++) {
		int sum = s;
		for (int j = 1; j <= n; j ++) {
			if (i >> (j - 1) & 1) sum -= a[j] + 1;
		}
		if (sum < 0) continue;
		(res += F(i) * C(sum + n - 1, n - 1) % Q + Q) %= Q;
	}
	printf("%lld\n", res);
	return 0;
}
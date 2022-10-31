// Hydro submission #62878a634b7a66f002ac8b89@1653049955556
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 5005
#define Q 1000000007

int n, k, q, a[N], f[N][N], x[N];

signed main() {
	n = read(), k = read(), q = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	for (int j = 1; j <= n; j ++) f[0][j] = 1;
	for (int i = 1; i <= k; i ++) {
		for (int j = 1; j <= n; j ++) {
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j + 1]) % Q;
		}
	}
	for (int i = 0; i <= k; i ++) {
		for (int j = 1; j <= n; j ++) {
			x[j] = (x[j] + f[i][j] * f[k - i][j] % Q) % Q;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i ++) {
		res = (res + x[i] * a[i] % Q) % Q;
	}
	while (q --) {
		int qos = read(), val = read();
		res = (res - x[qos] * a[qos] % Q + Q) % Q;
		res = (res + val * x[qos] % Q) % Q, a[qos] = val;
		printf("%lld\n", res);
	}
	return 0;
}
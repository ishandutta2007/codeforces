// Hydro submission #62878ab14b7a66f002ac8cee@1653050033606
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define Q 1000000007

int qow(int x, int k, int r = 1) {
	for (; k; k >>= 1, x = x * x % Q) {
		if (k & 1) r = r * x % Q;
	}
	return r;
}

signed main() {
	int n = read(), m = read(), res = qow(m, n);
	for (int i = 1; i <= n; i ++) {
		res = (res + qow(m, n - i + 1) * qow(2 * m - 1, i - 1) % Q) % Q;
	}
	printf("%lld\n", res);
	return 0;
}
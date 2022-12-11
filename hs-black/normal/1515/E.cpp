#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int N = 555;
ll f[N][N]; int n, P;
int main() {
	read(n), read(P), f[0][0] = 1;
	for (int i = 0;i < n; ++i) {
		for (int j = 0;j <= i; ++j) {
			f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j] * (j + 1)) % P;
			f[i + 1][j] = (f[i + 1][j] + f[i][j] * 2 * j) % P;
			f[i + 2][j] = (f[i + 2][j] + f[i][j] * 2 * j) % P;
			if (j) f[i + 2][j - 1] = (f[i + 2][j - 1] + f[i][j] * (j - 1) * 2) % P;
			if (j) f[i + 3][j - 1] = (f[i + 3][j - 1] + f[i][j] * (j - 1)) % P;
		}
	}
	write(f[n][1]);
	return 0;
}
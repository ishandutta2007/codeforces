#include <iostream>
#include <cstring>
#include <cstdio>
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

int T, v[55][55], n, m;
int main() {
	for (read(T); T; T--) {
		read(n), read(m); memset(v, 0, sizeof(v));
		v[1][1] = v[n][1] = v[1][m] = v[n][m] = 1;
		for (int i = 1;i <= n; ++i, puts("")) {
			for (int j = 1;j <= m; ++j) {
				if ((i == 1 || i == n) && !v[i][j - 1] && !v[i][j + 1]) v[i][j] = 1;
				if ((j == 1 || j == m) && !v[i - 1][j] && !v[i + 1][j]) v[i][j] = 1;
				putchar('0' + v[i][j]);
			}
		}
	}
	return 0;
}
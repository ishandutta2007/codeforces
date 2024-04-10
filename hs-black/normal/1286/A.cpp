#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define MP make_pair
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

const int N = 105;
int n, cnt1, cnt0, p[N];
int f[N][N][N][2];
template <typename T>
void Mn(T &x, T y) { if (x > y) x = y; }
int main() {
	read(n), cnt1 = (n + 1) >> 1, cnt0 = n >> 1;
	for (int i = 1;i <= n; ++i) {
		read(p[i]);
		if (p[i]) p[i] & 1 ? --cnt1 : --cnt0;
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0][0][0] = f[0][0][0][1] = 0;
	for (int i = 1;i <= n; ++i) {
		for (int j = 0;j < i; ++j)
			for (int k = 0;k < i; ++k) {
				for (int t = 0;t <= 1; ++t) {
					if (p[i]) Mn(f[i][j][k][p[i] & 1], f[i-1][j][k][t] + ((p[i] & 1) ^ t));
					else Mn(f[i][j + 1][k][0], f[i-1][j][k][t] + t), Mn(f[i][j][k + 1][1], f[i-1][j][k][t] + !t);
				}
			}
	}
	write(min(f[n][cnt0][cnt1][0], f[n][cnt0][cnt1][1]));
	return 0;
}
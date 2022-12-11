#include <iostream>
#include <cstdio>
#include <cstring>
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

bool v[2][2000][500];
int T, n, m;
char s[555], t[1055];
int main() {
	for (read(T); T; T--) {
		scanf ("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		for (int i = 1;i <= n; ++i) v[0][1][i] = s[i] == t[1];
		for (int i = 2;i <= m; ++i) {
			v[1][i - 1][n + 1] = v[0][i - 1][n + 1] = 0;
			for (int j = 1;j <= n; ++j) if (s[j] == t[i]) {
				v[0][i][j] = v[0][i - 1][j - 1];
				v[1][i][j] = v[0][i - 1][j + 1] | v[1][i - 1][j + 1];
			}
			else v[0][i][j] = v[1][i][j] = 0;
		}
		int fl = 0;
		for (int i = 1; i <= n; ++i) fl |= v[0][m][i] | v[1][m][i];
		puts(fl ? "YES" : "NO");
	}
	return 0;
}
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

const int N = 2000050;
int h[N], to[N<<1], ne[N<<1], deg[N], tot, T, n;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y, ++deg[x]; }
inline void adde(int x, int y) { add(x, y), add(y, x); }
char s[N];
int main() {
	int cnt = 0;
	for (read(T); T; --T) {
		read(n), memset(h, 0, (n + 1) << 2), tot = 0;
		memset(deg, 0, (n + 1) << 2); ++cnt;
		for (int i = 1, x, y;i < n; ++i) {
			read(x), read(y), adde(x, y);
		}
		scanf ("%s", s + 1);
		int tn = n, fl = 0;
		for (int i = 1;i <= tn; ++i) if (s[i] == 'W') 
			h[++n] = 0, deg[n] = 2, adde(n, i);
		
		int jzp = 0;

		for (int i = 1;i <= n && !fl; ++i) {
			fl |= deg[i] >= 4;
			if (deg[i] < 3) continue;
			int ct = 0, kk = 0;
			for (int t = h[i]; t; t = ne[t]) {
				int y = to[t];
				if (deg[y] >= 2) ++ct;
				else ++kk;
			}
			if (ct >= 2) fl = 1;
			++jzp;
		}
		if (jzp >= 2) fl |= n & 1;
		if (fl) puts("White");
		else puts("Draw");
	}
	return 0;
}
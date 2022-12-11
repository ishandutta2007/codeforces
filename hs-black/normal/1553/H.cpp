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

const int N = 2000500;
int ch[N][2], f[N], a[N], lim, cnt, n, k;
void dfs(int p, int dep, int l, int r) {
	if ((!p && dep < k) || l == r) return;
	int mid = (l + r) >> 1;
	dfs(ch[p][0], dep - 1, l, mid);
	dfs(ch[p][1], dep - 1, mid + 1, r);
	int len = 1 << (dep - 1), *f = ::f + l;
	if (!ch[p][0] || !ch[p][1]) {
		for (int i = 0;i < len; ++i) 
			f[i] = f[i + len] = min(f[i], f[i + len]);
		return ;
	}
	for (int i = 0;i < len; ++i) {
		int lmx = 0, lmn = 0, rmx = 0, rmn = 0;
		int l1 = ch[p][0], l2 = l1;
		int r1 = ch[p][1], r2 = r1;
		for (int j = dep - 2;j >= 0; --j) {
			int c = i >> j & 1, bt = 1 << j;
			if (ch[l1][c]) l1 = ch[l1][c];
			else l1 = ch[l1][!c], lmn += bt;
			if (ch[l2][!c]) l2 = ch[l2][!c], lmx += bt;
			else l2 = ch[l2][c];
			if (ch[r1][c]) r1 = ch[r1][c];
			else r1 = ch[r1][!c], rmn += bt;
			if (ch[r2][!c]) r2 = ch[r2][!c], rmx += bt;
			else r2 = ch[r2][c];
		}
		f[i] = min(f[i], f[i + len]);
		f[i + len] = min(f[i], len + lmn - rmx);
		f[i] = min(f[i], len + rmn - lmx);
	}
}

int main() {
	read(n), read(k), lim = 1 << k;
	for (int i = 1, x;i <= n; ++i) {
		read(x);
		int p = 0;
		for (int j = k - 1;j >= 0; --j) {
			int c = x >> j & 1;
			if (!ch[p][c]) ch[p][c] = ++cnt;
			p = ch[p][c];
		}
	}
	memset(f, 0x3f, sizeof(f));
	dfs(0, k, 0, lim - 1);
	//write(f[0]);
	for (int i = 0;i < lim; ++i) write(f[i], ' ');
	return 0;
}
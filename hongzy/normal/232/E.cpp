#include <bits/stdc++.h>
#define pb push_back 
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef unsigned int uint;
const int N = 505;
const int M = 6e5 + 10;
struct Bitset {
	uint a[16];
	int n;
	void init(int sz) {
		n = ((sz - 1) >> 5) + 1;
		fill(a, a + n, 0);
	}
	void set(int z) {
		a[z >> 5] |= 1u << (z & 31);
	}
	void operator |= (const Bitset &b) {
		for(int i = 0; i < n; i ++)
			a[i] |= b.a[i];
	}
	bool operator & (const Bitset &b) const {
		for(int i = 0; i < n; i ++)
			if(a[i] & b.a[i]) return 1;
		return 0;
	} 
} vis[N][N];
struct node {
	int x1, y1, x2, y2, id;
} a[M], buf[M];
int n, m, q;
char s[N][N];
bool ans[M];
void solve(int xl, int xr, int yl, int yr, int ql, int qr) {
	if(xl > xr || yl > yr || ql > qr) return ;
	if(xl == xr && yl == yr) {
		if(s[xl][yl]) {
			rep(i, ql, qr) ans[a[i].id] = 1;
		}
		return ;
	}
	int n = xr - xl + 1, m = yr - yl + 1;
	if(m >= n) {
		int ym = (yl + yr) >> 1;
		rep(i, xl, xr) rep(j, yl, yr) vis[i][j].init(n);
		
		rep(i, xl, xr) if(s[i][ym]) vis[i][ym].set(i - xl);
		per(i, xr, xl) per(j, ym, yl) if(s[i][j]) {
			if(i < xr) vis[i][j] |= vis[i + 1][j];
			if(j < ym) vis[i][j] |= vis[i][j + 1];
		}
		rep(i, xl, xr) if(s[i][ym + 1]) vis[i][ym + 1].set(i - xl);
		rep(i, xl, xr) rep(j, ym + 1, yr) if(s[i][j]) {
			if(i > xl) vis[i][j] |= vis[i - 1][j];
			if(j > ym + 1) vis[i][j] |= vis[i][j - 1];
		}
		
		int w1 = ql, w2 = qr;
		rep(i, ql, qr) {
			node &c = a[i];
			if(c.y1 <= ym && c.y2 > ym) {
				ans[c.id] |= vis[c.x1][c.y1] & vis[c.x2][c.y2];
			} else if(c.y2 <= ym) {
				buf[w1++] = c;
			} else {
				buf[w2--] = c;
			}
		}
		copy(buf + ql, buf + w1, a + ql);
		copy(buf + w2 + 1, buf + qr + 1, a + w2 + 1);
		solve(xl, xr, yl, ym, ql, w1 - 1);
		solve(xl, xr, ym + 1, yr, w2 + 1, qr);
	} else {
		int xm = (xl + xr) >> 1;
		rep(i, xl, xr) rep(j, yl, yr) vis[i][j].init(m);
		
		rep(j, yl, yr) if(s[xm][j]) vis[xm][j].set(j - yl);
		per(i, xm, xl) per(j, yr, yl) if(s[i][j]) {
			if(i < xm) vis[i][j] |= vis[i + 1][j];
			if(j < yr) vis[i][j] |= vis[i][j + 1];
		}
		rep(j, yl, yr) if(s[xm + 1][j]) vis[xm + 1][j].set(j - yl);
		rep(i, xm + 1, xr) rep(j, yl, yr) if(s[i][j]) {
			if(i > xm + 1) vis[i][j] |= vis[i - 1][j];
			if(j > yl) vis[i][j] |= vis[i][j - 1];
		}
		
		int w1 = ql, w2 = qr;
		rep(i, ql, qr) {
			node &c = a[i];
			if(c.x1 <= xm && c.x2 > xm) {
				ans[c.id] |= vis[c.x1][c.y1] & vis[c.x2][c.y2];
			} else if(c.x2 <= xm) {
				buf[w1++] = c;
			} else {
				buf[w2--] = c;
			}
		}
		copy(buf + ql, buf + w1, a + ql);
		copy(buf + w2 + 1, buf + qr + 1, a + w2 + 1);
		solve(xl, xm, yl, yr, ql, w1 - 1);
		solve(xm + 1, xr, yl, yr, w2 + 1, qr);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", s[i] + 1);
	rep(i, 1, n) rep(j, 1, m) s[i][j] = s[i][j] == '.';
	scanf("%d", &q);
	rep(i, 1, q) {
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
		a[i].id = i;
	}
	solve(1, n, 1, m, 1, q);
	rep(i, 1, q) puts(ans[i] ? "Yes" : "No");
	return 0;
}
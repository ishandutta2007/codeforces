
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

#define ull unsigned ll
const int B = 1333331;
const int N = 300500;
ull bs[N], pux[N], hs[N], add[N];
int siz[N], son[N][2], p[N];
#define ls son[x][0]
#define rs son[x][1]
inline void spread(int x) {
	if (!add[x]) return;
	add[ls] += add[x], add[rs] += add[x];
	hs[ls] += pux[siz[ls]] * add[x];
	hs[rs] += pux[siz[rs]] * add[x];
	p[ls] += add[x], p[rs] += add[x];
	add[x] = 0;
}

inline void update(int x) {
	siz[x] = siz[ls] + siz[rs] + 1;
	hs[x] = p[x];
	if (ls) hs[x] = hs[ls] + hs[x] * bs[siz[ls]];
	if (rs) hs[x] = hs[x] + hs[rs] * bs[siz[ls] + 1];
}

int rnd[N], cnt;
int bui(void) { rnd[++cnt] = rand(), siz[cnt] = 1; return cnt; }

int merge(int x, int y) {
	if (!x || !y) return x | y;
	spread(x), spread(y);
	if (rnd[x] < rnd[y]) return rs = merge(rs, y), update(x), x;
	return son[y][0] = merge(x, son[y][0]), update(y), y;
}

void split(int nw, int k, int &x, int &y) {
	if (!nw) return x = y = 0, void();
	spread(nw);
	if (siz[son[nw][0]] >= k) 
		y = nw, split(son[y][0], k, x, son[y][0]);
	else x = nw, split(rs, k - siz[ls] - 1, rs, y);
	update(nw);
}

int d[N];

int m, n, a[N], b[N], rt, X, Y, Z;
ull H;
void Add(int x, int c) {
	for (; x <= m; x += x & -x) d[x] += c;
}

int sum(int x) {
	int res = 0;
	for (; x; x -= x & -x) res += d[x];
	return res;
}

int t[N];
int main() {
	read(n), read(m);
	bs[0] = 1; int ans = 0;
	for (int i = 1;i <= n; i++) bs[i] = bs[i-1] * B;
	for (int i = 1;i <= n; i++) pux[i] = pux[i-1] + bs[i-1];
	for (int i = 1;i <= n; i++) read(a[i]), H = H + a[i] * bs[i-1];
	for (int i = 1;i <= m; i++) read(b[i]), t[b[i]] = i;
	for (int i = m;i >= 1; i--) {
		int x = t[i], pos = sum(x);
		Add(x, 1), split(rt, pos, X, Y);
		rt = merge(merge(X, bui()), Y);
		if (m - i >= n) {
			pos = sum(t[i + n]);
			split(rt, pos - 1, X, Y);
			split(Y, 1, Z, Y);
			rt = merge(X, Y);
			Add(t[i + n], -1);
		}
		add[rt]++, p[rt]++, hs[rt] += pux[siz[rt]];
		if (hs[rt] == H) ans++;
	}
	write(ans);
	return 0;
}
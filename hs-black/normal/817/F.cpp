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
inline void write(F x, char ed = '\n')
{
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

const int N = 300500;
const ll inf = (ll)1e18 + 10;
int rt, n, x, y, z, cnt;

struct node {
	ll l, r, m0, m1; int fil;
	int ls, rs, tag, rnd, rev;
	#define ls(x) t[x].ls
	#define rs(x) t[x].rs
	#define l(x) t[x].l
	#define r(x) t[x].r
	#define fil(x) t[x].fil
	#define tag(x) t[x].tag
	#define m0(x) t[x].m0
	#define m1(x) t[x].m1
	#define rnd(x) t[x].rnd
	#define rev(x) t[x].rev
}t[N];

int build(ll l, ll r, int fil) {
	t[++cnt] = (node) {l, r, fil ? inf : l, fil ? l : inf, fil, 0, 0, -1, rand(), 0};
	return cnt;
}

void update(int p) {
	m0(p) = fil(p) ? inf : l(p); m1(p) = fil(p) ? l(p) : inf;
	if (ls(p)) Mn(m0(p), m0(ls(p))), Mn(m1(p), m1(ls(p)));
	if (rs(p)) Mn(m0(p), m0(rs(p))), Mn(m1(p), m1(rs(p)));
}

void Split(int now, ll k) {
	int nw = build(k + 1, r(now), fil(now));
	r(now) = k, rs(nw) = rs(now), rs(now) = nw;
	tag(now) = -1, update(nw), update(now);
}

void Tag(int x, int fl) {
	rev(x) = 0;
	if (fl == 0) fil(x) = tag(x) = 0, m0(x) = ls(x) ? min(m0(ls(x)), m1(ls(x))) : l(x), m1(x) = inf;
	else fil(x) = tag(x) = 1, m1(x) = ls(x) ? min(m0(ls(x)), m1(ls(x))) : l(x), m0(x) = inf;
}

void Rev(int p) {
	fil(p) ^= 1;
	swap(m0(p), m1(p));
	if (tag(p) != -1) tag(p) ^= 1;
	else rev(p) ^= 1;
}

void spread(int p) {
	if (tag(p) != -1) {
		if (ls(p)) Tag(ls(p), tag(p));
		if (rs(p)) Tag(rs(p), tag(p));
	}
	if (rev(p)) {
		if (ls(p)) Rev(ls(p));
		if (rs(p)) Rev(rs(p));
	}
	tag(p) = -1, rev(p) = 0;
}

void split(int now, ll k, int &x, int &y) {
	if (!now) return x = y = 0, void();
	spread(now);
	if (r(now) <= k) x = now, split(rs(x), k, rs(x), y);
	else if (l(now) > k) y = now, split(ls(y), k, x, ls(y));
	else Split(now, k), x = now, split(rs(x), k, rs(x), y);
	update(now);
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (rnd(x) < rnd(y)) return spread(x), rs(x) = merge(rs(x), y), update(x), x;
	return spread(y), ls(y) = merge(x, ls(y)), update(y), y; 
}

int main() {
//	freopen ("hs.in","r",stdin);
//	freopen ("hs.out","w",stdout);
	rt = build(1, inf, 0);
	for (read(n); n; n--) {
		ll op, l, r;
		read(op), read(l), read(r);
		split(rt, l - 1, x, y);
		split(y, r, y, z);
		if (op == 1) Tag(y, 1);
		else if (op == 2) Tag(y, 0);
		else Rev(y);
		rt = merge(merge(x, y), z);
		write(m0(rt));
	}
	return 0;
}

/*

10
1 1 6
1 7 9
2 3 7
2 2 5
1 6 9
1 11 15
3 1 8
3 4 15
1 3 6
2 4 5
3 1 7




*/
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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 100500;
#define eb emplace_back
int a[N], lim, m, n;

struct node {
	ll ans;
	vector<int> L, R, li, ri;
}val[N<<2];

ll calc(int l, int r, vector<int> L, vector<int> R, vector<int> li, vector<int> ri) {
	int pre = l, lw = R.size() - 1, rw = 0;
	ll ans = 0;
	for ( ; lw >= 0; lw--) {
		while (rw < L.size() && (li[rw] | ri[lw]) < lim) rw++;
		if (rw >= L.size()) break;
		ans += (ll)(R[lw] - pre + 1) * (r - L[rw] + 1);
		pre = R[lw] + 1;
	}
	return ans;
}

node update(int l, int r, node Ls, node Rs) {
	node nw; nw.ans = 0;
	nw.L = Ls.L, nw.li = Ls.li, nw.R = Rs.R, nw.ri = Rs.ri; 
	int t = nw.li.back();
	for (int v: Rs.L) if ((a[v] | t) > t) 
		t |= a[v], nw.L.eb(v), nw.li.eb(t);
	t = nw.ri.back();
	for (int v: Ls.R) if ((a[v] | t) > t)
		t |= a[v], nw.R.eb(v), nw.ri.eb(t);
	nw.ans = calc(l, r, Rs.L, Ls.R, Rs.li, Ls.ri) + Ls.ans + Rs.ans;
	return nw;
}

#define ls p << 1
#define rs p << 1 | 1
void build(int p, int l, int r) {
	if (l == r) {
		val[p].L.eb(l), val[p].R.eb(l), val[p].li.eb(a[l]), val[p].ri.eb(a[l]);
		return val[p].ans = a[l] >= lim, void();
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	val[p] = update(l, r, val[ls], val[rs]);
}

void change(int p, int l, int r, int x) {
	if (l == r) {
		val[p].li.clear(), val[p].ri.clear();
		val[p].li.eb(a[l]), val[p].ri.eb(a[l]);
		return val[p].ans = a[l] >= lim, void();
	}
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x);
	else change(rs, mid + 1, r, x);
	val[p] = update(l, r, val[ls], val[rs]);
}

node query(int p, int l, int r, int lf, int rf) {
	if (lf <= l && r <= rf) return val[p];
	int mid = (l + r) >> 1;
	if (lf > mid) return query(rs, mid + 1, r, lf, rf);
	if (rf <= mid) return query(ls, l, mid, lf, rf);
	return update(max(l, lf), min(r, rf), query(ls, l, mid, lf, rf), query(rs, mid + 1, r, lf, rf));
}

int main() {
	read(n), read(m), read(lim);
	for (int i = 1;i <= n; i++) read(a[i]);
	build(1, 1, n);
	while (m--) {
		int op, x, y;
		read(op), read(x), read(y);
		if (op == 1) a[x] = y, change(1, 1, n, x);
		else write(query(1, 1, n, x, y).ans);
	}
	return 0;
}

/*
4 6 7
0 3 6 1
1 1 7
2 1 4
2 1 3
2 1 1
1 3 0
2 1 4

*/
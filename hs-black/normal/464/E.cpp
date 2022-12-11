
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#pragma GCC optimize(3, "inline")
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

const int P = 1e9 + 7;
const int Bas = 17;
const int len = 200000;
const int N = 400500;

int m, n;
int h[N], ne[N<<1], to[N<<1], w[N<<1], tot = 1;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}

#define ull unsigned ll
struct node {
	int tsum, ls, rs;
	ll hs; ull hs2;
	#define tsum(p) treenode[p].tsum
	#define hs2(p) treenode[p].hs2
	#define ls(p) treenode[p].ls
	#define rs(p) treenode[p].rs
	#define hs(p) treenode[p].hs
}treenode[N<<5];

ll B[N]; ull B2[N]; 
int T[N], t1, t2, cnt;

void update(int p, int len) {
	tsum(p) = tsum(rs(p)) + tsum(ls(p));
	hs2(p) = hs2(rs(p)) * B[len] + hs2(ls(p)) % P;
	hs(p) = (hs(rs(p)) * B[len] + hs(ls(p))) % P;
}

void build(int &p, int l, int r, int v) {
	p = ++cnt;
	if (l == r) return hs(p) = tsum(p) = v, hs2(p) = v + 5486, void();
	int mid = (l + r) >> 1;
	build(ls(p), l, mid, v), build(rs(p), mid + 1, r, v);
	update(p, mid - l + 1);
}

int query(int tx, int ty, int l, int r) {
	if (l == r) return hs(tx) < hs(ty);
	int mid = (l + r) >> 1;
	if (hs(rs(tx)) == hs(rs(ty)) && hs2(rs(tx)) == hs2(rs(ty)) && tsum(rs(tx)) == tsum(rs(ty)))
		return query(ls(tx), ls(ty), l, mid);
	return query(rs(tx), rs(ty), mid + 1, r);
}

struct ele {
	int T, x;
	ele(int t = 0, int xx = 0) : T(t), x(xx) {}
	bool operator < (const ele &i) const {
		return query(i.T, T, 1, len);
	}
};

int fl;

void Update(int &t, int t1, int t2, int pre, int l, int r) {
	if (fl) return ; t = ++cnt, treenode[t] = treenode[pre];
	if (tsum(t) == tsum(t2)) return treenode[t] = treenode[t1], void();
	if (l == r) return treenode[t] = treenode[t2], fl = 1, void();
	int mid = (l + r) >> 1;
	Update(ls(t), ls(t1), ls(t2), ls(pre), l, mid);
	Update(rs(t), rs(t1), rs(t2), rs(pre), mid + 1, r);
	update(t, mid - l + 1);
}

void update(int &t, int t1, int t2, int pre, int l, int r, int x) {
	if (fl) return ;
	t = ++cnt, treenode[t] = treenode[pre];
	if (l >= x) {
		if (tsum(t) == tsum(t2)) treenode[t] = treenode[t1];
		else Update(t, t1, t2, pre, l, r);
		return;
	}
	int mid = (l + r) >> 1; 
	if (x <= mid) update(ls(t), ls(t1), ls(t2), ls(pre), l, mid, x);
	update(rs(t), rs(t1), rs(t2), rs(pre), mid + 1, r, x);
	update(t, mid - l + 1);
}

void outit(int t, int l, int r, int L, int R) {
	if (l == r) return write(hs(t), ' ');
	int mid = (l + r) >> 1;
	if (L <= mid) outit(ls(t), l, mid, L, R);
	if (R > mid) outit(rs(t), mid + 1, r, L, R);
}

int mi[N];
priority_queue<ele> q;
int st[N], vis[N], pre[N], tp, s, t;
int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(m);
	for (int i = 1, x, y, z; i <= m; i++)
		read(x), read(y), read(z), add(x, y, z), add(y, x, z);
	read(s), read(t), B[0] = 1; B2[0] = 1;
	for (int i = 1;i <= len; i++) B[i] = B[i-1] * 2 % P, B2[i] = B2[i-1] * Bas;
	build(t1, 1, len, 0), build(t2, 1, len, 1);
	for (int i = 1;i <= n; i++) T[i] = i == s ? t1 : t2;
	q.push(ele(T[s], s));
	while (q.size()) {
		int x = q.top().x; q.pop();
		if (vis[x]) continue; vis[x] = 1;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; int t = 0; fl = 0;
			if (vis[y]) continue;
			update(t, t1, t2, T[x], 1, len, w[i] + 1);
			if (query(t, T[y], 1, len)) pre[y] = i ^ 1, T[y] = t, q.push(ele(T[y], y));
		}
	}
	if (T[t] == t2) return puts("-1"), 0;
	int x = t;
	while (x != s) st[++tp] = pre[x], x = to[pre[x]];
	write(hs(T[t])), write(tp + 1), write(s, ' ');
	for (int i = tp;i >= 1; i--) write(to[st[i] ^ 1], ' ');
	return 0;
}
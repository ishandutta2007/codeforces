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
int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

int ls[N<<5], rs[N<<5], mn[N<<5], T[N], L[N], R[N], num, cnt, n, m;

const int inf = 1e9;
int update(int pre, int l, int r, int x, int v) {
	int rt = ++cnt; 
	ls[rt] = ls[pre], rs[rt] = rs[pre];
	mn[rt] = min(mn[pre], v);
	if (l == r) return rt;
	int mid = (l + r) >> 1;
	if (x <= mid) ls[rt] = update(ls[pre], l, mid, x, v);
	else rs[rt] = update(rs[pre], mid + 1, r, x, v);
	return rt;
}

int query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return mn[p];
	int mid = (l + r) >> 1, tp = inf;
	if (L <= mid) Mn(tp, query(ls[p], l, mid, L, R));
	if (mid < R) Mn(tp, query(rs[p], mid + 1, r, L, R));
	return tp;
}

vector<int> v[N];
int val[N], dep[N], las, r;
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1, L[x] = ++num;
	v[dep[x]].push_back(x);
	for (int i = h[x]; i; i = ne[i]) 
		if (to[i] != fa) dfs(to[i], x);
	R[x] = num;
}

int main() {
	read(n), read(r); mn[0] = inf;
	for (int i = 1;i <= n; i++) read(val[i]);
	for (int i = 1, x, y;i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	dfs(r, 0);
	for (int i = 1;i <= n; i++, T[i] = T[i-1]) 
		for (auto g: v[i]) T[i] = update(T[i], 1, n, L[g], val[g]);
	read(m);
	while (m--) {
		int x, y; read(x), read(y);
		x = (x + las) % n + 1, y = (y + las) % n;
		write(las = query(T[min(dep[x] + y, n)], 1, n, L[x], R[x]));
	}
	return 0;
}
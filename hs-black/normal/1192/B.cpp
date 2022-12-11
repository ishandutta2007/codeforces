
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

const int N = 400500;
int n, q; ll val[N], lim;
int L[N], R[N], id[N], f[N], cnt;
int h[N], ne[N<<1], to[N<<1], tot; ll w[N<<1], dis[N];
inline void add(int x, int y, ll z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}
void dfs(int x, int fa) {
	id[L[x] = ++cnt] = x, f[x] = fa;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dis[y] = dis[x] + w[i];
		dfs(y, x), id[++cnt] = x;
	}
	R[x] = cnt;
}

#define ls p << 1
#define rs ls | 1
ll LM[N<<2], RM[N<<2], LMR[N<<2], W[N<<2], M[N<<2], Add[N<<2];
void Tag(int p, ll t) { Add[p] += t, LM[p] -= t, RM[p] -= t, M[p] -= 2 * t, W[p] += t; }
void spread(int p) { if (!Add[p]) return; Tag(ls, Add[p]), Tag(rs, Add[p]); Add[p] = 0; }
void update(int p) {
	W[p] = max(W[ls], W[rs]), M[p] = max(M[ls], M[rs]);
	LM[p] = max(LM[ls], LM[rs]), Mx(LM[p], W[ls] + M[rs]);
	RM[p] = max(RM[ls], RM[rs]), Mx(RM[p], W[rs] + M[ls]);
	LMR[p] = max(LMR[ls], LMR[rs]), Mx(LMR[p], max(LM[ls] + W[rs], RM[rs] + W[ls]));
}

void build(int p, int l, int r) {
	if (l == r) return W[p] = dis[id[l]], LM[p] = RM[p] = -dis[id[l]], M[p] = -2 * dis[id[l]], void();
	int mid = (l + r) >> 1; build(ls, l, mid), build(rs, mid + 1, r), update(p); 
}

void change(int p, int l, int r, int L, int R, ll t) {
	if (L <= l && r <= R) return Tag(p, t);
	int mid = (l + r) >> 1; spread(p);
	if (L <= mid) change(ls, l, mid, L, R, t);
	if (mid < R) change(rs, mid + 1, r, L, R, t);
	update(p);
}

ll las;
int main() {
	read(n), read(q), read(lim);
	for (int i = 1, x, y; i < n; i++)
		read(x), read(y), read(val[i]), add(x, y, val[i]), add(y, x, val[i]);
	dfs(1, 0); build(1, 1, cnt);
	for (int i = 1, op;i <= q; i++) {
		read(op); ll z; read(z);
		op = (op + las) % (n - 1) + 1;
		z = (z + las) % lim;
		ll t = z - val[op]; val[op] = z;
		int x = to[op * 2], y = to[op * 2 - 1];
		if (f[y] == x) swap(x, y);
		change(1, 1, cnt, L[x], R[x], t);
		write(las = LMR[1]);
	}
	return 0;
}
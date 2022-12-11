/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

const int N = 300500;
ll ans = 2;
int dfn[N], st[20][N<<1], lg[N<<1], num, n;
struct Au {
	int ch[N][26], f[N], len[N], cnt = 1, las = 1;
	int insert(int c) {
		int p = las, np = las = ++cnt; len[np] = len[p] + 1;
		for (; p && !ch[p][c]; p = f[p]) ch[p][c] = np;
		if (!p) return f[np] = 1, las;
		int q = ch[p][c]; if (len[q] == len[p] + 1) return f[np] = q, las;
		int nq = ++cnt; f[nq] = f[q], memcpy(ch[nq], ch[q], sizeof(ch[q]));
		f[q] = f[np] = nq, len[nq] = len[p] + 1;
		for (; ch[p][c] == q; p = f[p]) ch[p][c] = nq;
		return las;
	}
	void dfs(int x) {
		st[0][dfn[x] = ++num] = len[x];
		for (int i = h[x]; i; i = ne[i]) 
			dfs(to[i]), st[0][++num] = len[x];
	}
	int h[N], ne[N<<1], to[N<<1], tot;
	inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
	inline void Addedges(void) { for (int i = 2;i <= cnt; ++i) add(f[i], i); }
	void prework(void) {
		Addedges(), dfs(1);
		for (int i = 2;i <= num; ++i) lg[i] = lg[i >> 1] + 1;
		for (int i = 1;i <= 19; ++i) 
			for (int j = 1;j + (1 << i) - 1 <= num; ++j) 
				st[i][j] = min(st[i-1][j], st[i-1][j + (1 << i - 1)]);
	}
	inline int dep(int x, int y) {
		int t = lg[y - x + 1];
		return min(st[t][x], st[t][y - (1 << t) + 1]);
	}
	inline void Ans(void) { 
		for (int i = 1;i <= cnt; ++i) 
			ans += len[i] - len[f[i]];
	}
}A, B;

int ls[N<<5], rs[N<<5], L[N<<5], R[N<<5], cnt; ll sum[N << 5];
void update(int p) {
	sum[p] = sum[ls[p]] + sum[rs[p]] - (ls[p] && rs[p] ? B.dep(R[ls[p]], L[rs[p]]) : 0);
	L[p] = ls[p] ? L[ls[p]] : L[rs[p]];
	R[p] = rs[p] ? R[rs[p]] : R[ls[p]];
}

void insert(int &p, int l, int r, int x) {
	if (!p) p = ++cnt;
	if (l == r) return sum[p] = st[0][x], L[p] = R[p] = x, void();
	int mid = (l + r) >> 1;
	if (x <= mid) insert(ls[p], l, mid, x);
	else insert(rs[p], mid + 1, r, x);
	update(p);
//	write(L[p], ' '), write(R[p]);
}

int merge(int l, int r, int x, int y) {
	if (!x || !y) return x | y;
	if (l == r) return x;
	int mid = (l + r) >> 1;
	ls[x] = merge(l, mid, ls[x], ls[y]);
	rs[x] = merge(mid + 1, r, rs[x], rs[y]);
	return update(x), x;
}

int ed[N], col[N], rt[N];
void dfs(int x) {
//	write(x);
	if (col[x]) insert(rt[x], 1, num, dfn[ed[col[x] + 2]]);
	for (int i = A.h[x]; i; i = A.ne[i]) {
		dfs(A.to[i]);
		rt[x] = merge(1, num, rt[x], rt[A.to[i]]);
	}
//	write(x);
	ans += 1ll * (A.len[x] - A.len[A.f[x]]) * sum[rt[x]]; 
}

char s[N];
int main() {
//	freopen ("hs.in","r",stdin);
	scanf ("%s", s + 1), n = strlen(s + 1);
	if (n == 1) return write(3), 0;
	for (int i = 1;i < n - 1; ++i) col[A.insert(s[i] - 'a')] = i;
	A.insert(s[n - 1] - 'a'), A.Ans(), A.insert(s[n] - 'a'), A.Ans();
	for (int i = n;i > 1; --i) ed[i] = B.insert(s[i] - 'a');
	B.Ans(), ed[1] = B.insert(s[1] - 'a');
	B.prework(), A.Addedges(), dfs(1), write(ans);
	return 0;
}
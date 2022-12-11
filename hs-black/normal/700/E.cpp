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

const int N = 400050; 
int ne[N<<1], to[N<<1], h[N], tot;
inline void adde(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }

int ls[N<<5], rs[N<<5], siz[N<<5], rt[N], cnt = 1, T;
int merge(int x, int y) {
	if (!x || !y) return x | y;
	int rt = ++T;
	ls[rt] = merge(ls[x], ls[y]);
	rs[rt] = merge(rs[x], rs[y]);
	siz[rt] = siz[x] + siz[y];
	return rt;
}

void change(int &p, int l, int r, int t) {
	p = ++T; siz[p] = 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (t <= mid) change(ls[p], l, mid, t);
	else change(rs[p], mid + 1, r, t);
}

int pos[N], f[N], len[N], ch[N][26];
int dp[N], ans, n, las = 1;
char s[N];
void dfs(int x) {
	for (int i = h[x], y; i; pos[x] = pos[y], i = ne[i]) 
		dfs(y = to[i]), rt[x] = merge(rt[x], rt[y]);
}

void insert(int c, int t) {
	int p = las, np = las = ++cnt;
	len[np] = len[p] + 1, change(rt[np], 1, n, t), pos[np] = t;
	for (; p && !ch[p][c]; p = f[p]) ch[p][c] = np;
	if (!p) return f[np] = 1, void();
	int q = ch[p][c];
	if (len[p] + 1 == len[q]) return f[np] = q, void();
	int nq = ++cnt; memcpy(ch[nq], ch[q], sizeof(ch[q]));
	len[nq] = len[p] + 1, f[nq] = f[q], f[q] = f[np] = nq;
	for (; ch[p][c] == q; p = f[p]) ch[p][c] = nq;	
}

int query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return siz[p];
	int mid = (l + r) >> 1, res = 0;
	if (L <= mid) res += query(ls[p], l, mid, L, R);
	if (R > mid) res += query(rs[p], mid + 1, r, L, R);
	return res;
}

void dfs2(int x, int mx = 1) {
//	write(x);
	if (mx == 1) dp[mx = x] = 1;
	else if (query(rt[mx], 1, n, pos[x] - len[x] + len[mx], pos[x] - 1)) 
		dp[x] = dp[mx] + 1, mx = x;
	Mx(ans, dp[x]); 
	for (int i = h[x]; i; i = ne[i])
		dfs2(to[i], mx);
}

int main() {
	read(n), scanf ("%s", s + 1);
	for (int i = 1;i <= n; ++i) insert(s[i] - 'a', i);
	for (int i = 2;i <= cnt; ++i) adde(f[i], i);
	dfs(1);
	for (int i = h[1]; i; i = ne[i]) dfs2(to[i], 1);
	write(ans);
	return 0;
}
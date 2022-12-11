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
inline void Mx(T &x, T y) { x < y && (x = y, 0); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 1000500;
char s[N];
int f[N], T[N], las = 1, cnt = 1, tot;
int ls[N<<4], rs[N<<4], pos[N], m, n;
pair<int, int> mx[N<<4]; 
void update(int &p, int l, int r, int x) {
	p = ++tot; mx[p] = MP(1, -x);
	if (l == r) return;
	int mid = (l + r) >> 1;
	x <= mid ? update(ls[p], l, mid, x) : update(rs[p], mid + 1, r, x);
}

int merge(int x, int y, int l, int r) {
	if (!x || !y) return x | y;
	int p = ++tot;
	if (l == r) {
		mx[p] = MP(mx[x].fi + mx[y].fi, mx[x].se);
		return p;
	}
	int mid = (l + r) >> 1;
	ls[p] = merge(ls[x], ls[y], l, mid);
	rs[p] = merge(rs[x], rs[y], mid + 1, r);
	mx[p] = max(mx[ls[p]], mx[rs[p]]);
	return p;
}

pair<int, int> query(int p, int l, int r, int L, int R) {
	if (!p || (L <= l && r <= R)) return mx[p];
	int mid = (l + r) >> 1;
	pair<int, int> t(0, 0);
	if (L <= mid) Mx(t, query(ls[p], l, mid, L, R));
	if (mid < R) Mx(t, query(rs[p], mid + 1, r, L, R));
	return t;
}

int len[N], ch[N][26];
void add(int c, int k) {
	int p = las, np = las = ++cnt; len[np] = len[p] + 1;
	update(T[np], 1, m, k);
	for (; p && !ch[p][c]; p = f[p]) ch[p][c] = np;
	if (!p) return f[np] = 1, void();
	int q = ch[p][c];
	if (len[q] == len[p] + 1) return f[np] = q, void();
	int nq = ++cnt; f[nq] = f[q], len[nq] = len[p] + 1;
	memcpy(ch[nq], ch[q], sizeof(ch[q])), f[np] = f[q] = nq;
	for (; ch[p][c] == q; p = f[p]) ch[p][c] = nq;
}

int h[N], ne[N<<1], to[N<<1], qaq;
void adde(int x, int y) {
	ne[++qaq] = h[x], to[h[x] = qaq] = y;
}

int g[N][17], pl[N];
void dfs(int x) {
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; g[y][0] = x;
		for (int j = 1;j < 17; j++)
			g[y][j] = g[g[y][j-1]][j-1];
		dfs(y), T[x] = merge(T[x], T[y], 1, m);
	}
//	write(T[x]);
}

char t[N];
int main() {
	scanf ("%s", s + 1), n = strlen(s + 1), read(m);
	for (int i = 1;i <= m; i++) {
		scanf ("%s", t + 1), las = 1;
		int len = strlen(t + 1); 
		for (int j = 1;j <= len; j++) 
			add(t[j] - 'a', i);
	}
	int p = 1, res = 0;
	for (int i = 1;i <= n; i++) {
		int c = s[i] - 'a';
		while (p && !ch[p][c]) p = f[p], res = len[p];
		p = ch[p][c];
		if (p) res++;
		else p = 1, res = 0;
		pos[i] = p, pl[i] = res;
	}
//	for (int i = 1;i <= cnt; i++) write(T[i]);
	for (int i = 2;i <= cnt; i++) adde(f[i], i);
	n = m, dfs(1), read(m);
//	write(tot);
	while (m--) {
		int a, b, c, d;
		read(a), read(b), read(c), read(d);
		int p = pos[d], L = d - c + 1;
		if (L > pl[d]) { printf ("%d 0\n", a); continue; }
		for (int i = 16;i >= 0; i--)
			if (len[g[p][i]] >= L) p = g[p][i];
//		write(p);
//		write(p), write(Len[p]);
//		if (len[p] < L) {  }
		pair<int, int> t = query(T[p], 1, n, a, b);
		if (!t.fi) printf ("%d %d\n", a, 0);
		else printf ("%d %d\n", -t.se, t.fi);
	}
	return 0;
}

/*

fhadkslfhajskdhbg
5
hdakghdaklfjassdgvadsf
fdafadsukjghdks
afdashogfhdsi
aefhasodgh
adfadsovghiahgoi
1
1 5 3 4

2 5 3 6
1 5 3 3
1 4 2 5
1 5 3 6
2 4 5 6
2 3 6 9
1 4 5 9
1 5 10 14 
 
*/
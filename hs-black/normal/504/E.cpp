#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define re register
#define uint unsigned int
#define ll long long
#define MP make_pair
#define Pa pair<ll, ll>
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

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int P = 1e9+7;
const int N = 300050;
int dfn[N], id[N], ans, num;
int siz[N], dep[N], f[N];
int Top[N], son[N], q, n;
char s[N];
Pa B = MP(131, 13331), bas[N];
Pa hs[N], rhs[N];

#define I inline
#define O operator

I ll add (ll x, ll y) { return (x += y) >= P ? x - P : x; }
I ll sub (ll x, ll y) { return (x -= y) >= 0 ? x : x + P; }
I Pa O + (Pa a, ll b) { return MP(add(a.fi, b), add(a.se, b)); }
I Pa O + (Pa a, Pa b) { return MP(add(a.fi, b.fi), add(a.se, b.se)); }
I Pa O - (Pa a, Pa b) { return MP(sub(a.fi, b.fi), sub(a.se, b.se)); }
I Pa O * (Pa a, Pa b) { return MP(a.fi * b.fi % P, a.se * b.se % P); }
I Pa rH(int l, int r) { return rhs[l] - (rhs[r+1] * bas[r - l + 1]); }
I Pa H (int l, int r) { return hs[r] - (hs[l-1] * bas[r - l + 1]); }

vector<int> ed[N];
void dfs1(int x, int fa) {
	dep[x] = dep[f[x] = fa] + (siz[x] = 1);
	for (auto y: ed[x]) {
		if (y == fa) continue;
		dfs1(y, x), siz[x] += siz[y];
		if (siz[y] > siz[son[x]]) son[x] = y;
	}
}

void dfs2(int x, int topf) {
	Top[x] = topf, id[dfn[x] = ++num] = x;
	if (!son[x]) return; dfs2(son[x], topf);
	for (auto y: ed[x]) if (y^f[x]&&y^son[x]) dfs2(y, y);
}

inline int Lca(int x, int y) {
	while (Top[x] != Top[y]) {
		if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
		x = f[Top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

void get(vector <Pa> &a, int x, int y) {
	a.clear(); vector <Pa> b;
	while (Top[x] != Top[y]) {
		if (dep[Top[x]] < dep[Top[y]]) 
			b.push_back(MP(Top[y], y)), y = f[Top[y]];
		else a.push_back(MP(x, Top[x])), x = f[Top[x]];
	}
	if (dep[x] > dep[y]) a.push_back(MP(x, y));
	else b.push_back(MP(x, y));
	for (int i = b.size() - 1;i >= 0; i--) a.push_back(b[i]);
}


vector<Pa> r1, r2;
int main() {
	read(n); scanf ("%s", s + 1);
	for (int i = 1;i < n; i++) {
		int x, y; read(x), read(y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	} dfs1(1, 0), dfs2(1, 1); bas[0] = MP(1, 1);
	for (int i = 1;i <= n; i++)
		bas[i] = bas[i-1] * B, 
		hs[i] = hs[i-1] * B + s[id[i]], 
		rhs[n-i+1] = rhs[n-i+2] * B + s[id[n-i+1]];
	read(q);
	while (q--) {
		int a, b, c, d; uint s = 0, t = 0;
		read(a), read(b), read(c), read(d);
		get(r1, a, b), get(r2, c, d); ans = 0;
		while (s < r1.size() && t < r2.size()) {
			a = dfn[r1[s].fi], b = dfn[r1[s].se];
			c = dfn[r2[t].fi], d = dfn[r2[t].se];
			bool rL = b > a, rR = d > c;
			int L1 = (rL ? b - a : a - b) + 1;
			int L2 = (rR ? d - c : c - d) + 1;
			int len = min(L1, L2);
			int R1 = rL ? a + len - 1 : a - len + 1;
			int R2 = rR ? c + len - 1 : c - len + 1;
			Pa H1 = rL ? rH(a, R1) : H(R1, a);
			Pa H2 = rR ? rH(c, R2) : H(R2, c);
			if (H1 == H2) {
				L1 == len ? s++ : r1[s].fi = id[R1 + (rL ? 1 : -1)];
				L2 == len ? t++ : r2[t].fi = id[R2 + (rR ? 1 : -1)];
				ans += len; continue;
			}
			int L = 1, R = len;
			while (L <= R) {
				int mid = (L + R) >> 1;
				R1 = rL ? a + mid - 1 : a - mid + 1;
				R2 = rR ? c + mid - 1 : c - mid + 1;
				H1 = rL ? rH(a, R1) : H(R1, a);
				H2 = rR ? rH(c, R2) : H(R2, c);
				if (H1 == H2) L = mid + 1;
				else R = mid - 1;
			}
			ans += R; break;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
/*
6
bbbabb
2 1
3 2
4 3
5 2
6 5
6
5 5 5 5

*/
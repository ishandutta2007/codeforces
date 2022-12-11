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

const int N = 200500;
const int inf = 1e8;
int ne[N<<1], to[N<<1], w[N<<1], h[N], c[N], tot;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}

int L, R, S, T, V;
int siz[N], vis[N], Siz, lim, rt, s, t, n, m;
void get(int x, int fa) {
	siz[x] = 1; int mx = 0; 
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (vis[y] || y == fa) continue;
		get(y, x), siz[x] += siz[y], Mx(mx, siz[y]);
	}
	Mx(mx, Siz - siz[x]);
	if (mx < lim) rt = x, lim = mx;
}

struct node {
	int a, b;
}st[N];

bool cmp(node a, node b) {
	return siz[a.a] < siz[b.a];
}

int que[N], tmp[N], seq[N], sx[N], sqx[N], dep, tp, nw;
void dfs(int x, int fa, int dp, int s, int F) {
	if (tmp[dp] < s) tmp[dp] = s, sx[dp] = x; Mx(dep, dp);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa || vis[y]) continue;
		dfs(y, x, dp + 1, s + (w[i] >= F ? 1 : -1), F);  
	}
}

bool check(int x, int F) {
	seq[nw = 0] = 0, sqx[0] = x;
	for (int a = 1;a <= tp; a++) {
		int y = st[a].a; 
		for (int i = 1;i <= siz[y]; i++) tmp[i] = -inf;
		dep = 0, dfs(y, x, 1, st[a].b >= F ? 1 : -1, F);
		int l = 0, r = -1, rb = nw;
		for (int i = 1;i <= dep; i++) {
			while (rb >= 0 && i + rb >= L) {
				while (l <= r && seq[que[r]] <= seq[rb]) r--;
				que[++r] = rb, rb--;
			}
			while (l <= r && que[l] + i > R) l++;
			if (l <= r && seq[que[l]] + tmp[i] >= 0) 
				return s = sqx[que[l]], t = sx[i], 1;
		}
		while (nw < dep) nw++, seq[nw] = -inf;
		for (int i = 1;i <= dep; i++)
			tmp[i] > seq[i] && (seq[i] = tmp[i], sqx[i] = sx[i]);
	}
	return 0;
}

void solve(int x) {
	vis[x] = 1, get(x, 0), tp = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (vis[y]) continue;
		st[++tp] = (node){y, w[i]};
	}
	sort(st + 1, st + tp + 1, cmp);
	int l = V + 1, r = m; s = t = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(x, c[mid])) l = mid + 1;
		else r = mid - 1;
	}
	if (r > V) check(x, c[r]), V = r, S = s, T = t;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (vis[y]) continue;
		lim = Siz = siz[y], rt = y, get(y, 0), solve(rt);
	}
}

int main() {
	read(n), read(L), read(R);
	for (int i = 1, x, y, w;i < n; i++)
		read(x), read(y), read(w), add(x, y, w), add(y, x, w), c[i] = w;
	sort(c + 1, c + n), m = unique(c + 1, c + n) - c - 1;
	rt = lim = Siz = n, get(1, 0), solve(rt);
	printf ("%d %d\n", S, T);
	return 0;
}
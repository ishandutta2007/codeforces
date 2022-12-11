
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

const int N = 500050;

int c[N], col[N], f[N], fl;
struct node { 
	int x, y;
	bool operator < (const node &i) const {
		return c[x] == c[i.x] ? c[y] < c[i.y] : c[x] < c[i.x];
	}
}ed[N];

int ne[N<<1], to[N<<1], h[N], tot, m, n, k;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

void dfs(int x, int &f2, int &f1) {
	if (col[x] == 1){
		if (!f1) f1 = x;
		f[x] = f1;
	}
	if (col[x] == 2){
		if (!f2) f2 = x;
		f[x] = f2;
	}
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (fl) return;
		if (col[y]) {
			if (col[y] != 3 - col[x]) { fl = 1; return; }
		}
		else col[y] = 3 - col[x], dfs(y, f2, f1);
	}
}

vector<int> v[N];
int vis[N], cnt;
void check(int x, int tim) {
	vis[x] = tim;
	for (auto y: v[x]) {
		if (fl) return;
		if (vis[y] == tim) {
			if (col[y] != 3 - col[x]) {
				fl = 1; return;
			}
			continue;
		}
		col[y] = 3 - col[x];
		check(y, tim);
	}
}

int ban[N];
int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(m), read(k);
	for (int i = 1;i <= n; i++) read(c[i]);
	for (int i = 1, x, y;i <= m; i++) {
		read(x), read(y);
		if (c[x] == c[y]) add(x, y), add(y, x);
		else {
			if (c[x] > c[y]) swap(x, y);
			ed[++cnt] = (node) {x, y};
		}
	}
	ll ans = k;
	for (int i = 1;i <= n; i++) f[i] = i;
	for (int i = 1;i <= n; i++) {
		if (!col[i] && !ban[c[i]]) {
			int f1 = 0, f2 = 0;
			col[i] = 1; fl = 0; dfs(i, f2, f1);
			if (fl) ban[c[i]] = 1, ans--;
			if (f1 && f2) {
				v[f1].push_back(f2), v[f2].push_back(f1);
			}
		}
	}
	sort(ed + 1, ed + cnt + 1);
	ans = ans * (ans - 1) / 2;
	int tim = 0;
	for (int l = 1, r = 1;l <= cnt; l = r + 1, r = l) {
		while (r <= cnt && c[ed[r+1].x] == c[ed[l].x] && c[ed[r+1].y] == c[ed[l].y]) r++;
		if (ban[c[ed[l].x]] || ban[c[ed[l].y]]) continue;
		for (int i = l;i <= r; i++) {
			int x = ed[i].x, y = ed[i].y;
			v[f[x]].push_back(f[y]), v[f[y]].push_back(f[x]); 
		}
		tim++;
		for (int i = l;i <= r; i++) {
			int x = f[ed[i].x];
			fl = 0;
			if (vis[x] != tim) col[x] = 1, check(x, tim);
			if (fl) break;
		}
		if (fl) ans--;
		for (int i = l;i <= r; i++) {
			int x = ed[i].x, y = ed[i].y;
			v[f[x]].pop_back(), v[f[y]].pop_back();
		}
	}
	write(ans);
	return 0;
}
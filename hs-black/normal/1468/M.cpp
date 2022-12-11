
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

const int N = 605000;
#include <map>
map<int, int> mp;
int vis[N], ans1, ans2, cnt, T, n;
vector<int> v[N];

int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

inline bool solve(int x) {
	for (int t: v[x]) {	
		for (int i = h[t]; i; i = ne[i]) {
			int y = to[i];
			if (y == x) continue;
			if (vis[y]) {
				if (t <= n) ans2 = ans1, ans1 = t;
				if (x <= n) ans2 = ans1, ans1 = x;
				if (vis[y] <= n) ans2 = ans1, ans1 = vis[y];
				if (y <= n) ans2 = ans1, ans1 = y;
				return 1;
			}
			vis[y] = t;
		}
	}
	for (auto t: v[x])
	for (int i = h[t]; i; i = ne[i]) vis[to[i]] = 0;
	return 0;
}

struct node {
	int x, y;
}ed[N];

int deg[N], t;
int main() {
	for (read(T); T; T--) {
		read(n), cnt = n, mp.clear(), t = 0;
		for (int i = 1, k, x; i <= n; i++) {
			read(k);
			for (int j = 1;j <= k; j++) {
				read(x);
				if (!mp.count(x)) mp[x] = ++cnt;
				int tp = mp[x]; 
				deg[tp]++, deg[i]++;
				ed[++t] = (node) {tp, i};
			}
		}
		for (int i = 1;i <= cnt; i++) v[i].clear();
		for (int i = 1; i <= t; i++) {
			int x = ed[i].x, y = ed[i].y;
			if (deg[x] < deg[y]) swap(x, y);
			v[x].push_back(y), add(x, y), add(y, x);
		}
		int fl = 0;
		for (int i = 1;i <= cnt; i++) 
			if (solve(i)) { fl = 1; break; }
		memset(h, 0, cnt * 4 + 20);
		memset(vis, 0, cnt * 4 + 20);
		memset(deg, 0, cnt * 4 + 20);
		if (!fl) { write(-1); continue; }
		write(ans1, ' '), write(ans2);
	}
	return 0;
}
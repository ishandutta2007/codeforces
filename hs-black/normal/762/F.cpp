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

const int P = 1e9+7;
const int N = 1050;
int f[N][13][4100], ne[N<<1], to[N<<1], h[N], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

ll ans;
int ed[20][20], st[N], tp, all, m, n;
void dfs(int x, int fa) {
	for (int i = 1;i <= m; i++) f[x][i][1 << i - 1] = 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs(y, x);
		for (int a = 1;a <= m; a++) {
			static int g[4100]; 
			for (int i = 1;i <= all; i++) g[i] = f[x][a][i];
			for (int b = 1;b <= m; b++) {
				if (!ed[a][b]) continue;
				for (int id = 1;id <= tp; id++) {
					int t = st[id]; if (!f[y][b][t]) continue;
					int res = all ^ t;
					for (int s = res; s; s = (s - 1) & res)
						f[x][a][s ^ t] = (f[x][a][s ^ t] + 1ll * g[s] * f[y][b][t]) % P;
				}
//				for (int s = all; s; s--) {
//					for (int t = s; t; t = (t - 1) & s)
//						f[x][a][s] = (f[x][a][s] + 1ll * g[s ^ t] * f[y][b][t]) % P;
//				}
			}
		}
	}
	for (int i = 1;i <= m; i++)
		ans += f[x][i][all];
}

vector<int> vec[N];
namespace Deal {
	ll fpw(ll x, ll mi) {
		ll res = 1;
		for (; mi; mi >>= 1, x = x * x % P)
			if (mi & 1) res = res * x % P;
		return res;
	}
	ll f[13][13][4100], ans;
	void dfs(int x, int fa) {
		for (int i = 1;i <= m; i++) f[x][i][1 << i - 1] = 1;
		for (auto y: vec[x]) if (y != fa) {
			dfs(y, x);
			for (int a = 1;a <= m; a++) {
				static int g[4100]; 
				for (int i = 1;i <= all; i++) g[i] = f[x][a][i];
				for (int b = 1;b <= m; b++) {
					if (!ed[a][b]) continue;
					for (int id = 1;id <= tp; id++) {
						int t = st[id]; if (!f[y][b][t]) continue;
						int res = all ^ t;
						for (int s = res; s; s = (s - 1) & res)
							f[x][a][s ^ t] = (f[x][a][s ^ t] + 1ll * g[s] * f[y][b][t]) % P;
					}
				}
			}
		}
		for (int i = 1;i <= m; i++) ans += f[x][i][all];
	}
	inline ll Inv() { return dfs(1, 0), fpw(ans % P, P - 2); }
	inline int S(int x, int fa) {
		int s = 1 << (x - 1);
		for (auto t: vec[x]) 
			if (t != fa) s |= S(t, x);
		return s;
	}
	void prework() {
		for (int i = 1;i <= m; i++) {
			for (auto t: vec[i]) 
				st[++tp] = all ^ S(t, i);
		}
	}
}

using Deal::Inv; 
using Deal::prework;

int main() {
	read(n);
	for (int i = 1, x, y;i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	read(m); all = (1 << m) - 1;
	for (int i = 1, x, y;i < m; i++)
		read(x), read(y), ed[x][y] = ed[y][x] = 1, vec[x].push_back(y), vec[y].push_back(x);
	prework(), dfs(1, 0), write(ans % P * Inv() % P);
	return 0;
}

/*

9
2 4
5 2
1 8
4 8
9 3
3 5
7 9
2 6
5
2 3
1 3
5 1
4 1

4
1 2
2 3
3 4
3
1 2
2 3

*/
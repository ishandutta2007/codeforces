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

const int N = 100050, M = 1000500;
vector<int> v[N], V[N], id[N];
vector<char> S[N];
int rx[N], ry[N], m, n, cnt, tot = 1, s, t, tim, T;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
inline bool legal(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
int cur[M], h[M], dep[M], ne[M], to[M], w[M];
void clear() {
	memset(h, 0, cnt * 4 + 20);
	memset(rx, 0, cnt * 4 + 20);
	memset(ry, 0, cnt * 4 + 20);
	cnt = 0, tot = 1;
}
namespace Flows {
	inline void add(int x, int y, int z) { ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z; }
	inline void adde(int x, int y, int z) { add(x, y, z), add(y, x, 0); }
	int dfs(int x, int lim) {
		if (!lim || x == t) return lim;
		int res = 0, fl;
		for (int &i = cur[x], y; i; i = ne[i]) {
			if (dep[y = to[i]] != dep[x] + 1 || !w[i]) continue;
			fl = dfs(y, min(lim, w[i]));
			lim -= fl, res += fl;
			w[i] -= fl, w[i^1] += fl;
			if (!lim) return res;
		}
		return res;
	}
	queue<int> q;
	bool bfs(void) {
		memset(dep, 0, cnt * 4 + 20);
		dep[s] = 1, q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int i = h[x], y; i; i = ne[i]) 
				if (!dep[y = to[i]] && w[i]) dep[y] = dep[x] + 1, q.push(y);
		}
		if (!dep[t]) return 0;
		memcpy(cur, h, cnt * 4 + 20);
		return 1;
	}
	int flow(void) {
		int ans = 0;
		while (bfs()) ans += dfs(s, 1e9);
		return ans;
	}
}
using Flows::adde;
using Flows::flow;

int main() {
	for (read(T); T; T--) {
		read(n), read(m), clear(); int nd = 0;
		for (int i = 1;i <= n; ++i)
			v[i].resize(m + 2), id[i].resize(m + 2), S[i].resize(m + 2), V[i].clear(), V[i].resize(m + 2);
		for (int i = 1;i <= n; ++i) 
			for (int j = 1;j <= m; ++j) 
				read(v[i][j]), id[i][j] = ++cnt, rx[cnt] = i, ry[cnt] = j, S[i][j] = 0;
		s = ++cnt, t = ++cnt;
		int ss = ++cnt, tt = ++cnt, ts = 0, ttt = 0;
		for (int i = 1;i <= n; ++i) 
			for (int j = 1;j <= m; ++j) {
				int fl1 = (i + j) & 1, fl2 = 0;
				for (int k = 0;k < 4; ++k) {
					int tx = i + dx[k], ty = j + dy[k];
					if (legal(tx, ty)) {
						if (v[i][j] == v[tx][ty]) { if (fl1) adde(id[i][j], id[tx][ty], 1); }
						else if (v[i][j] > v[tx][ty]) fl2 = 1;
					}
				}
				if (fl1) adde(fl2 ? s : (ts++, ss), id[i][j], 1);
				else adde(id[i][j], fl2 ? t : (ttt++, tt), 1);
				nd += !fl2;
			}
		adde(s, tt, ts), adde(ss, t, ttt);
		adde(t, s, 1e7), swap(s, ss), swap(t, tt);
		ll ans = flow();
		if (ans != nd) { puts("NO"); continue; }
		for (int i = 2;i <= tot; i += 2) {
			int x = to[i], y = to[i ^ 1];
			if (w[i] || !rx[x] || !rx[y]) continue;
			if (rx[x] != rx[y]) {
				if (rx[x] > rx[y]) swap(x, y);
				S[rx[x]][ry[x]] = 'D', S[rx[y]][ry[y]] = 'U';
				V[rx[x]][ry[x]] = 1, V[rx[y]][ry[y]] = v[rx[x]][ry[x]] - 1;
			} else {
				if (ry[x] > ry[y]) swap(x, y);
				S[rx[x]][ry[x]] = 'R', S[rx[y]][ry[y]] = 'L';
				V[rx[x]][ry[x]] = 1, V[rx[y]][ry[y]] = v[rx[x]][ry[x]] - 1;
			}
		}
		for (int i = 1;i <= n; ++i)
			for (int j = 1;j <= m; ++j) if (!V[i][j]) {
				for (int k = 0;k < 4; ++k) {
					int tx = i + dx[k], ty = j + dy[k];
					if (!legal(tx, ty)) continue;
					if (v[tx][ty] < v[i][j]) {
						V[i][j] = v[i][j] - v[tx][ty];
						S[i][j] = "DURL"[k];
						break;
					}
				}
			}
		puts("YES");
		for (int i = 1;i <= n; ++i) 
			for (int j = 1;j <= m; ++j) 
				write(V[i][j], " \n"[j == m]);
		for (int i = 1;i <= n; ++i) 
			for (int j = 1;j <= m; ++j) 
				putchar(S[i][j]), putchar(" \n"[j == m]);
	}
	return 0;
}

/*

3
1 5
2 2 3 2 2

*/
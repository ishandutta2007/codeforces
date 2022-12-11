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

namespace Flows {
	const int M = 2005500;
	int cur[M], h[M], dep[M], ne[M], to[M], cnt, s, t, tot = 1;
	ll w[M];
	inline void add(int x, int y, ll z) { ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z; }
	inline void adde(int x, int y, ll z) { add(x, y, z), add(y, x, 0); }
	ll dfs(int x, ll lim) {
		if (!lim || x == t) return lim;
		ll res = 0, fl;
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
	inline void del(int x) { 
		h[x] = ne[h[x]]; 
	}
	int flow(void) {
		int ans = 0;
		while (bfs()) ans += dfs(s, 1e15);
		return ans;
	}
}
using Flows::cnt;
using Flows::adde;
using Flows::s;
using Flows::t;
using Flows::flow;
using Flows::del;
const int N = 405000;
struct node {
	int c, up, dw;
}c1[N], c2[N];
int c[N], tt, m, n, rc, bc, x[N], y[N];
void update(node &x, int d) {
	int L = (x.c - d + 1) >> 1, R = (x.c + d) >> 1;
	if (L > R) { write(-1), exit(0); }
	Mx(x.dw, L), Mn(x.up, R);
}

ll deg[N];
int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(m), read(rc), read(bc);
	char r = 'r', b = 'b';
	if (rc > bc) swap(rc, bc), swap(r, b);
	for (int i = 1;i <= n; ++i) 
		read(x[i]), read(y[i]), c[++tt] = x[i], c[++tt] = y[i];
	sort(c + 1, c + tt + 1), tt = unique(c + 1, c + tt + 1) - c - 1;
	for (int i = 1;i <= n; ++i) {
		x[i] = lower_bound(c + 1, c + tt + 1, x[i]) - c;
		y[i] = lower_bound(c + 1, c + tt + 1, y[i]) - c;
		c1[x[i]].c++, c2[y[i]].c++;
	}
	for (int i = 1;i <= tt; ++i) c1[i].up = c2[i].up = 1e9;
	for (int i = 1, op, x, d;i <= m; ++i) {
		read(op), read(x), read(d);
		int k = lower_bound(c + 1, c + tt + 1, x) - c;
		if (c[k] != x) continue;
		if (op == 1) update(c1[k], d);
		else update(c2[k], d);
	}
	int nd = 0, ss, ttt;
	cnt = 2 * tt, s = ++cnt, t = ++cnt, ss = ++cnt, ttt = ++cnt;
	for (int i = 1;i <= n; ++i) 
		adde(x[i], y[i] + tt, 1);
	ll Sc = 0, Tc = 0;
	for (int i = 1;i <= tt; ++i) {
		int t1 = c1[i].up - c1[i].dw;
		int t2 = c2[i].up - c2[i].dw;
		adde(s, i, t1), adde(i + tt, t, t2);
		int d1 = c1[i].dw, d2 = c2[i].dw;
		Sc += d1, Tc += d2, nd += d1 + d2;
		adde(ss, i, d1), adde(i + tt, ttt, d2);
	}
	adde(ss, t, Tc), adde(s, ttt, Sc);
	adde(t, s, 1e9); int S = s, T = t;
	s = ss, t = ttt; int res = flow();
	if (res != nd) return write(-1), 0;
	int tp = Flows::w[Flows::tot];
	s = S, t = T, del(s), del(t), del(s), del(t);
	tp += flow();
	write(1ll * tp * rc + 1ll * (n - tp) * bc);
	Flows::tot = 1;
	for (int i = 1;i <= n; ++i) {
		Flows::tot += 2;
		putchar(Flows::w[Flows::tot] ? r : b);
	}
	return 0;
}
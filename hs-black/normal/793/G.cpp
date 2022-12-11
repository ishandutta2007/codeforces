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
	int cur[M], h[M], dep[M], ne[M], to[M], w[M], cnt, s, t, tot = 1;
	inline void add(int x, int y, int z) { ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z; }
	inline void adde(int x, int y, int z) { 
//	write(x, ' '), write(y); 
	add(x, y, z), add(y, x, 0); }
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
//		for (int i = h[s]; i; i = ne[i])
//			write(to[i], ' '), write(w[i]);
		while (bfs()) {
			ans += dfs(s, 1e9);
//			write(ans);
		}
		return ans;
	}
}
using Flows::cnt;
using Flows::adde;
using Flows::s;
using Flows::t;
using Flows::flow;

#define ls p << 1
#define rs ls | 1
const int hinf = 1e8;
const int N = 10500;
int id[N<<2], _1[N<<2], tag[N<<2], n, q;
void build(int p, int l, int r) {
	if (l == r) return adde(id[p] = _1[p] = l, t, 1);
	int mid = (l + r) >> 1; id[p] = _1[p] = ++cnt;
	build(ls, l, mid), build(rs, mid + 1, r);
	adde(_1[p], _1[ls], hinf), adde(_1[p], _1[rs], hinf);
}

void change(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tag[p] ^= 1, id[p] = tag[p] ? 0 : _1[p], void();
	int mid = (l + r) >> 1; id[p] = ++cnt;
	if (L <= mid) change(ls, l, mid, L, R);
	if (R > mid) change(rs, mid + 1, r, L, R);
	if (id[ls]) adde(id[p], id[ls], hinf);
	if (id[rs]) adde(id[p], id[rs], hinf);
}

vector<pair<int, int> > v1[N], v2[N];
int main() {
	read(n), read(q), s = cnt = n + 1, t = ++cnt;
	for (int i = 1, x1, x2, y1, y2;i <= q; ++i) {
		read(x1), read(y1), read(x2), read(y2);
		v1[x1].emplace_back(y1, y2), v2[x2 + 1].emplace_back(y1, y2);
	}
	build(1, 1, n);
	for (int i = 1;i <= n; ++i) {
		for (auto t: v2[i]) change(1, 1, n, t.fi, t.se);
		for (auto t: v1[i]) change(1, 1, n, t.fi, t.se);
		adde(s, id[1], 1);
	}
	write(flow());
	return 0;
}
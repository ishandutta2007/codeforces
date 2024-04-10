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

#define ull unsigned ll
const int N = 305;
struct jzp {
	#define clz __builtin_clzll
	ull x, y;
	jzp() { x = y = 0; }
	bool operator < (const jzp &i) const { return y == i.y ? x < i.x : y < i.y;  }
	void flip(int t) { t >> 6 ? y ^= 1ull << (t & 63) : x ^= 1ull << t; }
	bool operator [] (int t) { return t >> 6 ? y >> (t & 63) & 1 : x >> t & 1; }
	inline int ht(void) { return y ? 127 - clz(y) : 63 - clz(x); }
	bool chr(void) { return x || y; }
}dp[N];

int h[N], ne[N<<1], to[N<<1], col[N<<1], siz[N], tot = 1, n;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
void dfs(int x, int fa) {
	siz[x] = 1;
	for (int i = h[x]; i; i = ne[i]) 
		if (to[i] != fa) dfs(to[i], x), siz[x] += siz[to[i]];
//	if (x == 3) {
//		puts("48");
//	}
	auto check = [&](jzp T) {
		priority_queue<pair<jzp, int> > q;
		for (int i = h[x]; i; i = ne[i]) 
			if (to[i] != fa) q.push(MP(dp[to[i]], i));
		while (q.size() && T.chr()) {
			jzp t = q.top().fi; int tt = q.top().se; q.pop();
//			if (tt == 118 || tt == 119) printf ("baba: %d\n", x);
			int x = T.ht(); T.flip(x);
			if (!t.chr()) { col[tt] = col[tt ^ 1] = x + 1; continue; }
			int y = t.ht(); t.flip(y);
			if (y > x) return 0;
			if (x == y) q.push(MP(t, tt));
			else col[tt] = col[tt ^ 1] = x + 1;
		}
		if (q.size()) return 0;
		return 1;
	};
	for (int i = 0;i < siz[x]; ++i) 
	dp[x].flip(i);
	for (int i = siz[x] - 1;i >= 0; --i) {
		dp[x].flip(i); 
		if (!check(dp[x])) 
		dp[x].flip(i);
	}
	check(dp[x]);
}

int vis[N<<1], mx, rt;
void getnx(int x, int fa) {
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (vis[i] || y == fa) continue;
		if (col[i] > mx) rt = i, mx = col[i];
		getnx(y, x);
	}
}

void solve(int x) {
	mx = 0, getnx(x, 0), vis[rt] = vis[rt ^ 1] = 1;
	if (!mx) { cout << "! " << x << endl; fflush(stdout); return; }
	cout << "? " << to[rt] << ' ' << to[rt ^ 1] << endl;
	fflush(stdout);
	int t; cin >> t; solve(t);
}

int main() {
	read(n);
	for (int i = 1, x, y;i < n; ++i)
		read(x), read(y), add(x, y), add(y, x);
	dfs(1, 0);
//	for (int i = 1;i < n; ++i) write(col[i * 2]);
//	for (int i = 1;i < n; ++i) if (col[i * 2] == 65) {
//		write(to[i * 2], ' '), write(to[i * 2 + 1]);
//	}
	solve(1);
	return 0;
}
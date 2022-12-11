
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

const int N = 600080;
int h[N], ne[N<<1], to[N<<1], tot = 1;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}
vector<int> ans;
int vis[N], d[N], rt, m, n, p;
void dfs(int x, int fa, int in) {
	vis[x] = 1;
	for (int i = h[x]; i; i = ne[i]) 
		if (!vis[to[i]]) dfs(to[i], x, i);
	if (d[x] && fa) d[fa] ^= 1, ans.push_back(in / 2);
}

int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) {
		read(d[i]);
		if (d[i] == -1) rt = i, d[i] = 0;
		else p ^= d[i];
	}
	if (!rt && p) return puts("-1"), 0;
	if (!rt) rt = 1;
	for (int i = 1, x, y;i <= m; i++)
		read(x), read(y), add(x, y), add(y, x);
	dfs(rt, 0, 0), sort(ans.begin(), ans.end());
	write(ans.size());
	for (auto t: ans) write(t);
	return 0;
}
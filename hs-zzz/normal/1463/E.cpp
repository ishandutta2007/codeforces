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

const int N = 360000;
int L[N], to[N], f[N], deg[N], vis[N], siz[N], m, n;
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int ans[N], nw;
int main() {
	read(n), read(m), nw = n;
	for (int i = 1;i <= n; i++) read(to[i]), deg[to[i]]++;
	for (int i = 1;i <= n; i++) siz[f[i] = i] = 1;
	for (int i = 1, x, y;i <= m; i++) {
		read(x), read(y); if (L[y] || find(x) == find(y)) return write(0), 0;
		L[y] = x, siz[find(y)] += siz[find(x)], f[find(x)] = find(y);
	}
	for (int i = 1;i <= n; i++) {
		if (find(i) == i) {
			int t = i;
			while (t) {
				int y = to[t]; vis[t] = 1;
				if (y && find(y) == find(t)) {
					if (vis[y]) return write(0), 0;
					to[t] = 0, deg[y]--;
				}
				t = L[t];
			}
		}
	}
	queue<int> q;
	for (int i = 1;i <= n; i++)
		if (!deg[i]) siz[find(i)]--;
	for (int i = 1;i <= n; i++)
		if (!siz[find(i)] && i == find(i)) q.push(i);
	while (q.size()) {
		int x = q.front(); q.pop();
		while (x) {
			int y = to[x];
			if (y && !--deg[y] && !--siz[find(y)]) q.push(find(y));
			ans[nw--] = x, x = L[x];
		}
	}
	if (nw) return write(0), 0;
	for (int i = 1;i <= n; i++) write(ans[i], ' ');
	return 0;
}
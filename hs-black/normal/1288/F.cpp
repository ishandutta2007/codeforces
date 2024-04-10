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
const int N = 2505;
int h[N], ne[N<<1], to[N<<1], w[N<<1], v[N<<1], cnt, s, t, tot = 1;
 
inline void add(int x, int y, int z, int c) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z, v[tot] = c;
}
inline void adde(int x, int y, int z, int c) { add(x, y, z, c), add(y, x, 0, -c); }
int vis[N]; ll dis[N];
queue<int> q;
bool spfa(void) {
	memset(vis, 0, cnt * 4 + 24);
	memset(dis, 0x3f, cnt * 8 + 24); 
	vis[s] = 1, dis[s] = 0, q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i];
			if (w[i] && dis[y] > dis[x] + v[i]) {
				dis[y] = dis[x] + v[i];
				if (!vis[y]) q.push(y), vis[y] = 1;
			}
		}
	}
	return dis[t] < 1e15;
}
 
int tim = 1;
int dfs(int x, int lim) {
	if (x == t || !lim) return lim;
	int res = 0, fl; vis[x] = tim;
	for (int i = h[x], y; i ; i = ne[i]) {
		if (dis[y = to[i]] != dis[x] + v[i] || vis[y] == tim) continue;
		fl = dfs(y, min(lim, w[i]));
		w[i] -= fl, w[i ^ 1] += fl, res += fl, lim -= fl;
		if (!lim) break;
	}
	return res;
}

ll res;
int n1, n2, m, rc, bc;
char A[N], B[N]; 
int main() {
//	freopen ("hs.in","r",stdin);
	read(n1), read(n2), read(m), read(rc), read(bc);
	scanf ("%s", A + 1), scanf ("%s", B + 1);
	cnt = n1 + n2, s = ++cnt, t = ++cnt;
	for (int i = 1;i <= n1; ++i) 
		if (A[i] == 'R') adde(s, i, 1, -1e8), adde(s, i, 1e8, 0), ++res;
		else if (A[i] == 'B') adde(i, t, 1, -1e8), adde(i, t, 1e8, 0), ++res;
		else adde(i, t, 1e8, 0), adde(s, i, 1e8, 0);
	for (int i = 1;i <= n2; ++i) 
		if (B[i] == 'B') adde(s, i + n1, 1, -1e8), adde(s, i + n1, 1e8, 0), ++res;
		else if (B[i] == 'R') adde(i + n1, t, 1, -1e8), adde(i + n1, t, 1e8, 0), ++res;
		else adde(i + n1, t, 1e8, 0), adde(s, i + n1, 1e8, 0);
	int nw = tot;
	for (int i = 1, x, y; i <= m; ++i) 
		read(x), read(y), adde(x, y + n1, 1, rc), adde(y + n1, x, 1, bc);
	adde(t, ++cnt, 1e8, 0), adde(s, t, 1e8, 0), t = cnt;
	res *= 1e8;
	while (spfa()) {
		ll tmp = 0;
		while (tmp = dfs(s, 1e9)) 
			res += tmp * dis[t], ++tim;
	}
	if (res >= 1e8) return write(-1), 0;
	write(res);
	for (int i = 1;i <= m; ++i) {
		bool f1 = 0, f2 = 0;
		nw += 2;
		if (w[nw]) f1 = 1;
		nw += 2;
		if (w[nw]) f2 = 1;
		if (f1 == f2) putchar('U');
		else if (f1) putchar('R');
		else putchar('B');
	}
	return 0;
}

/*

5 5 7 0 1
BBBBB
BBBBB
1 1
2 2
3 3
4 4
5 5
1 5
2 3

*/
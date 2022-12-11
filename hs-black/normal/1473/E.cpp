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

struct node {
	int x; ll dis; int a, b;
	bool operator < (const node &i) const {
		return dis > i.dis;
	}
	node (int X = 0, ll D = 0, int A = 0, int B = 0) : x(X), dis(D), a(A), b(B) {}
};

priority_queue<node> q;
int m, n;
const int N = 405000;
int h[N], ne[N<<1], to[N<<1], w[N<<1], tot;
inline void add(int x, int y, int z) { 
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}
ll dis[N][2][2];
int vis[N][2][2];
int main() {
	read(n), read(m);
	q.push(node(1, 0, 0, 0));
	for (int i = 1, x, y, z;i <= m; ++i) 
		read(x), read(y), read(z), add(x, y, z), add(y, x, z);
	memset(dis, 0x3f, sizeof(dis)), dis[1][0][0] = 0;
	while (q.size()) {
		int x = q.top().x; node t = q.top(); q.pop(); 
		if (vis[x][t.a][t.b]) continue; vis[x][t.a][t.b] = 1;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i];
			if (!t.a && dis[y][1][t.b] > dis[x][t.a][t.b]) 
					dis[y][1][t.b] = dis[x][t.a][t.b], q.push(node(y, dis[y][1][t.b], 1, t.b));
			
			if (!t.b && dis[y][t.a][1] > dis[x][t.a][t.b] + 2 * w[i]) 
				dis[y][t.a][1] = dis[x][t.a][t.b] + 2 * w[i], q.push(node(y, dis[y][t.a][1], t.a, 1));
			
			if (!t.a && !t.b && dis[y][1][1] > dis[x][t.a][t.b] + w[i]) 
				dis[y][1][1] = dis[x][t.a][t.b] + w[i], q.push(node(y, dis[y][1][1], 1, 1));
				
			if (dis[y][t.a][t.b] > dis[x][t.a][t.b] + w[i])
				dis[y][t.a][t.b] = dis[x][t.a][t.b] + w[i], q.push(node(y, dis[y][t.a][t.b], t.a, t.b));
		}
	}
	for (int i = 2;i <= n; ++i) write(dis[i][1][1], ' ');
	return 0;
}

/*

6 7
1 2 6
2 6 8
2 4 5
4 6 6
3 5 9
1 5 6
6 3 1


*/
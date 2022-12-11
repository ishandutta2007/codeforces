#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 405000;
queue<int> q;
int dis[N], bs[N], n, m, qu;
int h[N], ne[N<<1], to[N<<1], tot;
int s[N];

inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

void bfs(int s, int t) {
	q.push(s); dis[s] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; 
			if (dis[y]) {
				if (dis[y] == dis[x] + 1) bs[y] = 1;
				continue;
			}
			dis[y] = dis[x] + 1;
			q.push(y);
		}
	}
}

int main() {
	read(n), read(m);
	for (int i = 1;i <= m; i++) {
		int x, y; read(x), read(y); add(y, x);
	}
	read(qu);
	for (int i = 1;i <= qu; i++) read(s[i]);
	bfs(s[qu], s[1]);
	int mx = 0, mn = 0;
	for (int i = 1;i < qu; i++) {
		if (dis[s[i+1]] + 1 != dis[s[i]]) {
			mn++, mx++; continue;
		}
		if (bs[s[i]]) mx++;
	}
	cout << mn << ' ' << mx << endl;
	return 0;
}
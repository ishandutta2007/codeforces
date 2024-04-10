#pragma GCC optimize(3)
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
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

const int N = 600500;
int h[N], ne[N<<1], to[N<<1], tot = 1;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}


int n, m = 2e5;
int deg[N], used[N], res[N];

void dfs(int x) { 
	for (int &i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (used[i>>1]) continue;
		used[i>>1] = 1, res[i>>1] = i & 1, dfs(y);
	}
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) {
		int x, y; read(x), read(y); y += m;
		add(x, y), add(y, x); deg[x]++, deg[y]++;
	}
	
	for (int i = 1;i <= m * 2; i++) if (deg[i] & 1) add(i, 0), add(0, i);
	
	for (int i = 1;i <= m * 2; i++) dfs(i);
	
	for (int i = 1;i <= n; i++) putchar(res[i] ? 'b' : 'r');
	
	return 0;
}
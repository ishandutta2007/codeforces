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

const int N = 200050;
int h[N], ne[N<<1], to[N<<1];
int tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

double ans;
int dep[N];
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1;
	ans += 1.0 / (double)dep[x];
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs(y, x);
	}
}

int main() {
	int n; read(n);
	for (int i = 1;i < n; i++) {
		int x, y; read(x), read(y);
		add(x, y); add(y, x);
	}
	dfs(1, 0);
	printf ("%.10lf\n", ans);
	return 0;
}
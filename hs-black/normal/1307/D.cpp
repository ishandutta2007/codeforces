#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
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

queue<int> q;

const int N = 200500;
int ne[N<<1], to[N<<1], h[N], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

void bfs(int s, int *dep) {
	dep[s] = 0; q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; if (dep[y] <= dep[x] + 1) continue;
			dep[y] = dep[x] + 1; q.push(y);
		}
	}
}

int n, m, k;
int a[N], dis[N], rdis[N];
int tmp[N];

int main() {
	read(n), read(m), read(k);
	for (int i = 1;i <= k; i++) read(a[i]);
	for (int i = 1;i <= m; i++) {
		int x, y; read(x), read(y);
		add(x, y), add(y, x);
	}
	memset(dis, 0x3f, sizeof(dis));
	memset(rdis, 0x3f, sizeof(rdis));
	bfs(1, dis), bfs(n, rdis);
	for (int i = 1;i <= k; i++) tmp[i] = dis[a[i]];
	sort(tmp + 1, tmp + k + 1);
	int ans = 0;
	for (int i = 1;i <= k; i++) {
		int t = upper_bound(tmp + 1, tmp + k + 1, dis[a[i]]) - tmp - 1;
		if (t > 1) ans = max(ans, min(tmp[t-1] + rdis[a[i]] + 1, dis[n]));
	}
	cout << ans << endl;
	return 0;
}
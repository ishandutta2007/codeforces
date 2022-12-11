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

const int N = 1005000;
int deg[N], v[N], k, m, n;
int h[N], ne[N], to[N], tot = 1;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y, deg[x]++;
}

void dfs(int x) {
	for (int &i = h[x]; i; i = ne[i]) {
		if (v[i]) continue; v[i] = v[i^1] = 1; 
		int y = to[i]; dfs(to[i]);
		if ((++k) & 1) printf ("%d %d\n", y, x);
		else printf ("%d %d\n", x, y);
	}
}

vector<int> f__k;
int main() {
	read(n), read(m);
	for (int i = 1, x, y;i <= m; i++)
		read(x), read(y), add(x, y), add(y, x);
	for (int i = 1;i <= n; i++) if (deg[i] & 1) f__k.push_back(i);
	for (int i = 0;i < f__k.size(); i += 2) add(f__k[i], f__k[i+1]), add(f__k[i+1], f__k[i]), m++;
	if (m & 1) add(1, 1), add(1, 1), m++; printf ("%d\n", m), dfs(1);
	return 0;
}
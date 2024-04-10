// Hydro submission #61da69f68345528b626d51cb@1641703926618
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? -x : x;
}

#define N 200010
#define pb push_back

int n, x[N], y[N], c[N];
vector<int> e[N];

void dfs(int x, int col) {
	c[x] = col;
	for (auto y : e[x])
		if (!c[y]) dfs(y, 3 - col);
}

int main() {
	n = read();
	for (int i = 1; i <= n; i ++) {
		x[i] = read(), y[i] = read();
		e[x[i]].pb(y[i]), e[y[i]].pb(x[i]);
	}
	for (int i = 1; i <= n; i ++)
		e[i * 2 - 1].pb(i * 2), e[i * 2].pb(i * 2 - 1);

	for (int i = 1; i <= n * 2; i ++)
		if (!c[i]) dfs(i, 1);

	for (int i = 1; i <= n; i ++)
		printf("%d %d\n", c[x[i]], c[y[i]]);
	return 0;
}
#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;

int a[N][N];
struct DSU {
	int f[N];
	void init(int n) { std::iota(f + 1, f + n + 1, 1); }
	int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
} dsu[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m, k; std::cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) std::cin >> a[i][j];
	for (int i = 1; i <= m; ++i) {
		dsu[i].init(n + 1);
		for (int j = 1; j <= n; ++j) if (a[j][i] == 2) { dsu[i].f[j] = j + 1; }
	}
	while (k--) {
		int j; std::cin >> j; int i = dsu[j].find(1);
		while (i <= n) {
			dsu[j].f[i] = i + 1;
			if (a[i][j] == 1) a[i][j++] = 2;
			else a[i][j--] = 2;
			i = dsu[j].find(i);
		}
		std::cout << j << " \n"[k == 0];
	}

	return 0;
}
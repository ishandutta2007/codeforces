#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define maxN 323456

const int kM = 19;

int n, q, dis[40], ans[maxN];
int a[maxN], g[40][40];
vector<pair<int, int>> query[maxN];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		query[y - 1].push_back(make_pair(x - 1, i));
	}
	for (int i = 0; i < kM; i++)
		for (int j = 0; j < kM; j++)
			g[i][j] = -1;
	for (int i = 0; i < n; i++) {
		vector<int> dig;
		for (int j = 0; j < kM; j++)
			if (a[i] & (1 << j))
				dig.push_back(j);
		for (int j = 0; j < kM; j++)
			dis[j] = -1;
		for (auto x : dig) {
			dis[x] = i;
			for (int j = 0; j < kM; j++)
				dis[j] = max(dis[j], g[x][j]);
		}
		for (auto x : dig) {
			for (int j = 0; j < kM; j++)
				g[x][j] = max(g[x][j], dis[j]);
		}
		for (auto p : query[i]) {
			auto solve = [&] {
				int l = p.first;
				for (int x = 0; x < kM; x++)
					if (a[i] & (1 << x))
						for (int y = 0; y < kM; y++)
							if (a[l] & (1 << y) && g[x][y] >= l)
								return 1;
				return 0;
			};
			ans[p.second] = solve();
		}
	}
	for (int i = 0; i < q; i++) {
		if (ans[i]) {
			puts("Shi");
		} else {
			puts("Fou");
		}
	}
}
#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 105;

int n;
bool eq[mxn][mxn][mxn];
int cc[mxn][mxn], c;

inline void dfs(int u, int v) {
	if (cc[u][v]) return ;
	cc[u][v] = c;
	dfs(v, u);
	rep(w, n) if (eq[u][w][v] || eq[w][u][v]) dfs(w, v);
}

inline bool check(std::vector <std::pair <int, int> > edge) {
	static int dis[mxn][mxn];
	rep(i, n) rep(j, n) dis[i][j] = i == j ? 0 : 0x3f3f3f3f;
	rep(i, n - 1) dis[edge[i].first][edge[i].second] = 1;
	rep(i, n - 1) dis[edge[i].second][edge[i].first] = 1;
	rep(k, n) rep(i, n) rep(j, n) dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
	rep(i, n) rep(j, n) if (dis[i][j] >= mxn) return 0;
	rep(i, n) for (int j = i + 1; j < n; ++ j) rep(k, n)
		if ((dis[i][k] == dis[j][k]) != eq[i][j][k]) return 0;
	return 1;
}

inline void Main() {
	scanf("%d", &n);
	rep(i, n) rep(j, n) rep(k, n) eq[i][j][k] = 0;
	rep(i, n) for (int j = i + 1; j < n; ++ j) {
		char temp[mxn];
		scanf("%s", temp);
		rep(k, n) eq[i][j][k] = temp[k] - '0';
	}
	c = 0;
	rep(i, n) rep(j, n) if (i != j) cc[i][j] = 0;
	rep(i, n) rep(j, n) if (i != j) if (!cc[i][j]) ++ c, dfs(i, j);
	static std::vector <std::pair <int, int> > vec[mxn * mxn];
	for (int i = 1; i <= c; ++ i) vec[i].clear();
	rep(i, n) rep(j, n) if (i < j) vec[cc[i][j]].push_back({i, j});
	for (int i = 1; i <= c; ++ i)
		if ((int) vec[i].size() == n - 1)
			if (check(vec[i])) {
				puts("Yes");
				rep(j, n - 1) printf("%d %d\n", vec[i][j].first + 1, vec[i][j].second + 1);
				return ;
			}
	puts("No");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}
#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, m;
int v[305 * 305], sv[305 * 305];
int cost[305][305];
std::vector <int> vec;
std::vector <int> map[305 * 305];

void Main() {
	scanf("%d %d", &n, &m);
	rep(i, n * m) scanf("%d", &v[i]);
	rep(i, n * m) sv[i] = v[i];
	std::sort(sv, sv + n * m);
	vec = std::vector <int> (v, v + n * m);
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	rep(i, n) rep(j, m) {
		cost[i][j] = j - (m - j - 1);
	}
	rep(i, vec.size()) map[i].clear();
	rep(i, n) for (int j = m - 1; ~j; -- j)
		map[std::lower_bound(vec.begin(), vec.end(), sv[i * m + j]) - vec.begin()].push_back(i * m + j);
	int ans = 0;
	for (int s = n * m - 1; ~s; -- s) {
		int i = v[s];
		int p = map[std::lower_bound(vec.begin(), vec.end(), i) - vec.begin()].back();
		map[std::lower_bound(vec.begin(), vec.end(), i) - vec.begin()].pop_back();
		ans += cost[p / m][p % m];
		for (int x = p / m, y = 0; y < p % m; ++ y) cost[x][y] += 1;
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}
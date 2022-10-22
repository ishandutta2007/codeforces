#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	int n, m; scanf("%d %d", &n, &m);
	std::vector <int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	std::map <int, int> cnt;
	rep(i, n) cnt[a[i]] += 1;
	std::vector <int> e;
	for (auto pr : cnt) e.push_back(pr.second);
	std::sort(e.begin(), e.end());
	e.erase(std::unique(e.begin(), e.end()), e.end());
	std::vector <std::vector <int> > vec(e.size());
	for (auto pr : cnt) {
		int p = std::lower_bound(e.begin(), e.end(), pr.second) - e.begin();
		vec[p].push_back(pr.first);
	}
	rep(i, e.size()) std::reverse(vec[i].begin(), vec[i].end());
	std::vector <std::vector <std::set <std::pair <int, int> > > > ban(e.size());
	rep(i, e.size()) ban[i].resize(e.size());
	rep(i, m) {
		int u, v; scanf("%d %d", &u, &v);
		int p = std::lower_bound(e.begin(), e.end(), cnt[u]) - e.begin();
		int q = std::lower_bound(e.begin(), e.end(), cnt[v]) - e.begin();
		ban[p][q].insert({u, v});
		ban[q][p].insert({v, u});
	}
	long long ans = 0;
	auto umax = [&] (long long v) { if (v > ans) ans = v; };
	auto chk = [&] (int x, int y) { umax(1LL * (cnt[x] + cnt[y]) * (x + y)); };
	rep(p, e.size()) for (int q = p + 1; q < (int) e.size(); ++ q) {
		int M = std::min(ban[p][q].size() + 1, vec[p].size());
		int N = std::min(ban[p][q].size() + 1, vec[q].size());
		rep(i, M) {
			int mn = N;
			rep(j, std::min(mn, N)) {
				if (ban[p][q].find({vec[p][i], vec[q][j]}) == ban[p][q].end()) {
					mn = j;
					chk(vec[p][i], vec[q][j]);
					break;
				}
			}
		}
	}
	rep(p, e.size()) {
		int mn = vec[p].size();
		rep(i, vec[p].size()) {
			for (int j = i + 1; j < (int) vec[p].size() && j < mn; ++ j) {
				if (ban[p][p].find({vec[p][i], vec[p][j]}) == ban[p][p].end()) {
					mn = j;
					chk(vec[p][i], vec[p][j]);
					break;
				}
			}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}
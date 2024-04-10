#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}

	std::vector<std::set<int>> differ(n);
	int id = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != a[0][j]) {
				differ[i].insert(j);
				if ((int)differ[i].size() > 4) {
					break;
				}
			}
		}
		if ((int)differ[i].size() > 4) {
			std::cout << "No\n";
			return 0;
		}
		if (!id && (int)differ[i].size() > 2) {
			id = i;
		}
	}
	if (!id) {
		std::cout << "Yes\n";
		for (int v : a[0]) {
			std::cout << v << " ";
		}
		std::cout << "\n";
		return 0;
	}

	for (int x : differ[id]) {
		std::vector<int> v;
		for (int i = 0; i < n; ++i) {
			v.push_back(a[i][x]);
		}
		std::sort(v.begin(), v.end());
		v.erase(std::unique(v.begin(), v.end()), v.end());
		int k = v.size();
		std::vector<std::vector<int>> p(k);
		for (int i = 0; i < n; ++i) {
			p[std::lower_bound(v.begin(), v.end(), a[i][x]) - v.begin()].push_back(i);
		}
		for (int y = 0; y < m; ++y) {
			if (x != y) {
				bool flag = true;
				std::vector<std::set<int>> S(differ);
				for (int i = 0; i < n; ++i) {
					S[i].insert(x), S[i].insert(y);
					if ((int)S[i].size() > 4) {
						flag = false;
						break;
					}
				}
				if (!flag) {
					continue;
				}
				std::vector<std::pair<bool, int>> pre(k), suf(k);
				auto merge = [&](std::pair<bool, int> a, std::pair<bool, int> b) {
					int t;
					if (a.second == -1 || b.second == -1) {
						t = std::max(a.second, b.second);
					} else {
						t = a.second;
						if (a.second != b.second) {
							return std::make_pair(false, t);
						}
					}
					return std::make_pair(a.first && b.first, t);
				};
				pre[0] = std::make_pair(true, -1);
				for (int d = 1; d < k; ++d) {
					pre[d] = pre[d - 1];
					for (int i : p[d - 1]) {
						if ((int)S[i].size() <= 2) {
							continue;
						} else if ((int)S[i].size() > 3) {
							pre[d].first = false;
						} else {
							pre[d] = merge(pre[d], std::make_pair(true, a[i][y]));
						}
					}
				}
				suf[k - 1] = std::make_pair(true, -1);
				for (int d = k - 2; d >= 0; --d) {
					suf[d] = suf[d + 1];
					for (int i : p[d + 1]) {
						if ((int)S[i].size() <= 2) {
							continue;
						} else if ((int)S[i].size() > 3) {
							suf[d].first = false;
						} else {
							suf[d] = merge(suf[d], std::make_pair(true, a[i][y]));
						}
					}
				}
				for (int d = 0; d < k; ++d) {
					std::pair<bool, int> tmp = merge(pre[d], suf[d]);
					for (int i : p[d]) {
						if ((int)S[i].size() <= 3) {
							continue;
						} else {
							tmp = merge(tmp, std::make_pair(true, a[i][y]));
						}
					}
					if (tmp.first) {
						if (tmp.second == -1) {
							tmp.second = a[0][y];
						}
						std::cout << "Yes\n";
						for (int i = 0; i < m; ++i) {
							if (i != x && i != y) {
								std::cout << a[0][i] << " ";
							} else if (i == x) {
								std::cout << v[d] << " ";
							} else {
								std::cout << tmp.second << " ";
							}
						}
						std::cout << "\n";
						return 0;
					}
				}
			}
		}
	}
	std::cout << "No\n";
}
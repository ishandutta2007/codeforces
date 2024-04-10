#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

const int M = (1 << 20);

vector<int> p;

void solve(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	string b;
	cin >> b;
	vector<vector<pair<int, int>>> f(M);
	for (int i = 0; i < n; ++i) {
		int val = a[i];
		int op = (b[i] == '*' ? +1 : -1); 
		while (val > 1) {
			int p0 = p[val];
			int e0 = 0;
			while (val % p0 == 0) {
				val /= p0;
				e0 += op;
			}
			f[p0].push_back({i, e0});
		}
	}
	vector<int> g(n);
	for (int i = 0; i < n; ++i) {
		g[i] = i;
	}
	for (const auto& f0 : f) {
		if (!f0.empty()) {
			vector<pair<int, int>> sk;
			auto add = [&](int val, int pos) {
				while (sk.size() > 0 && sk.back().first >= val) {
					sk.pop_back();
				}
				sk.push_back({ val, pos });
			};
			add(0, 0);
			int cur = 0;
			for (const auto& w : f0) {
				add(cur, w.first);
				cur += w.second;
				int target =  -1;
				if (sk[0].first <= cur) {
					int lo = 0;
					int hi = sk.size();
					while (hi - lo > 1) {
						int mi = (lo + hi) / 2;
						if (sk[mi].first <= cur) {
							lo = mi;
						} else {
							hi = mi;
						}
					}
					target = sk[lo].second;
				}
				g[w.first] = min(g[w.first], target);
				add(cur, w.first + 1);
			}
		}
	}
	vector<vector<int>> h(n + 1);
	for (int i = 0; i < n; ++i) {
		h[g[i] + 1].push_back(i);
	}
	set<int> w;
	w.insert(n);
	long long r = 0;
	for (int i = 0; i < n; ++i) {
		for (int j : h[i]) {
			w.insert(j);
		}
		while (*w.begin() < i) {
			w.erase(w.begin());
		}
		r += *w.begin() - i;
	}
	cout << r << endl;
}

int main()
{
#ifdef _MSC_VER
	freopen("g.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	p = vector<int>(M);
	for (int i = 2; i < M; ++i) {
		if (p[i] == 0) {
			for (int j = i; j < M; j += i) {
				p[j] = i;
			}
		}
	}
	int n;
	while (cin >> n) {
		solve(n);
	}
	return 0;
}
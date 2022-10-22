#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	vector<int> qs(m);
	vector<int> qt(m);
	vector<int> qr(m);
	vector<vector<int>> qg(n);
	for (int i = 0; i < m; ++i) {
		cin >> qs[i] >> qt[i];
		--qs[i];
		--qt[i];
		qg[qs[i]].push_back(i);
	}

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = str[i] - '0';
	}
	vector<int> s(n + 1);
	for (int i = 0; i < n; ++i) {
		s[i] = (a[i] == 0 ? -1 : 1);
	}
	auto accumulate = [&](vector<int> &s) {
		int d = 0;
		for (int i = 0; i < n; ++i) {
			swap(s[i], d);
			d += s[i];
		}
		s[n] = d;
	};
	accumulate(s);

	vector<int> next(n + 1, -1);
	unordered_map<int, int> last;

	vector<int> count1[2];
	vector<int> count2[2][2];
	for (int i = 0; i < 2; ++i) {
		count1[i] = vector<int>(n + 1);
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			count2[i][j] = vector<int>(n + 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		++count1[a[i]][i];
	}
	for (int i = 0; i < n - 1; ++i) {
		++count2[a[i]][a[i+1]][i];
	}
	for (int i = 0; i < 2; ++i) {
		accumulate(count1[i]);
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			accumulate(count2[i][j]);
		}
	}

	for (int i = n; i >= 0; i--) {
		if (last.count(s[i])) {
			next[i] = last[s[i]];
		}
		last[s[i]] = i;
	}
	auto compute = [&](int s, int t) {
		assert(s <= t);
		int c = a[s];
		int ret = count1[c][t + 1] - count1[c][s];
		if (s < t) {
			ret -= count2[1 - c][c][t] - count2[1 - c][c][s];
		}
		return ret;
	};
	struct Container {
		vector<pair<int, int>> vals;
		vector<int> s2;

		void add(pair<int, int> p) {
			vals.push_back(p);
			int e = p.second - 1;
			if (!s2.empty()) {
				e += s2.back();
			}
			s2.push_back(e);
		}
		int get_s2(int s) const {
			if (s >= s2.size()) {
				return 0;
			}
			int ret = s2.back();
			if (s > 0) {
				ret -= s2[s - 1];
			}
			return ret;
		}
	};
	vector<Container> c(n + 1);

	auto calc = [&](int s, int t, const Container& c) {
		if (c.vals.empty()) {
			return compute(s, t);
		}
		if (t >= c.vals[0].first) {
			return c.get_s2(0) + compute(c.vals[0].first - 1, t);
		}
		int lo = 0;
		int hi = c.vals.size();
		for (; hi - lo > 1;) {
			int md = (lo + hi) / 2;
			auto p = c.vals[md];
			if (t < p.first) {
				lo = md;
			} else {
				hi = md;
			}
		}
		return c.get_s2(hi) + compute(hi == c.vals.size() ? s : c.vals[hi].first - 1, t);
	};
	for (int s = n - 1; s >= 0; s--) {
		if (next[s] >= 0) {
			c[s] = std::move(c[next[s] - 1]);
			c[s].add({next[s], compute(s, next[s] - 1) });
		}
		for (int id : qg[s]) {
			assert(s == qs[id]);
			qr[id] = calc(s, qt[id], c[s]);
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%d\n", qr[i]);
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("h.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	solve();
	return 0;
}
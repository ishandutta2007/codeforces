#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, s, t) for (int i = static_cast<int>(s); i < static_cast<int>(t); ++i)
#define REP(i, n) for (int i = 0; i < static_cast<int>(n); ++i)

int get_root(vector<int>& p, int cur) {
	if (p[cur] == cur) {
		return cur;
	}
	int root = get_root(p, p[cur]);
	p[cur] = root;
	return root;
}

int one_case() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	REP(i, n) {
		cin >> a[i];
	}
	REP(i, n) {
		int b;
		cin >> b;
		a[i] -= b;
	}
	vector<int> l(m);
	vector<int> r(m);
	REP(i, m) {
		cin >> l[i] >> r[i];
		--l[i];
	}
	vector<ll> s(n + 1);
	REP(i, n) {
		s[i + 1] = s[i] + a[i];
	}
	vector<vector<int>> g(n + 1);
	REP(i, m) {
		g[l[i]].push_back(i);
		g[r[i]].push_back(i);
	}
	vector<int> active(m, 1);
	vector<int> que;

	vector<int> p(n + 2);
	REP(i, n + 2) {
		p[i] = i;
	}
	REP(i, n + 1) {
		if (!s[i]) {
			p[i] = i + 1;
		}
	}

	auto touch = [&](int at) {
		for (int id : g[at]) {
			if (active[id] && s[l[id]] == 0 && s[r[id]] == 0) {
				que.push_back(id);
			}
		}
	};

	REP(i, n + 1) {
		touch(i);
	}
	for (int close = 0; close < que.size(); ++close) {
		int cur = que[close];
		if (!active[cur]) {
			continue;
		}
		active[cur] = 0;
		for (int i = l[cur] + 1; i < r[cur]; ++i) {
			i = get_root(p, i);
			if (i >= r[cur]) {
				break;
			}
			assert(s[i] && p[i] == i);
			if (s[i]) {
				s[i] = 0;
				p[i] = i + 1;
				touch(i);
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		if (s[i]) {
			return 0;
		}
	}
	return 1;
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		if (one_case()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Tree {
	Tree(vector<ll> a)
		: a(a) {
		nodes.resize(a.size() * 4);
		build(0, 0, a.size() - 1);
	}

	vector<ll> a;
	vector<pair<ll, int>> nodes;

	void build(int idx, int l, int r) {
		auto& node = nodes[idx];
		if (l == r) {
			node.first = a[l];
			node.second = 1;
			return;
		}
		int m = (l + r) / 2;
		build(idx * 2 + 1, l, m);
		build(idx * 2 + 2, m + 1, r);
		node = f(nodes[idx * 2 + 1], nodes[idx * 2 + 2]);
	}

	pair<ll, int> extract(int idx, int l, int r, int ll, int rr) {
		if (ll <= l && rr >= r) {
			return nodes[idx];
		}
		int m = (l + r) / 2;
		if (rr <= m) {
			return extract(idx * 2 + 1, l, m, ll, rr);
		}
		if (ll > m) {
			return extract(idx * 2 + 2, m + 1, r, ll, rr);
		}
		auto n1 = extract(idx * 2 + 1, l, m, ll, rr);
		auto n2 = extract(idx * 2 + 2, m + 1, r, ll, rr);
		return f(n1, n2);
	}

	pair<ll, int> f(pair<ll, int> n1, pair<ll, int> n2) {
		pair<ll, int> node;
		node.first = min(n1.first, n2.first);
		node.second = 0;
		if (n1.first == node.first) {
			node.second += n1.second;
		}
		if (n2.first == node.first) {
			node.second += n2.second;
		}
		return node;
	}

	int find_next(int idx, int l, int r, int at, ll limit) {
		if (r < at) {
			return -1;
		}
		if (nodes[idx].first >= limit) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		int m = (l + r) / 2;
		int ret = find_next(idx * 2 + 1, l, m, at, limit);
		if (ret >= 0) {
			return ret;
		}
		return find_next(idx * 2 + 2, m + 1, r, at, limit);
	}

	int find_next(int at, ll limit) {
		int ret = find_next(0, 0, a.size() - 1, at, limit);
		return (ret < 0) ? a.size() : ret;
	}

	pair<ll, int> min_val(int l, int r) {
		return extract(0, 0, a.size() - 1, l, r);
	}
};

ll solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<ll> s(n);
	s[0] = a[0];
	for (int i = 1; i < n; ++i) {
		s[i] = a[i] - s[i - 1];
	}
	ll ret = 0;

	vector<ll> val_even(n, 1ll << 60);
	vector<ll> val_odd(n, 1ll << 60);
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			val_even[i] = s[i];
		} else {
			val_odd[i] = s[i];
		}
	}
	Tree tree_even(val_even);
	Tree tree_odd(val_odd);

	for (int i = 0; i < n; ++i) {
		ll base = (i - 1 < 0 ? 0 : s[i - 1]);

		int m1 = tree_even.find_next(i, (i % 2 == 0) ? -base : base);
		int m2 = tree_odd.find_next(i, (i % 2 == 1) ? -base : base);
		int lo = min(m1, m2) - 1;
		auto t1 = tree_even.min_val(i, lo);
		if (t1.first == ((i % 2 == 0) ? -base : base)) {
			ret += t1.second;
		}
		auto t2 = tree_odd.min_val(i, lo);
		if (t2.first == ((i % 2 == 1) ? -base : base)) {
			ret += t2.second;
		}
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		printf("%lld\n", solve());
	}
	return 0;
}
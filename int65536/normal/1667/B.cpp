#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> nodes;

static void up(vector<int>& target, const vector<int>& source) {
	for (int i = 0; i < source.size(); ++i) {
		target[i] = max(target[i], source[i]);
	}
}

void add(int cur, int min_val, int max_val, int val, const vector<int>& pd) {
	up(nodes[cur], pd);
	if (min_val == max_val) {
		return;
	}
	int mid_val = min_val + (max_val - min_val) / 2;
	if (val <= mid_val) {
		add(cur * 2 + 1, min_val, mid_val, val, pd);
	} else {
		add(cur * 2 + 2, mid_val + 1, max_val, val, pd);
	}
}

void eval(int cur, int min_val, int max_val, ll range_s, ll range_t, vector<int>& pd) {
	if (range_s <= min_val && range_t >= max_val) {
		up(pd, nodes[cur]);
		return;
	}
	if (range_s > max_val || range_t < min_val) {
		return;
	}
	int mid_val = min_val + (max_val - min_val) / 2;
	eval(cur * 2 + 1, min_val, mid_val, range_s, range_t, pd);
	eval(cur * 2 + 2, mid_val + 1, max_val, range_s, range_t, pd);
}

vector<int> eval(int cur, int min_val, int max_val, ll range_s, ll range_t) {
	vector<int> pd(3, -1e9);
	eval(cur, min_val, max_val, range_s, range_t, pd);
	return pd;
}

void solve_one_case() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		a[i] = val;
	}
	ll M = 1e18;
	vector<ll> s(n + 1);
	for (int i = 0; i < n; ++i) {
		s[i + 1] = s[i] + a[i];
	}
	set<ll> ss(s.begin(), s.end());
	ss.insert(-M);
	ss.insert(M);
	vector<ll> vs(ss.begin(), ss.end());
	unordered_map<ll, int> ms;
	for (int i = 0; i < vs.size(); ++i) {
		ms[vs[i]] = i;
	}
	nodes = vector<vector<int>>(vs.size() * 4, vector<int>(3, -1e9));
	vector<int> f(n + 1);
	add(0, 0, vs.size() - 1, ms[0], {0, 0, 0});
	for (int i = 1; i <= n; ++i) {
		int t = ms[s[i]];
		f[i] = eval(0, 0, vs.size() - 1, t, t)[0];
		f[i] = max(f[i], eval(0, 0, vs.size() - 1, 0, t - 1)[1] + i);
		f[i] = max(f[i], eval(0, 0, vs.size() - 1, t + 1, vs.size() - 1)[2] - i);
		add(0, 0, vs.size() - 1, t, {f[i], f[i] - i, f[i] + i});
	}
	printf("%d\n", f[n]);
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; ++case_id) {
		solve_one_case();
	}
	return 0;
}
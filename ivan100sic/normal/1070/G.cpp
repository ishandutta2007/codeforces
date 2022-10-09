#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int _a[105], s[105], h[105], a[105], z[105];

bool walk_e(int x, int y, int h) {
	if (x < y) {
		for (int i=x; i<y; i++) {
			h += a[i];
			if (h < 0)
				return false;
		}
	} else {
		for (int i=x; i>y; i--) {
			h += a[i];
			if (h < 0)
				return false;
		}
	}
	return true;
}

bool walk_i(int x, int y, int h) {
	if (x < y) {
		for (int i=x; i<=y; i++) {
			h += a[i];
			if (h < 0)
				return false;
		}
	} else {
		for (int i=x; i>=y; i--) {
			h += a[i];
			if (h < 0)
				return false;
		}
	}
	return true;
}

// da li covek x moze da dodje do cilja
bool dp[105];
int nx[105];

basic_string<int> sol;

void sakupi(int x, int y) {
	basic_string<int> xpath, ypath, ima(105, 0);

	while (x != 0) {
		xpath += x;
		x = nx[x];
	}

	for (int x : xpath)
		ima[x] = 1;

	while (y != 0) {
		if (ima[y])
			break;
		ypath += y;
		y = nx[y];
	}

	for (int y : ypath)
		ima[y] = 1;

	reverse(xpath.begin(), xpath.end());
	reverse(ypath.begin(), ypath.end());

	sol = xpath + ypath;

	for (int i=1; i<=m; i++)
		if (!ima[i])
			sol += i;
}

bool solve_left(int y) {
	int lo = min_element(s+1, s+m+1) - s;
	int hi = max_element(s+1, s+m+1) - s;

	if (s[lo] > y)
		return false;

	vector<int> redosled(m);
	iota(redosled.begin(), redosled.end(), 1);

	auto cmp = [&](int u, int v) {
		return abs(s[u]-y) < abs(s[v]-y);
	};

	sort(redosled.begin(), redosled.end(), cmp);

	memset(dp, 0, sizeof(dp));

	for (int i=1; i<=m; i++) {
		auto f = s[i] <= y ? walk_i : walk_e;

		if (f(s[i], y, h[i])) {
			dp[i] = true;
			nx[i] = 0;
		}
	}
	
	for (int j : redosled) {
		if (dp[j])
			continue;
		for (int i=1; i<=m; i++) {
			if (!dp[i])
				continue;
			bool ok = false;
			if (y <= s[i] && s[i] <= s[j])
				ok = true;
			if (y >= s[i] && s[i] >= s[j])
				ok = true;
			if (!ok)
				continue;
			if (!walk_e(s[j], s[i], h[j]))
				continue;
			dp[j] = true;
			nx[j] = i;
			break;
		}
	}

	/*
	cerr << "y = " << y << '\n';
	for (int i=1; i<=m; i++) {
		cerr << dp[i] << ' ';
	}
	cerr << '\n';
	*/

	if (dp[lo] && dp[hi]) {
		sakupi(lo, hi);
		return true;
	}

	return false;
}

bool solve_right(int y) {
	int lo = min_element(s+1, s+m+1) - s;
	int hi = max_element(s+1, s+m+1) - s;

	if (s[hi] < y)
		return false;

	vector<int> redosled(m);
	iota(redosled.begin(), redosled.end(), 1);

	auto cmp = [&](int u, int v) {
		return abs(s[u]-y) < abs(s[v]-y);
	};

	sort(redosled.begin(), redosled.end(), cmp);

	memset(dp, 0, sizeof(dp));

	for (int i=1; i<=m; i++) {
		auto f = s[i] >= y ? walk_i : walk_e;

		if (f(s[i], y, h[i])) {
			dp[i] = true;
			nx[i] = 0;
		}
	}
	
	for (int j : redosled) {
		if (dp[j])
			continue;
		for (int i=1; i<=m; i++) {
			if (!dp[i])
				continue;
			bool ok = false;
			if (y <= s[i] && s[i] <= s[j])
				ok = true;
			if (y >= s[i] && s[i] >= s[j])
				ok = true;
			if (!ok)
				continue;
			if (!walk_e(s[j], s[i], h[j]))
				continue;
			dp[j] = true;
			nx[j] = i;
			break;
		}
	}

	/*
	cerr << "y = " << y << '\n';
	for (int i=1; i<=m; i++) {
		cerr << dp[i] << ' ';
	}
	cerr << '\n';
	*/

	if (dp[lo] && dp[hi]) {
		sakupi(hi, lo);
		return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++)
		cin >> s[i] >> h[i];

	for (int i=1; i<=n; i++)
		cin >> _a[i];

	for (int i=1; i<=n; i++) {
		copy(_a, _a+105, a);
		partial_sum(a+1, a+n+1, z+1);
		if (solve_left(i)) {
			cout << i << '\n';
			for (int x : sol)
				cout << x << ' ';
			cout << '\n';
			return 0;
		}
		if (solve_right(i)) {
			cout << i << '\n';
			for (int x : sol)
				cout << x << ' ';
			cout << '\n';
			return 0;
		}
	}

	cout << "-1\n";
}
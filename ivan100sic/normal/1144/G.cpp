#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stanje {
	int raste, opada, pre, gde;
};

basic_string<int> solve(basic_string<int> a) {
	int n = a.size();
	vector<basic_string<stanje>> dp(n+1);
	dp[0] = {{-1, 200001, -1, -1}};
	for (int i=0; i<n; i++) {

		stanje t0, t1;
		t0 = t1 = {-12, -12, -12, -12};

		int x = a[i];
		int j = 0;
		for (auto [e, f, g, h] : dp[i]) {
			if (x > e)
				if (t0.raste == -12 || f > t0.opada)
					t0 = {x, f, j, 0};

			if (x < f)
				if (t1.raste == -12 || e < t1.raste)
					t1 = {e, x, j, 1};

			j++;
		}

		if (t0.raste != -12)
			dp[i+1] += t0;
		if (t1.raste != -12)
			dp[i+1] += t1;
	}


	if (dp[n].size()) {
		basic_string<int> sol(n, 0);
		int x = 0;
		for (int i=n-1; i>=0; i--) {
			sol[i] = dp[i+1][x].gde;
			x = dp[i+1][x].pre;
		}
		return sol;
	} else {
		return {};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	basic_string<int> a;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a += x;
	}

	auto w = solve(a);
	if (w.size()) {
		cout << "YES\n";
		for (int x : w)
			cout << x << ' ';
		cout << "\n";
	} else {
		cout << "NO\n";
	}
		
}
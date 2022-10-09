#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int a[100005];

struct engine {
	vector<int> a;
	ll val;

	engine() : a(100005, 0), val(0) {}

	void add(int x) {
		val += a[x]++;
	}

	void remove(int x) {
		val -= --a[x];
	}

	ll operator() () {
		return val;
	}

	void reset() {
		a = vector<int>(100005, 0);
		val = 0;
	}
};

struct manager {
	int l = 1, r = 0;
	engine e;

	void target(int lx, int rx) {
		while (r < rx) {
			e.add(a[++r]);
		}
		while (l > lx) {
			e.add(a[--l]);
		}
		while (r > rx) {
			e.remove(a[r--]);
		}
		while (l < lx) {
			e.remove(a[l++]);
		}
	}

	ll operator() (int l, int r) {
		target(l, r);
		return e();
	}

};


ll dp[22][100005];

manager man;

void solve(int k, int nlo, int nhi, int slo, int shi) {
	if (nlo > nhi) {
		return;
	}

	int n = (nlo + nhi) / 2;
	dp[k][n] = 1e18;
	int pos = slo;

	for (int j=slo; j<=shi; j++) {
		ll sugg = dp[k-1][j] + man(j+1, n);
		if (sugg < dp[k][n]) {
			dp[k][n] = sugg;
			pos = j;
		}
	}

	solve(k, nlo, n-1, slo, pos);
	solve(k, n+1, nhi, pos, shi);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n; i++) {
		dp[1][i] = man(1, i);
	}

	for (int j=2; j<=k; j++) {
		solve(j, 1, n, 0, n-1);
	}

	cout << dp[k][n];
}
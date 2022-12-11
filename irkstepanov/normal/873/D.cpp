#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 100500;

int dp[nmax];

vector<int> ans;
bool ok = true;

void solve(int lf, int rg, int k, int a, int b) {
	if (k == 1) {
		for (int i = lf; i <= rg; ++i) {
			ans[i] = a + (i - lf);
		}
		return;
	}
	if (k <= 2) {
		ok = false;
		return;
	}
	int l = lf, r = rg + 1;
	int m = (l + r) >> 1;
	--k;
	if (dp[m - l] + 1 >= k) {
		solve(lf, m - 1, k - 1, a + rg - m + 1, b);
		for (int i = m; i <= rg; ++i) {
			ans[i] = a + (i - m);
		}
	} else {
		k -= dp[m - l];
		solve(lf, m - 1, dp[m - l], a + rg - m + 1, b);
		solve(m, rg, k, a, a + rg - m);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	dp[1] = 1;
	for (int n = 2; n < nmax; ++n) {
		int l = 0, r = n;
		int m = (l + r) >> 1;
		dp[n] = 1 + dp[m - l] + dp[r - m];
	}

	int n, k;
	cin >> n >> k;
	if (dp[n] < k) {
		cout << "-1\n";
		return 0;
	}

	ans.resize(n);
	solve(0, n - 1, k, 1, n);

	if (!ok) {
		cout << "-1\n";
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

}
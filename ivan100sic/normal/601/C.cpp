#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// moze ali ne mora fft
int n, m;

double dp[2][110005];
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	if (m == 1) {
		cout << "1\n";
		return 0;
	}

	dp[0][0] = 1.0;

	double g = 1.0 / (m - 1);

	for (int i=1; i<=n; i++) {
		auto ol = dp[1-i%2];
		auto nu = dp[i%2];
		memset(nu, 0, sizeof(dp[0]));
		int r = a[i];

		for (int j=0; j<=m*i; j++) {
			// dodaj ljudima f
			double og = ol[j] * g;
			nu[j + 1] += og;
			nu[j + r] -= og;
			nu[j + r + 1] += og;			
			nu[j + m + 1] -= og;
		}

		// pusti prefsum
		for (int j=1; j<=m*i+m+2; j++)
			nu[j] += nu[j-1];
	}

	auto d = dp[n%2];
	int er = accumulate(a+1, a+n+1, 0);
	double r = 0.0;
	for (int i=0; i<er; i++)
		r += d[i];
	cout.precision(20);
	cout << fixed << r*(m-1) + 1 << '\n';
}
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 1e6 + 100;
const int mod = 1e9 + 7;

void add(int& a, int b)
{
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void mul(int& a, int b)
{
	ll c = ll(a) * ll(b);
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

int dp[20][nmax];

int solve(int k, int r) // k >= 1
{
	if (r == 0) {
		return 2;
	}
	int ans = dp[k][r];
	int val = dp[k - 1][r + 1];
	mul(val, 2);
	add(ans, val);
	return ans;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	dp[0][0] = 1;
	for (int n = 0; n < 20; ++n) {
		for (int k = 1; k < nmax; ++k) {
			for (int val = 0; val <= n; ++val) {
				add(dp[n][k], dp[n - val][k - 1]);
			}
		}
	}

	int mind[nmax];
	vector<int> primes;
	mind[1] = 0;

	for (int i = 2; i < nmax; ++i) {
		mind[i] = i;
	}
	for (int i = 2; i < nmax; ++i) {
		if (mind[i] == i) {
			primes.pb(i);
		}
		for (int j = 0; j < sz(primes) && primes[j] <= mind[i] && primes[j] * i < nmax; ++j) {
			mind[i * primes[j]] = primes[j];
		}
	}

	int q;
	cin >> q;

	while (q--) {
		int r, n;
		cin >> r >> n;
		int ans = 1;
		while (n != 1) {
			int k = 0;
			int p = mind[n];
			while (mind[n] == p) {
				++k;
				n /= p;
			}
			mul(ans, solve(k, r));
		}
		cout << ans << "\n";
	}

}
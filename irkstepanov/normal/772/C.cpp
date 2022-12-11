#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int mod;

void mul(int& a, int b)
{
	ll c = ll(a) * ll(b);
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

int binpow(int a, int n)
{
	int ans = 1;
	while (n) {
		if (n & 1) {
			mul(ans, a);
		}
		mul(a, a);
		n >>= 1;
	}
	return ans;
}

int getPhi(int n)
{
	int ans = n;
	for (int d = 2; d * d <= n; ++d) {
		if (n % d == 0) {
			ans /= d;
			ans *= (d - 1);
			while (n % d == 0) {
				n /= d;
			}
		}
	}
	if (n != 1) {
		ans /= n;
		ans *= (n - 1);
	}
	return ans;
}

const int inf = 1e9;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

    /*ios_base::sync_with_stdio(false); // TODO
    cin.tie(0);
    cout.tie(0);*/

	int forbidden;
	cin >> forbidden >> mod;

	vector<char> valid(mod, true);
	while (forbidden--) {
		int x;
		cin >> x;
		valid[x] = false;
	}

	vector<vector<int> > d(mod + 1);
	for (int i = 0; i < mod; ++i) {
		if (valid[i]) {
			d[__gcd(i, mod)].pb(i);
		}
	}

	int phi = getPhi(mod);

	vector<int> dp(mod + 1, -inf);
	vector<int> pr(mod + 1, -1);
	for (int i = 1; i <= mod; ++i) {
		dp[i] = sz(d[i]);
		pr[i] = -1;
		for (int x = 1; x * x <= i; ++x) {
			if (i % x == 0) {
				if (x != i) {
					if (dp[x] + sz(d[i]) > dp[i]) {
						dp[i] = dp[x] + sz(d[i]);
						pr[i] = x;
					}
				}
				if (i / x != i) {
					if (dp[i / x] + sz(d[i]) > dp[i]) {
						dp[i] = dp[i / x] + sz(d[i]);
						pr[i] = i / x;
					}
				}
			}
		}
	}

	int ans = -inf;
	int start = 0;
	for (int i = 1; i <= mod; ++i) {
		if (dp[i] > ans) {
			ans = dp[i];
			start = i;
		}
	}

	vector<int> res;
	while (start != -1) {
		for (int x : d[start]) {
			res.pb(x);
		}
		//cout << start << " " << sz(d[start]) << "\n";
		start = pr[start];
	}

	reverse(all(res));
	cout << sz(res) << "\n";

	for (int i = 0; i < sz(res); ++i) {
		if (!i) {
			cout << res[i] << " ";
		} else {
			int g = __gcd(res[i], res[i - 1]);
			int y = binpow(res[i - 1] / g, phi - 1);
			mul(y, res[i] / g);
			cout << y << " ";
		}
	}
	cout << "\n";

}
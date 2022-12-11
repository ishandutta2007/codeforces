#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const ll inf = 3e18;
const int nmax = 100;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	string s;
	cin >> s;

	vector<vector<ll> > dp(sz(s) + 1, vector<ll>(nmax, inf));
	dp[sz(s)][0] = 0;

	vector<ll> degs(nmax);
	degs[0] = 1;
	for (int i = 1; i < nmax; ++i) {
		degs[i] = degs[i - 1];
		ll t = inf / n;
		if (inf % n == 0) {
			++t;
		}
		if (degs[i] > t) {
			degs[i] = inf;
		} else {
			degs[i] *= n;
		}
	}

	vector<vector<ll> > val(sz(s), vector<ll>(sz(s)));
	for (int i = 0; i < sz(s); ++i) {
		for (int j = i; j < sz(s); ++j) {
			if (s[i] == '0' && i != j) {
				val[i][j] = inf;
			} else {
				if (j == i) {
					val[i][j] = s[i] - '0';
				} else {
					ll x = val[i][j - 1];
					ll t = (inf - (s[j] - '0')) / 10;
					if ((inf - (s[j] - '0')) % 10 == 0) {
						++t;
					}
					if (x > t) {
						val[i][j] = inf;
					} else {
						val[i][j] = ll(10) * x + (s[j] - '0');
					}
				}
			}
			if (val[i][j] >= n) {
				val[i][j] = inf;
			}
		}
	}

	for (int i = sz(s); i; --i) {
		for (int deg = 0; deg < nmax; ++deg) {
			if (dp[i][deg] == inf) {
				continue;
			}
			for (int j = i - 1; j >= 0; --j) {
				if (val[j][i - 1] == inf) {
					continue;
				}
				ll t = (inf - dp[i][deg]) / degs[deg];
				if ((inf - dp[i][deg]) % degs[deg] == 0) {
					++t;
				}
				if (val[j][i - 1] > t) {
					continue;
				}
				ll x = val[j][i - 1] * degs[deg] + dp[i][deg];
				dp[j][deg + 1] = min(dp[j][deg + 1], x);
			}
		}
	}

	ll ans = inf;
	for (int deg = 0; deg < nmax; ++deg) {
		ans = min(ans, dp[0][deg]);
	}
	cout << ans << "\n";

}
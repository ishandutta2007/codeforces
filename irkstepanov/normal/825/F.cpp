
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

vector<int> p_function(const string& s) {
	int n = sz(s);
	vector<int> p(n);
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		p[i] = j;
	}
	return p;
}

const int nmax = 1e4;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	
	int f[nmax];
	for (int i = 1; i < nmax; ++i) {
		int val = i;
		f[i] = 0;
		while (val) {
			++f[i];
			val /= 10;
		}
	}

	string s;
	cin >> s;
	
	vector<int> dp(sz(s));
	for (int i = 0; i < sz(s); ++i) {
		dp[i] = i + 2;
		if (i) {
			dp[i] = min(dp[i], 2 + dp[i - 1]);
		}
		string t = "";
		for (int j = i; j >= 0; --j) {
			t += s[j];
		}
		vector<int> p = p_function(t);
		for (int j = 2; j <= i + 1; ++j) {
			int k = j - p[j - 1];
			int val = 0;
			if (j != i + 1) {
				val = dp[i - j];
			}
			if (j % k == 0) {
				dp[i] = min(dp[i], f[j / k] + k + val);
				if (j % (2 * k) == 0) {
					dp[i] = min(dp[i], f[j / (2 * k)] + 2 * k + val);
				}
			}
			dp[i] = min(dp[i], 1 + j + val);
		}
	}

	cout << dp.back() << "\n";

}
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int sigma = 26;
const int nmax = 100500;

//pair<int, char> pref[nmax], suff[nmax];
int dp[nmax][sigma];

int maxin(const string& s, char c) {
	int ans = 0;
	int pr = 0;
	for (int i = 1; i < sz(s); ++i) {
		if (s[pr] == s[i]) {
			continue;
		} else {
			if (s[pr] == c) {
				ans = max(ans, i - pr);
			}
			pr = i;
		}
	}
	if (s[pr] == c) {
		ans = max(ans, sz(s) - pr);
	}
	return ans;
}

//bool same[nmax];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < sigma; ++i) {
		dp[0][i] = maxin(s[0], char(i + 'a'));
	}

	/*same[0] = true;
	for (int i = 1; i < sz(s[0]); ++i) {
		if (s[0][i] != s[0][0]) {
			same[0] = false;
		}
	}*/

	for (int i = 1; i < n; ++i) {
		bool eq = true;
		//same[i] = same[i - 1];
		for (int j = 1; j < sz(s[i]); ++j) {
			if (s[i][j] != s[i][0]) {
				eq = false;
			}
		}
		//memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
		for (int j = 0; j < sigma; ++j) {
			dp[i][j] = maxin(s[i], char(j + 'a'));
			if (dp[i - 1][j]) {
				dp[i][j] = max(dp[i][j], 1);
			}
		}
		if (eq) {
			int c = s[i][0] - 'a';
			int k = dp[i - 1][c];
			dp[i][c] = max(dp[i][c], sz(s[i]) * (k + 1) + k);
			/*if (c != s[0][0]) {
				same[i] = false;
			}*/
		} else {
			//same[i] = false;
			int pref = 1, suff = 1;
			while (pref < sz(s[i]) && s[i][pref] == s[i][0]) {
				++pref;
			}
			while (suff < sz(s[i]) && s[i][sz(s[i]) - suff - 1] == s[i].back()) {
				++suff;
			}
			if (s[i][0] == s[i].back()) {
				int c = s[i][0] - 'a';
				if (dp[i - 1][c]) {
					dp[i][c] = max(dp[i][c], pref + suff + 1);
				}
			} else {
				int c = s[i][0] - 'a';
				if (dp[i - 1][c]) {
					dp[i][c] = max(dp[i][c], pref + 1);
				}
				c = s[i].back() - 'a';
				if (dp[i - 1][c]) {
					dp[i][c] = max(dp[i][c], suff + 1);
				}
			}
		}
	}

	int ans = 0;
	for (int c = 0; c < sigma; ++c) {
		ans = max(ans, dp[n - 1][c]);
	}
	cout << ans << "\n";

}
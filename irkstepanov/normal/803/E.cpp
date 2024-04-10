#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int nmax = 1010;

char dp[nmax][2 * nmax];

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n, k;
	cin >> n >> k;

	memset(dp, '-', sizeof(dp));
	dp[0][0 + nmax] = '+';

	string s;
	cin >> s;

	for (int i = 0; i < sz(s); ++i) {
		for (int b = -k + 1; b < k; ++b) {
			if (dp[i][b + nmax] != '-') {
				if (s[i] == 'W') {
					dp[i + 1][b + 1 + nmax] = 'W';
				} else if (s[i] == 'L') {
					dp[i + 1][b - 1 + nmax] = 'L';
				} else if (s[i] == 'D') {
					dp[i + 1][b + nmax] = 'D';
				} else {
					dp[i + 1][b + 1 + nmax] = 'W';
					dp[i + 1][b - 1 + nmax] = 'L';
					dp[i + 1][b + nmax] = 'D';
				}
			}
		}
	}

	if (dp[n][k + nmax] == '-' && dp[n][-k + nmax] == '-') {
		cout << "NO\n";
		return 0;
	}

	int b = k;
	if (dp[n][k + nmax] == '-') {
		b = -k;
	}
	int curr = n;
	string ans = "";

	while (curr > 0) {
		ans += dp[curr][b + nmax];
		if (dp[curr][b + nmax] == 'W') {
			--b;
		} else if (dp[curr][b + nmax] == 'L') {
			++b;
		}
		--curr;
	}
	reverse(all(ans));
	cout << ans << "\n";

}
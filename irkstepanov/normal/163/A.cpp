#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 5050;

const int mod = 1e9 + 7;

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

int dp[nmax][nmax];
int pref[nmax][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	string s, t;
	cin >> s >> t;

	int n = sz(s), m = sz(t);
	int ans = 0;

	for (int j = 0; j < m; ++j) {
		if (s[0] == t[j]) {
			dp[0][j] = 1;
			add(ans, 1);
		} else {
			dp[0][j] = 0;
		}
	}
	pref[0][0] = dp[0][0];
	for (int j = 1; j < m; ++j) {
		pref[0][j] = pref[0][j - 1];
		add(pref[0][j], dp[0][j]);
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i] == t[j]) {
				dp[i][j] = 1;
				if (j) {
					add(dp[i][j], pref[i - 1][j - 1]);
				}
				add(ans, dp[i][j]);
			}
		}
		pref[i][0] = dp[i][0];
		for (int j = 1; j < m; ++j) {
			pref[i][j] = pref[i][j - 1];
			add(pref[i][j], dp[i][j]);
		}
	}

	cout << ans << "\n";

}
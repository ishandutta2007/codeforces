#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

string s, t;
int n, m;
vector<int> dp[2];
int f[100005];

int prelaz[100005][26];
vector<int> mocni_prelazi[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> t;
	n = s.size();
	m = t.size();
	s = string(" ") + s;
	t = string(" ") + t + ".";

	dp[0].resize(m+1);
	dp[1].resize(m+1);

	// prefix funkcija
	f[0] = -1;
	f[1] = 0;
	for (int i=2; i<=m; i++) {
		int x = f[i-1] + 1;
		while (x > 0 && t[x] != t[i]) {
			x = f[x-1] + 1;
		}
		f[i] = x;
	}

	for (int j=0; j<=m; j++) {
		for (char r='a'; r<='z'; r++) {
			int u = j+1;
			
			if (t[u] != r) {
				u = prelaz[f[u-1]][r-'a'];
			}

			// cerr << j << ' ' << r << ' ' << u << '\n';

			prelaz[j][r-'a'] = u;
			mocni_prelazi[j].push_back(u);
		}

		sort(mocni_prelazi[j].begin(), mocni_prelazi[j].end());
		mocni_prelazi[j].resize(
			unique(mocni_prelazi[j].begin(), mocni_prelazi[j].end()) 
				- mocni_prelazi[j].begin()
		);
	}

	fill(dp[0].begin(), dp[0].end(), -123123123);
	dp[0][0] = 0;

	for (int i=1; i<=n; i++) {

		fill(dp[1].begin(), dp[1].end(), -123123123);

		for (int j=0; j<=m; j++) {
			// svi moguci prelazi
			if (s[i] == '?') {
				for (int u : mocni_prelazi[j]) {
					dp[1][u] = max(dp[1][u], dp[0][j] + (u == m));
				}
			} else {
				// samo ovaj koji mi kaze
				char r = s[i];
				{
					int u = prelaz[j][r-'a'];
					dp[1][u] = max(dp[1][u], dp[0][j] + (u == m));
				}
			}
		}

		swap(dp[0], dp[1]); // O(1)

		// cerr << i << ' ' << *max_element(dp[0].begin(), dp[0].end()) << '\n';
	}

	cout << *max_element(dp[0].begin(), dp[0].end()) << '\n';
	
}
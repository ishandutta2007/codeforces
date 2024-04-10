#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
3 2 3

4 4
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		string s;
		cin >> n >> m >> k >> s;
		vector<int> a(26);
		for (char x : s)
			a[x - 'A']++;
		int sol = 1123123123;
		for (int i=0; i<26; i++) {
			vector<char> dp(n+m+1, 0);
			dp[0] = 1;
			// bez i
			for (int j=0; j<26; j++) {
				if (j == i)
					continue;
				for (int k=n+m-a[j]; k>=0; k--)
					dp[k + a[j]] |= dp[k];
			}

			for (int j=0; j<=n+m; j++) {
				if (!dp[j])
					continue;
				int prvi = min(j, n);
				int drugi = min(k - a[i] - j, m);
				if (n-prvi + m-drugi > a[i])
					continue;
				// cerr << prvi << ' ' << drugi << '\n';
				sol = min(sol, (n-prvi) * (m-drugi));
			}
		}
		cout << sol << '\n';
	}
}
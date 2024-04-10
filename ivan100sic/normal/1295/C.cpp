// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		int n = a.size();
		vector<vector<int>> dp(n, vector<int>(26, -1));
		vector<int> last(26, -1);

		for (int rep=0; rep<2; rep++) {
			for (int i=n-1; i>=0; i--) {
				dp[i] = last;
				last[a[i]-'a'] = i;
			}
		}

		int p = n-1, c = 0;
		for (char x : b) {
			int q = dp[p][x-'a'];
			if (q == -1) {
				c = -1;
				break;
			}
			if (q <= p) {
				c++;
			}
			p = q;
		}

		cout << c << '\n';
	}
}
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
		ll a, b, p;
		string s;
		cin >> a >> b >> p >> s;
		int n = s.size();
		vector<ll> dp(n);

		int j = n;
		s.back() = 0;

		for (int i=n-2; i>=0; i--) {
			if (s[i] == s[i+1]) {
				dp[i] = dp[i+1];
			} else {
				dp[i] = dp[i+1] + (s[i] == 'A' ? a : b);
			}
			if (dp[i] <= p) {
				j = i+1;
			}
		}

		cout << j << '\n';
	}
}
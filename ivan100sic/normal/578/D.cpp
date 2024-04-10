#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s;
ll dp[2][730];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s;
	for (int i=0; i<n; i++)
		s[i] = s[i] - 'a' + 1;

	const int M = m+1;
	dp[0][M*M] = 1;

	for (int i=0; i<n; i++) {
		auto ol = dp[i%2];
		auto nu = dp[1-i%2];
		memset(nu, 0, sizeof dp[0]);
		int c = s[i];
		// non-empty
		for (int a=0; a<M; a++) {
			for (int b=0; b<M; b++) {
				ll dp = ol[a*M+b];
				// for (int d=1; d<M; d++) {
				// 	if (a == d && b == c)
				// 		nu[b*M+a] += dp;
				// 	else if (a == d)
				// 		nu[c*M+0] += dp;
				// 	else if (b == c)
				// 		nu[0*M+d] += dp;
				// 	else if (c == d)
				// 		nu[0*M+0] += dp;
				// }

				if (a != c) {
					// d != a, d != c
					if (b == c) {
						nu[1] += dp;
						nu[M] -= dp;
						if (a)
							nu[a] -= dp, nu[a+1] += dp;
						if (c)
							nu[c] -= dp, nu[c+1] += dp;
					}
						
					if (a) {
						int d = a;
						if (a == d && b == c)
							nu[b*M+a] += dp, nu[b*M+a+1] -= dp;
						else if (a == d)
							nu[c*M+0] += dp, nu[c*M+0+1] -= dp;
						else if (b == c)
							nu[0*M+d] += dp, nu[0*M+d+1] -= dp;
						else if (c == d)
							nu[0*M+0] += dp, nu[0*M+0+1] -= dp;
					}

					if (c) {
						int d = c;
						if (a == d && b == c)
							nu[b*M+a] += dp, nu[b*M+a+1] -= dp;
						else if (a == d)
							nu[c*M+0] += dp, nu[c*M+0+1] -= dp;
						else if (b == c)
							nu[0*M+d] += dp, nu[0*M+d+1] -= dp;
						else if (c == d)
							nu[0*M+0] += dp, nu[0*M+0+1] -= dp;
					}
				} else {
					// d != a (samim tim i d != c)
					if (b == c) {
						nu[1] += dp;
						nu[M] -= dp;
						nu[a] -= dp;
						nu[a+1] += dp;
					}

					if (a) {
						int d = a;
						if (a == d && b == c)
							nu[b*M+a] += dp, nu[b*M+a+1] -= dp;
						else if (a == d)
							nu[c*M+0] += dp, nu[c*M+0+1] -= dp;
						else if (b == c)
							nu[0*M+d] += dp, nu[0*M+d+1] -= dp;
						else if (c == d)
							nu[0*M+0] += dp, nu[0*M+0+1] -= dp;
					}
				}
			}
		}

		// empty
		{
			ll dp = ol[M*M];
			for (int d=1; d<M; d++) {
				if (c == d)
					nu[M*M] += dp;
				else
					nu[c*M+d] += dp, nu[c*M+d+1] -= dp;
			}
		}

		for (int i=1; i<=M*M; i++)
			nu[i] += nu[i-1];
	}

	cout << accumulate(dp[n%2]+0, dp[n%2]+M*M, 0ll) << '\n';
}
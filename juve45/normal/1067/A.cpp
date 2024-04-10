#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

const long long N = 100100;
const long long M = 200;
const long long MOD = 998244353;
long long n, k, m, dp[N][202][3], a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];

	for(long long i = 1; i <= n; i++) {
		if(a[i] == -1) {
			for(long long j = 1; j <= M; j++) {
				if(i == 1) dp[i][j][1] = 1;
				else {
					dp[i][j][0] = (MOD + MOD + dp[i - 1][M][0] - dp[i - 1][j - 1][0] + dp[i - 1][j][1] - dp[i - 1][j - 1][1]) % MOD;
					dp[i][j][1] = (dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0]) % MOD;
				}
			}
		} else {
			if(i == 1) dp[i][a[i]][1] = 1;
			else {
				dp[i][a[i]][0] = (MOD + MOD + dp[i - 1][M][0] - dp[i - 1][a[i] - 1][0] + dp[i - 1][a[i]][1] - dp[i - 1][a[i] - 1][1]) % MOD;
				dp[i][a[i]][1] = (dp[i - 1][a[i] - 1][1] + dp[i - 1][a[i] - 1][0]) % MOD;
			}
		}

		for(long long j = 2; j <= M; j++) {
			dp[i][j][0] += dp[i][j - 1][0];
			dp[i][j][1] += dp[i][j - 1][1];

			dp[i][j][0] %= MOD;
			dp[i][j][1] %= MOD;
		}
	}

	cout << (dp[n][M][0]  + MOD) % MOD << '\n';
}
#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1005;
const int MOD = 998244353;
long long n, k, dp[N][2 * N][4];

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

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;


	dp[1][1][0] = 1;
	dp[1][2][1] = 1;
	dp[1][2][2] = 1;
	dp[1][1][3] = 1;

	for(int i = 0; i < 4; i++) dp[0][0][i] = 1;

	for(int i = 2; i <=n; i++)
		for(int j = 1; j <= k; j++) {
			dp[i][j][0] += dp[i - 1][j][0] 			+ dp[i - 1][j][1] 		+ dp[i - 1][j][2] 		+ dp[i - 1][j - 1][3];
			dp[i][j][3] += dp[i - 1][j - 1][0] 	+ dp[i - 1][j][1] 		+ dp[i - 1][j][2] 		+ dp[i - 1][j][3];

			if(j >= 2) {
				dp[i][j][1] += dp[i - 1][j - 1][0] 			+ dp[i - 1][j][1]			+ dp[i - 1][j - 2][2] + dp[i - 1][j - 1][3];
				dp[i][j][2] += dp[i - 1][j - 1][0] 			+ dp[i - 1][j - 2][1] + dp[i - 1][j][2] 		+ dp[i - 1][j - 1][3];
			}

			dp[i][j][0] %= MOD;
			dp[i][j][1] %= MOD;
			dp[i][j][2] %= MOD;
			dp[i][j][3] %= MOD;
		}

		dbg(dp[2][4][0]);
		dbg(dp[2][4][1]);
		dbg(dp[2][2][2]);
		dbg_ok;

		dbg(dp[3][4][0]);
		dbg(dp[3][4][1]);
		dbg(dp[3][4][2]);
		dbg(dp[3][4][3]);
	cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % MOD << '\n';
}
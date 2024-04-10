#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


long long dp[44][4][4], cst[4][4];

long long get_dp(long long n, long long a, long long b, long long c) {
	if(n > 0 && dp[n][a][b] == 0) {
		dp[n][a][b] = min(get_dp(n - 1, a, c, b) + cst[a][b] + get_dp(n - 1, c, b, a),
									2LL * get_dp(n - 1, a, b, c) + cst[a][c] + get_dp(n - 1, b, a, c) + cst[c][b]);
	}
	return dp[n][a][b];
}

int main() {
	ios_base::sync_with_stdio(false);
		
	for(long long i = 1; i <= 3; i++)
		for(long long j = 1; j <= 3; j++)
			cin >> cst[i][j];

	cin >> n;

	// cout << get_dp(n, 3, 2, 1);

	cout << get_dp(n, 1, 3, 2) << '\n';
							 // get_dp(n, 1, 3, 2)}) << '\n';
}
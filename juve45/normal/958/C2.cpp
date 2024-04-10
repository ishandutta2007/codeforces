#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 20100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, p, a[DMAX], mx[DMAX];

int dp[55][20100][111];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int s[DMAX], lhs, rhs, ans;

int sum(int l, int r) {
	return s[r] - s[l - 1];
}

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k >> p;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= p;
	}	

	// dp[i][j][k] = val pt primele i imp in j bucati;

	memset(dp, -1, sizeof dp);

	int s = 0;
	for(int i = 1; i <= n; i++) {
		s += a[i];
		s %= p;
		dp[1][i][s] = s;
	}	

	for(int i = 2; i <= k; i++) {
		for(int j = i; j <= n; j++) {
			for(int l = 0; l < p; l++) {
				if(dp[i - 1][j - 1][l] != -1)
					dp[i][j][a[j]] = max(dp[i][j][a[j]], dp[i - 1][j - 1][l] + a[j]);
				if(i < j && dp[i][j - 1][l] != -1)
					dp[i][j][(l + a[j]) % p] = max(dp[i][j][(l + a[j]) % p], dp[i][j - 1][l] - l + (l + a[j]) % p);
			}
		}
	}

	// for(int i = 1; i <= k; i++) {
	// 	cout << " i -- " << i << '\n';
	// 	for(int j = 1; j <= n ; j++) {
	// 		cout << j << " --> ";
	// 		for(int l = 0; l < p; l++) cout << dp[i][j][l] << ' ';
	// 		cout << '\n';
	// 	}
	// 	cout << '\n';
	// 	cout << '\n';
	// }

	for(int i = 0; i < p ; i++)
		ans = max(ans, dp[k][n][i]);

	cout << ans << '\n';
}
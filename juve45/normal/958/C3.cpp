#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 10001
#define NMAX 500001
#define INF 0x3f3f3f3f

using namespace std;

int n, k, p, a[NMAX], lis[NMAX];

int dp[101][DMAX][111];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int s[DMAX], lhs, rhs, ans = INF;

int sum(int l, int r) {
	return s[r] - s[l - 1];
}

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k >> p;

	int s = 0;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= p;
		s += a[i];
	}	

	// dp[i][j][k] = val pt primele i imp in j bucati;

	if(n <= 10000) {
		memset(dp, 0x3f, sizeof dp);

		int s = 0;
		for(int i = 1; i <= n; i++) {
			s += a[i];
			s %= p;
			dp[1][i][s] = s;
		}	

		for(int i = 2; i <= k; i++) {
			for(int j = i; j <= n; j++) {
				for(int l = 0; l < p; l++) {
					if(dp[i - 1][j - 1][l] != INF)
						dp[i][j][a[j]] = min(dp[i][j][a[j]], dp[i - 1][j - 1][l] + a[j]);
					if(i < j && dp[i][j - 1][l] != INF)
						dp[i][j][(l + a[j]) % p] = min(dp[i][j][(l + a[j]) % p], dp[i][j - 1][l] - l + (l + a[j]) % p);
				}
			}
		}


		for(int i = 0; i < p ; i++)
				ans = min(ans, dp[k][n][i]);
		cout << ans << '\n';
	}
	else  {

		for(int i = 2; i <= n; i++) {
			a[i] += a[i - 1];
			a[i] %= p;
		}
		// dbg_v(a, n + 1);
		memset(lis, INF, sizeof lis);
		lis[0] = 0;
		int lenmax = 0;
		int pos = 0;
		for(int i = 1; i <= n; i++) {
			pos = upper_bound(lis, lis + lenmax + 1, a[i]) - lis;
			lis[pos] = min(lis[pos], a[i]);
			lenmax = max(lenmax, pos);
			// dbg_v(lis, n + 1);
		}


		if(pos >= k) cout << s % p;
		else cout << s % p + p;
	}
}
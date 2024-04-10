 #include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 65;
long long n, k, a[N], s[N], dp[N][N][N], ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

long long sum(long long i, long long j) {
	return s[j] - s[i - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	long long last = 61;
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= i && j <= k; j++)
			dp[i][j][last] = 1;

	for(long long h = 60; h >= 0; h--) {
		for(long long i = 1; i <= n; i++) {
			for(long long j = 1; j <= k && j <= i; j++) {
				if(j == 1) {
					dp[i][j][h] = ((sum(1, i) & ans) == ans && (sum(1, i) & (1LL << h)) != 0);
					continue;
				}
				for(long long i2 = j - 1; i2 < i; i2++)
					if((sum(i2 + 1, i) & ans) == ans && (sum(i2 + 1, i) & (1LL << h)) != 0 && dp[i2][j - 1][h] && dp[i][j][last] && dp[i2][j - 1][last]) {
						dp[i][j][h] = 1;
					}
			}
		}
		if(dp[n][k][h] == 1) {
			last = h;
			ans += (1LL << last);
		}
	}

	// for(long long j = 1; j <= k; j++) {
	// 	cout << j << " --- ";
	// 	for(long long i = 1; i <= n; i++) {
	// 		cout << dp[i][j][1] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	// for(long long j = 1; j <= k; j++) {
	// 	cout << j << " --- ";
	// 	for(long long i = 1; i <= n; i++) {
	// 		cout << dp[i][j][0] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	cout << ans << '\n';
}
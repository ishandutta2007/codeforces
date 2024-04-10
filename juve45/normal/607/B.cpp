#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 505;
int n, k, a[N], dp[N][N];

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
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int l = 1; l <= n; l++) {
		for(int i = 1; i + l - 1 <= n; i++) {
			int j = i + l - 1;
			if(l == 1) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = min(dp[i][j-1] + 1, dp[i+1][j] + 1);
			if(a[i] == a[j])
				dp[i][j] = min(dp[i][j], max(dp[i+1][j-1], 1));

			for(int k = i; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	}

	cout << dp[1][n] << '\n';

}
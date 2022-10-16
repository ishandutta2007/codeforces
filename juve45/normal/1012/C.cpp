#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 5050;
int n, k, a[N];
int dp[N][N][3];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int dist(int from, int to) {
	if(from < to)
		return 0;
	return from - to + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	a[0] = a[n + 1] = -100;

	memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i <= n; i++)
		dp[0][i][0] = 0;

	for(int i = 1; i <= (n + 1) / 2; i++)
		for(int j = 1; j <= n; j++) {
			dp[i][j][0] = min(dp[i][j - 1][0], dp[i][j-1][2]); // nu iau fix ultima chestie
			dp[i][j][1] = min(dp[i-1][j-1][0] + dist(a[j-1], a[j]), dp[i-1][j - 1][2] + dist(min(a[j-2]-1, a[j - 1]), a[j]) ) + dist(a[j+1], a[j]);
			dp[i][j][2] = dp[i][j - 1][1];
		}

	for(int i = 1; i <= (n + 1) / 2; i++)
		cout << min({dp[i][n][0], dp[i][n][1], dp[i][n][2]}) << ' ';
	cout << '\n';
}
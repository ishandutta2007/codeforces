#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k;

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
int v[N], dp[6][N];;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++)
		v[i + 1] = s[i] - '0';

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 6; j++)
			dp[j][i] = dp[j][i - 1];
		dp[v[i]][i] = max(dp[v[i]][i], dp[1-v[i]][i - 1] + 1);
		dp[3 - v[i]][i] = max({dp[3 - v[i]][i], dp[v[i]][i - 1] + 1, dp[2 + v[i]][i - 1] + 1});
		dp[4 + v[i]][i] = max({dp[4 + v[i]][i], dp[3 - v[i]][i - 1] + 1, dp[5 - v[i]][i - 1] + 1});
	}

	cout << max({dp[0][n], dp[1][n], dp[2][n], dp[3][n], dp[4][n], dp[5][n]}) <<'\n';

}
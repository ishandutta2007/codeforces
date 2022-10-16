#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 550;
int n, k, c[N];
bool dp[N][N][N];
vector <int> ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> c[i];

	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int l = 0; l <= k; l++)
			for(int j = 0; j <= l; j++)
				if(dp[i - 1][j][l] || j >= c[i] && dp[i - 1][j - c[i]][l - c[i]] || l >= c[i] && dp[i - 1][j][l - c[i]])
					dp[i][j][l] = 1;

	for(int i = 0; i <= k; i++)
		if(dp[n][i][k])
			ans.push_back(i);

	cout << ans << '\n';

}
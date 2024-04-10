#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 5005;
int n, k, m, t, a, b, c, dp[N][N], use[N], ant[N][N];
vector <pair<int, int> > v[N];
vector <int> ans;
 
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

void dfs(int k) {
	use[k] = 1;
	if(k == n) {

		dp[n][1] = 0;
		return;
	}
	for(auto i : v[k])
		if(!use[i.st])
			dfs(i.st);

	for(auto i : v[k]) 
		for(int j = 1; j <= n; j++)
			if(dp[k][j] > dp[i.st][j - 1] + i.nd) {
				dp[k][j] = dp[i.st][j - 1] + i.nd;
				ant[k][j] = i.st;
			}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> t;

	memset(dp, 0x3f, sizeof dp);

	for(int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}

	dfs(1);

	int lg = 0, node = 1;
	for(int i = n; i > 0; i--)
		if(dp[1][i] <= t) {
			lg = i;
			break;
		}

	while(node != n) {
		ans.push_back(node);
		node = ant[node][lg];
		lg--;
	}
	ans.push_back(n);
	cout << ans << '\n';
}
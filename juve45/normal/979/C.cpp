#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 300100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, dp[DMAX], x, y, use[DMAX], a, b;

vector <int> v[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int dfs(int k) {
	use[k] = 1;
	dp[k]++;
	for(auto i : v[k])
		if(!use[i])
			dp[k] += dfs(i);
	return dp[k];
}

bool findy(int k) {
	use[k] = 1;
	if(k == y) return 1;
	for(auto i : v[k])
		if(!use[i] && findy(i))
			return 1;
	return 0;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> x >> y;

	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(x);

	memset(use, 0, sizeof use);
	use[x] = 1;
	int ans1 = 1;
	for(auto i : v[x]) {
		if(!findy(i))
			ans1 += dp[i];
	}
	// dbg(ans1);
	// dbg(dp[y]);
	cout << 1LL * n * (n - 1) - 1LL * ans1 * dp[y];
}
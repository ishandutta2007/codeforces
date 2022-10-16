// dinamica pe arbore
#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 300100;
long long n, k, m, dp[N], w[N], use[N], a, b, c, ans;
vector <pair <long long, long long> > v[N];

void dfs(long long node) {
	long long max1 = 0, max2 = 0;
	use[node] = 1;

	for(auto i : v[node]) 
		if(!use[i.st]) {
			dfs(i.st);
			if(dp[i.st] - i.nd > max1) max2 = max1, max1 = dp[i.st] - i.nd;
			else if(dp[i.st] - i.nd > max2) max2 = dp[i.st] - i.nd;
		}
	ans = max(ans, w[node] + max1 + max2);
	dp[node] = w[node] + max1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++)
		cin >> w[i];

	for(long long i = 1; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	dfs(1);

	cout << ans << '\n';
}
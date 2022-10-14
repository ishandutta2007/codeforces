#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 998244353;
int n, m, dp[1<<22], pi[1<<22],  pm[1<<22], g[22];
void bp(int msk) {
	if(msk == -1)
		return;
	bp(pm[msk]);
	cout << pi[msk]+1 << " ";
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	if(2*m == n*(n-1)) {
		cout << 0;
		return 0;
	}
	for(int i = 0; i < n; i++) g[i] = 1<<i;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		f--, t--;
		g[f]|=1<<t;
		g[t]|=1<<f;
	}
	for(int i = 0; i < 1<<n; i++)
		dp[i] = 1e9, pi[i] = -1, pm[i] = -1;
	for(int i = 0; i < n; i++)
		dp[g[i]]=1, pi[g[i]] = i;
	for(int i = 0; i < 1<<n; i++) {
		for(int j = 0; j < n; j++) {
			if((i>>j)&1) {
				int to = i|g[j];
				if(dp[to]>dp[i]+1)
					dp[to]=dp[i]+1, pi[to]=j, pm[to]=i;
			}
		}
	}
	cout << dp[(1<<n)-1] << "\n";
	bp((1<<n)-1);
}
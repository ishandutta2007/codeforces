#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Sparse{
	vector<int>logs;
	vector<vector<int>>dp;
	int ln;
	int size;
	void init(int n, vector<int>arr){
		size = n;
		logs.resize(n+1);
		dp.resize(n+1);
		ln = 0;
		for(int i = 1; i<=n; i*=2){
			logs[i] = ln; ln++;
		}
		for(int i = 1; i<=n; i++){
			dp[i].resize(ln+1);
			logs[i] = max(logs[i],logs[i-1]);
			dp[i][0] = arr[i];
		}
		for(int i = 1; i<=ln; i++){
			for(int j = 1; j+(1<<i)-1<=n; j++){
				dp[j][i] = min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
			}
		}
	}
	int query(int l, int r){
		int lg = logs[r-l+1];
		return min(dp[l][lg],dp[r-(1<<lg)+1][lg]);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,q;
	cin >> n >> m >> q;
	vector<int>p(n+5);
	for(int i = 1; i<=n; i++){
		cin >> p[i];
	}
	p[n+1] = p[1];
	vector<int>nextnum(n+1);
	for(int i = 1; i<=n; i++){
		nextnum[p[i]] = p[i+1];
	}
	vector<int>arr(m+1);
	for(int i = 1; i<=m; i++){
		cin >> arr[i];
	}
	vector<vector<int>>ind(n+1);
	for(int i = 1; i<=m; i++){
		ind[arr[i]].push_back(i);
	}
	for(int i = 1; i<=n; i++){
		ind[i].push_back(m+1);
	}
	int ln = 20;
	vector<vector<int>>dp(m+2,vector<int>(ln));
	for(int i = 0; i<ln; i++){
		dp[m+1][i] = m+1;
	}
	for(int i = 1; i<=m; i++){
		int num = nextnum[arr[i]];
		dp[i][0] = *lower_bound(ind[num].begin(),ind[num].end(),i);
		if(dp[i][0]==i){
			dp[i][0] = *upper_bound(ind[num].begin(),ind[num].end(),i);
		}
	}
	for(int j = 1; j<ln; j++){
		for(int i = 1; i<=m; i++){
			dp[i][j] = dp[dp[i][j-1]][j-1];
		}
	}
	vector<int>dn(m+1);
	for(int i = 1; i<=m; i++){
		dn[i] = i;
		for(int j = 0; j<ln; j++){
			if((n-1)&(1<<j)){
				dn[i] = dp[dn[i]][j];
			}
		}
	}
	Sparse sparse;
	sparse.init(m,dn);
	while(q--){
		int l,r;
		cin >> l >> r;
		int v = sparse.query(l,r);
		if(v<=r)cout << 1;
		else cout << 0;
	}
	cout << "\n";
	return 0;
}
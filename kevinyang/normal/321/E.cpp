#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int>>psa(4005,vector<int>(4005));
vector<vector<int>>dp(805,vector<int>(4005,(int)1e9));
void f(int t, int lx, int rx, int l, int r){// l and r represent the boundaries of best possible index to stop at from previous gondola
	//lx and rx represent interval we are calculating
	//[lx,rx)
	//[l,r)
	if(lx>=rx)return;
	int idx = 0;
	int ans = (int)1e9;
	int m = (lx+rx)/2;
	for(int i = l; i<r; i++){
		int v = dp[t-1][i]+psa[m][m]-psa[m][i]-psa[i][m]+psa[i][i];
		if(v<ans){
			ans = v;
			idx = i;
		}
	}
	dp[t][m] = ans;
	if(rx-lx==1)return;
	f(t,lx,m,l,idx+1);
	f(t,m,rx,idx,r);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin >> psa[i][j];
			psa[i][j] += psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
		}
	}
	dp[0][0] = 0;
	for(int i = 1; i<=k; i++){
		f(i,1,n+1,0,n+1);
	}

	cout << dp[k][n]/2 << "\n";
	return 0;
}
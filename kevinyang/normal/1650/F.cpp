#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int e,t,p,i;
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int>a(n+1);
		for(int i = 1; i<=n; i++){
			cin >> a[i];
		}
		vector<node>arr(m+1);
		for(int i = 1; i<=m; i++){
			int x,y,z;
			cin >> x >> y >> z;
			arr[i] = {x,y,z,i};
		}
		vector<vector<node>>vals(n+1);
		for(int i = 1; i<=m; i++){
			vals[arr[i].e].push_back(arr[i]);
		}
		vector<vector<int>>seq(n+1);
		vector<int>amt(n+1);
		bool flag = true;
		for(int i = 1; i<=n; i++){
			int len = vals[i].size();
			if(len==0)flag = false;
			vector<vector<int>>dp(len+1,vector<int>(201,(int)1e9+5));
			vector<vector<int>>pre(len+1,vector<int>(201));
			dp[0][0] = 0;
			for(int j = 1; j<=len; j++){
				int t = vals[i][j-1].t; int p = vals[i][j-1].p;
				for(int k = 0; k<=100; k++){
					if(dp[j][k+p]>dp[j-1][k]+t){
						dp[j][k+p] = dp[j-1][k]+t;
						pre[j][k+p] = vals[i][j-1].i;
					}
				}
				for(int k = 0; k<=200; k++){
					if(dp[j][k]>dp[j-1][k]){
						dp[j][k] = dp[j-1][k];
						pre[j][k] = 0;
					}
				}
			}
			int num = (int)1e9+5; int idx = 0;
			for(int j = 100; j<=200; j++){
				if(dp[len][j]<num){
					num = dp[len][j]; idx = j;
				}
			}
			if(num>(int)1e9){
				flag = false;
			}
			for(int j = len; j>=1; j--){
				if(pre[j][idx]==0){
					continue;
				}
				amt[i]+=arr[pre[j][idx]].t;
				seq[i].push_back(pre[j][idx]);
				idx-=arr[pre[j][idx]].p;
			}

		}
		if(!flag){
			cout << "-1\n";
			continue;
		}
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+amt[i];
			if(psa[i]>a[i]){
				flag = false;
			}
		}
		if(!flag){
			cout << "-1\n";
			continue;
		}
		vector<int>ans;
		for(int i = 1; i<=n; i++){
			for(int nxt: seq[i]){
				ans.push_back(nxt);
			}
		}
		cout << ans.size() << "\n";
		for(int nxt: ans){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}
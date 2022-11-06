#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int mxn = 200005;
vector<vector<int>>adj(mxn);
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 2; i<=n; i++){
		int x;
		cin >> x;
		adj[x].push_back(i);
	}
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int low = -1; int high = (int)1e18; int mid = (low+high)/2;
	while(low+1<high){
		bool f = true;
		vector<int>dp(n+1);//maximum you can take
		for(int i = n; i>=1; i--){
			if(adj[i].size()==0){
				dp[i] = mid-arr[i];
				if(dp[i]<0)f = false;
				continue;
			}
			int sum = 0;
			for(int nxt: adj[i]){
				sum+=dp[nxt];
				sum = min(sum,(int)1e18);
			}
			sum-=arr[i];
			dp[i] = sum;
			if(dp[i]<0)f = false;
		}
		if(f)high = mid;
		else low = mid;
		mid = (low+high)/2;
	}
	cout << high << "\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int r,n;
	cin >> r >> n;
	vector<int>time(n+1);
	vector<pair<int,int>>pos(n+1);
	pos[0] = {1,1};
	for(int i = 1; i<=n; i++){
		cin >> time[i];
		int x,y;
		cin >> x >> y;
		pos[i] = {x,y};
	}
	vector<int>dp(n+1);
	vector<int>mx(n+1);
	for(int i = 1; i<=n; i++){
		dp[i] = (int)-1e9;
		mx[i] = (int)-1e9;
	}
	int start = 0;
	int ans = 0;
	for(int i = 1; i<=n; i++){
		for(int j = max(0LL,i-1005); j<i; j++){
			if(time[i]-time[j]>=abs(pos[j].first-pos[i].first)+abs(pos[j].second-pos[i].second)){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		if(i>=1004)dp[i] = max(dp[i],mx[i-1004]+1);
		mx[i] = max(dp[i],mx[i-1]);
	}
	cout << mx[n] << "\n";
	return 0;
}
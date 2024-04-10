#include <bits/stdc++.h>
using namespace std;
#define int long long
int sq = 320;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<pair<int,int>>dp(n+1);//first val is index that it goes to second val is the number of jumps or length
	for(int i = n; i>=1; i--){
		int nxt = arr[i]+i;
		if(nxt>n){
			dp[i] = {i,0};
		}
		else{
			if(nxt/sq>i/sq){
				dp[i] = {nxt,1};
			}
			else{
				dp[i] = dp[nxt];
				dp[i].second++;
			}
		}
	}
	while(m--){
		int cm;
		cin >> cm;
		if(cm==0){
			int a,b;
			cin >> a >> b;
			arr[a] = b;
			for(int i = a; i>=1; i--){
				if(i/sq!=a/sq)break;
				int nxt = arr[i]+i;
				if(nxt>n){
					dp[i] = {i,0};
				}
				else{
					if(nxt/sq>i/sq){
						dp[i] = {nxt,1};
					}
					else{
						dp[i] = dp[nxt];
						dp[i].second++;
					}
				}
			}
		}
		else{
			int a;
			cin >> a;
			int ans = 0;
			while(dp[a].second!=0){
				ans+=dp[a].second;
				a = dp[a].first;
			}
			cout << a << " ";
			cout << ans+1 << "\n";
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 507;
const ll INF = 1e18;
ll dp[N][N][N];
int A[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	for(int i = 0;i<=n;i+=1){
		for(int j = 0;j<=n;j+=1){
			for(int k = 0;k<=n;k+=1){
				dp[i][j][k] = -INF;
			}
		}
	}
	dp[0][0][0] = 0;
	for(int i = 1;i<=n;i+=1){
		for(int ops = 0;ops<i;ops+=1){
			ll big1 = -INF;
			for(int mx = 0;mx<=n;mx+=1){
				dp[i][ops+1][mx] = max(dp[i][ops+1][mx],dp[i-1][ops][mx] + A[mx]);
				if (mx<i){
					big1 = max(big1,dp[i-1][ops][mx]);
				}
			}
			ll big2 = -INF;
			for(int k = i;k<=n && ops+k-i-1<=i;k+=1){
				dp[i][ops+k-i][k] = max(dp[i][ops+k-i][k],big1+A[k]);
				dp[i][ops+k-i][k] = max(dp[i][ops+k-i][k],big2+A[k]);
				big2 = max(big2,dp[i-1][ops][k]);
			}
		}
	}
	ll res = 0;
	for(int ops = 0;ops<=n;ops+=1){
		for(int mx = 0;mx<=n;mx+=1){
			res = max(res,dp[n][ops][mx]);
		}
	}
	cout<<res<<endl;
}
signed main(){
	int t = 1;
	while(t--){
		solve();
	}
}
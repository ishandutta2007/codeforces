#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
const int N = 2e5+7;
const int MOD = 998244353;
int dp[N],ans[N],cnt[N];
void solve(){
	int n;
	ll k;
	cin>>n>>k;
	dp[0] = 1;
	ll sum = 0;
	for(int move = 0;sum + move + k <=n;move += 1){
		sum += move + k;
		int cp = 0;
		for(int i = 0;i<=n;i+=1){
			
			cnt[cp] = cnt[cp]+dp[i];
			if (cnt[cp]>=MOD){
				cnt[cp] -= MOD;
			}
			dp[i] = cnt[cp]+MOD-dp[i];
			while(dp[i]>=MOD){
				dp[i] -= MOD;
			}
			ans[i] = ans[i]+dp[i];
			if (ans[i]>=MOD){
				ans[i] -= MOD;
			}
			cp += 1;
			if (cp==k+move){
				cp = 0;
			}
		}
		for(int i = 0;i<k+move;i+=1){
			cnt[i] = 0;
		}
	}
	for(int i = 1;i<=n;i+=1){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
signed main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}
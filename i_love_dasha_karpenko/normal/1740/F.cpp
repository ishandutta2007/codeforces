#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define div dsfd
typedef long long ll;
const int N = 2007;
const int MOD = 998244353;
int cnt[N],add[N];
int dp[2][N][N],sum[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		int x;
		cin>>x;
		cnt[x] += 1;
	}
	for(int i = 1;i<=n;i+=1){
		add[cnt[i]] += 1;
	}
	for(int i = n;i>=1;i-=1){
		add[i] += add[i+1];
	}
	dp[0][n][0] = 1;
	int res = 0;
	//cout<<"GGG "<<add[3]<<endl;
	int csum = 0;
	for(int i = 1;i<=n;i+=1){
	//	cout<<add[i]<<' ';
		for(int a = 0;a<=n;a+=1){
			sum[a] = 0;
		}
		csum += add[i];
		int lim = n/i,plim = n/max(1,(i-1));
		for(int prev = plim;prev>lim;prev-=1){
			for(int left = 0;left<=csum;left+=1){
				sum[left] += dp[0][prev][left];
				if (sum[left]>=MOD){
					sum[left] -= MOD;
				}
			}
		}
		for(int prev = lim;prev>=1;prev-=1){
			for(int left = 0;left<=csum;left+=1){
				sum[left] += dp[0][prev][left];
				if (sum[left]>=MOD){
					sum[left] -= MOD;
				}
			}
			for(int left = 0;left<=csum;left+=1){
				if (0<=left+prev-add[i] && left+prev-add[i]<=n){
					dp[1][prev][left] += sum[left+prev-add[i]];
					if (dp[1][prev][left]>=MOD){
						dp[1][prev][left] -= MOD;
					}
				}
			}
		}
	//	cout<<dp[1][3][1]<<endl;
		for(int a = 1;a<=lim;a+=1){
			if (add[i+1]==0){
				//if (i==3){
				//	cout<<"GDB "<<a<<' '<<dp[1][a][0]<<endl;
				//}
				res += dp[1][a][0];
				if (res>=MOD){
					res -= MOD;
				}
			}
			for(int b = 0;b<=csum;b+=1){
				dp[0][a][b] = dp[1][a][b];
				dp[1][a][b] = 0;
			}
		}
	}
	//cout<<endl;
	cout<<res<<endl;
}
signed main(){

	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
}
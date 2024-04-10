#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,C[1010][1010];
inline void Plus(int &x,int y){
	(x+=y)>=mod?x-=mod:233;
}
int Solve(ll lim,ll X){
	static int dp[66][2333][2];
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<=60;++i){
		int c=lim>>i&1;
		for(int j=0;j<2333;++j){
			for(int o=0;o<2;++o){
				int w=dp[i][j][o];
				if(!w)continue;
				for(int k=0;k<=n;++k){
					if((k&1)!=(X>>i&1))continue;
					int nj=(j+k)>>1;
					int tt=(j+k)&1;
					Plus(dp[i+1][nj][(tt>c)||(tt==c&&o)],1LL*dp[i][j][o]*C[n][k]%mod);
				}
			}
		}
	}
	return dp[61][0][0];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll l,r,X;
	cin>>n>>l>>r>>X;
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	cout<<(Solve(r,X)-Solve(l-1,X)+mod)%mod<<'\n';
	return 0;
}
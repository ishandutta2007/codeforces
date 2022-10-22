#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
const LL INF=1e18;
int n;
LL c[210][210];
LL p[210][210];
LL ned[210][210];
LL dp[210][210];
int fa[210];
void sol(int i,int j,int F){
	if(i>j) return;
	if(i==j) {
		fa[i]=F;
		return;
	}
	LL now;
	for(int k=i;k<=j;++k){
		now=dp[i][k-1]+dp[k+1][j]+ned[i][k-1]+ned[k+1][j];
		if(now==dp[i][j]){
			fa[k]=F;
			sol(i,k-1,k);
			sol(k+1,j,k);
			return;
		}
	}
	return;
}
void MAIN(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>c[i][j];
		}
		p[i][0]=0;
		for(int j=1;j<=n;++j){
			p[i][j]=c[i][j]+p[i][j-1];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(k>=i&&k<=j) continue;
				ned[i][j]+=p[k][j]-p[k][i-1];
			}
		}
	}
	
	for(int i=0;i<=n+1;++i){
		for(int j=0;j<=n+1;++j){
			if(i>=j) dp[i][j]=0;
			else dp[i][j]=INF;
		}
	}
	for(int len=2;len<=n;++len){
		for(int i=1,j=len;j<=n;++i,++j){
			for(int k=i;k<=j;++k){
				dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+ned[i][k-1]+ned[k+1][j]);
			}
		}
	}
//	cout<<dp[1][n]<<"\n";
	sol(1,n,0);
	for(int i=1;i<=n;++i) cout<<fa[i]<<" ";cout<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ttt=1;//cin>>ttt;
	while(ttt--) MAIN();
	return 0;
}
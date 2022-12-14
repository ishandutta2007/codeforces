#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 105
#define pb push_back
#define pn cout<<"No\n";
#define py cout<<"Yes\n";
bool vis[N][N][N];
int i,j,p;
ll dp[N][N][N],C[N][N];
ll CAL(int n,int m,int k){
	if(vis[n][m][k])return dp[n][m][k];
	if(k&&m+k-1>n)return 0;
	if(!n)return k==0;
	vis[n][m][k]=1;
	if(m==1&&k!=1)return 0;
	if(m==1&&k==1){
		ll ans=1;
		for(int i=1;i<=n;++i)ans=ans*i%p;
		return dp[n][m][k]=ans;
	}
	int i,j;
	for(i=1;i<=n;++i){
		int mx=min(i-1,k),mn=max(0,k-n+i);
		for(j=mn;j<=mx;++j){ 
			(dp[n][m][k]+=CAL(i-1,m-1,j)*CAL(n-i,m-1,k-j)%p*C[n-1][i-1])%=p;
		}
	}
	return dp[n][m][k];
} 
int n,m,k;
int main(){
	cin>>n>>m>>k>>p;if(p==1)return cout<<0,0;
	for(i=C[0][0]=1;i<=n;++i){
		for(j=C[i][0]=1;j<=n;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
		}
	}
	cout<<CAL(n,m,k); 
}
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=4009;
int n,k;
int v[M][M],dp[M],g[M];
void solve(int l,int r,int x,int y){
	if(l>r)return;
	int mid=(l+r)>>1;
	int p=x;
	for(int i=x;i<=min(y,mid-1);++i){
		if(g[p]+v[p+1][mid]>g[i]+v[i+1][mid])p=i;
	}
	dp[mid]=g[p]+v[p+1][mid];
	solve(l,mid-1,x,p);
	solve(mid+1,r,p,y);
}
inline int getint(){
	char c;
	while((c=getchar())<'0'||c>'9');return c-'0';
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)v[i][j]=getint();
		for(int j=i+1;j<=n;++j)v[i][j]=v[i][j-1]+v[i][j];
	}
	for(int j=n;j>=1;--j){
		for(int i=j-1;i>=1;--i){
			v[i][j]+=v[i+1][j];
		}
	}
	memset(g,0X3f,sizeof(g));
	g[0]=0;
	for(int i=1;i<=min(k,n);++i){
		memset(dp,0X3f,sizeof(dp));
		solve(1,n,0,n);
		memcpy(g,dp,sizeof(dp));
	}
	cout<<dp[n]<<"\n";
	return 0;
}
/*
23323
1
4
*/
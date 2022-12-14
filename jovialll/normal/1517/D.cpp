#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 
#include<bits/stdc++.h>
using namespace std;
#define N 505
#define pb push_back
#define ll long long
#define mod 998244353
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int T,n,X,Y,m,k,ans,ex,v,e,ey,ux,I,uy,a[N][N],b[N][N],dp[N][N][12],i,j,x,y,ii;
void Min(int &x,int y){x>y&&(x=y);}
int solve(int x,int y,int g){
	if(!g)return 0;
	if(dp[x][y][g])return dp[x][y][g];
	dp[x][y][g]=1e9;
	if(x>1)dp[x][y][g]=min(dp[x][y][g],solve(x-1,y,g-1)+b[x-1][y]);
	if(x<n)dp[x][y][g]=min(dp[x][y][g],solve(x+1,y,g-1)+b[x][y]);
	if(y>1)dp[x][y][g]=min(dp[x][y][g],solve(x,y-1,g-1)+a[x][y-1]);
	if(y<m)dp[x][y][g]=min(dp[x][y][g],solve(x,y+1,g-1)+a[x][y]);
	return dp[x][y][g];
}
int main(){
	cin>>n>>m>>k;
	if(k&1){
		for(i=1;i<=n;cout<<"\n",++i)for(j=1;j<=m;++j)cout<<"-1 ";return 0;
	} 
	k>>=1;memset(a,0x3f,sizeof(a));memset(b,0x3f,sizeof(b));
	for(i=1;i<=n;++i)for(j=1;j<m;++j)cin>>a[i][j];
	for(i=1;i<n;++i)for(j=1;j<=m;++j)cin>>b[i][j];
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			cout<<(solve(i,j,k)*2)<<" ";
		}cout<<"\n";
	}
}
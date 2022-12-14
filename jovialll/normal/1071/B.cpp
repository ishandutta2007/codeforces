#include<bits/stdc++.h>
using namespace std;
#define py puts("Yes\n")
#define pn puts("No\n")
#define N 2005
struct dot{int x,y;}e[N*N];
struct ttt{int x,y;char c;}ur[N];
int T,n,i,j,k,ans,las,a[N],cnt,f0,f1,dp[N][N],tot,x[N],y[N],g[N],f[N][N],pm[N][N];
char s[N][N];
inline bool cmp(int xx,int yy){
	int i1=x[xx],j1=y[xx],i2=x[yy],j2=y[yy];
	while(i1+j1<=n+n){
		if(s[i1][j1]!=s[i2][j2])return s[i1][j1]<s[i2][j2];
		if(f[i1][j1])++j1;else ++i1;
		if(f[i2][j2])++j2;else ++i2;
	}
	return 0;
}
inline bool CC(dot aa,dot bb){return aa.x+aa.y<bb.x+bb.y;}
inline bool ccmp(ttt aa,ttt bb){return aa.c==bb.c?(min(pm[aa.x+1][aa.y],pm[aa.x][aa.y+1])<min(pm[bb.x+1][bb.y],pm[bb.x][bb.y+1])):aa.c<bb.c;}
int main(){
	cin>>n>>k;
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)e[++tot].x=i,e[tot].y=j;
	sort(e+1,e+tot+1,CC);
	pm[n][n]=0;
	for(i=1;i<=n+1;++i)pm[i][n+1]=pm[n+1][i]=1e9;
	for(i=tot-1;i;--i){
		if(e[i].x+e[i].y!=e[i+1].x+e[i+1].y){
			for(f0=0,j=i+1;j<=las;++j){
				++f0;
				ur[f0].c=s[e[j].x][e[j].y];
				ur[f0].x=e[j].x;
				ur[f0].y=e[j].y;
			}
			sort(ur+1,ur+f0+1,ccmp);
			f1=0;
			for(j=2;j<=f0;++j){
				if(ur[j].c!=ur[j-1].c||(min(pm[ur[j].x+1][ur[j].y],pm[ur[j].x][ur[j].y+1])!=min(pm[ur[j-1].x+1][ur[j-1].y],pm[ur[j-1].x][ur[j-1].y+1])))++f1;
				pm[ur[j].x][ur[j].y]=f1;
			}
			las=i;
		}
	}
	for(i=1;i<n;++i)f[i][n]=0,f[n][i]=1;
	for(i=1;i<n;++i){
		for(j=1;j<n;++j){
			if(s[i+1][j]>s[i][j+1])f[i][j]=1;
			else if(s[i+1][j]<s[i][j+1])f[i][j]=0;
			else{
				if(pm[i+1][j]>pm[i][j+1])f[i][j]=1;
				else f[i][j]=0;
			}
		}
	}
	for(i=1;i<=n;++i)dp[1][i]=dp[1][i-1]+(s[1][i]=='a');
	for(i=2;i<=n;++i){
		dp[i][1]=dp[i-1][1]+(s[i][1]=='a');
		for(j=2;j<=n;++j){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(s[i][j]=='a');
		}
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(i+j-1-dp[i][j]<=k)ans=max(ans,i+j);
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j)
			if(i+j>ans&&i-2+j-max(dp[i-1][j],dp[i][j-1])==k)x[++cnt]=i,y[cnt]=j,g[cnt]=cnt;
	}
	sort(g+1,g+cnt+1,cmp);
	for(i=1;i<ans;++i)cout<<"a";
	i=x[g[1]];j=y[g[1]];
	if(i+j>ans){
		while(i+j<=n+n){
			cout<<s[i][j];
		if(f[i][j])++j;else ++i;
			
		}
	}
}
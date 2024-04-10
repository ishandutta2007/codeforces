#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
const int maxn=2e5+10;
const int mod=998244353;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
const int N=5e3+5;
int n,k,dp[N][N],ans,dep[N],sum[N][N];
int beg[N],nex[N<<1],to[N<<1],e;
inline void add(int x,int y){
	e++;nex[e]=beg[x];beg[x]=e;to[e]=y;
	e++;nex[e]=beg[y];beg[y]=e;to[e]=x;
}
inline void Add(int &x,int y){x=(x+y>=mod?x+y-mod:x+y);}
inline void dfs(int x,int fa){
	dep[x]=dep[fa]+1;dp[x][dep[x]]=1;
	for(int i=1;i<=n;i++)
		sum[x][i]=sum[x][i-1],Add(sum[x][i],dp[x][i]);
	for(int i=beg[x];i;i=nex[i]){
		int t=to[i];
		if(t==fa)continue;
		dfs(t,x);
		for(int j=1;j<=n;j++)
			dp[x][j]=1ll*dp[x][j]*(sum[t][n]+sum[t][min(j,2*dep[x]+k-j)])%mod;
		for(int j=1;j<=n;j++){
			//if(j==2)printf("%d\n",1ll*dp[t][j]*sum[x][min(j-1,2*dep[x]+k-j)]%mod);
			Add(dp[x][j],1ll*dp[t][j]*sum[x][min(j-1,2*dep[x]+k-j)]%mod);
		}
		for(int j=1;j<=n;j++)
			sum[x][j]=sum[x][j-1],Add(sum[x][j],dp[x][j]);
		//for(int j=1;j<=n;j++)
		//	printf("dp[%d][%d]=%d\n",x,j,dp[x][j]);
	}
//	for(int i=1;i<=n;i++)
//		printf("dp[%d][%d]=%d\n",x,i,dp[x][i]);
}
int main(){
	n=read(),k=read();
	for(int i=1,x,y;i<n;i++)
		x=read(),y=read(),add(x,y);
	dfs(1,0);
	for(int i=1;i<=n&&i<=k+1;i++)
		Add(ans,dp[1][i]);
	printf("%d\n",ans);
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=300010;
struct edge{
	int next,to,w;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y,int z){
	e[++len]=(edge){head[x],y,z};
	head[x]=len;
}
int i,j,k,n,m,T,c[maxn];ll dp[maxn][3];
ll ans=0ll;
void dfs(int now,int fa){
	dp[now][0]=c[now];dp[now][2]=c[now];
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		dfs(u,now);
		if(dp[u][0]+c[now]-e[i].w>dp[now][0]){
			dp[now][2]=dp[now][0];
			dp[now][0]=dp[u][0]+c[now]-e[i].w;
			dp[now][1]=u;
		}else
		if(dp[u][0]+c[now]-e[i].w>dp[now][2])
			dp[now][2]=dp[u][0]+c[now]-e[i].w;
	}ans=max(ans,(ll)dp[now][0]+dp[now][2]-c[now]);
	//cout<<dp[now][0]<<' '<<dp[now][1]<<' '<<dp[now][2]<<endl;
}
/*
void dfs(int now,int fa,ll up){
	ans=max(ans,up+dp[now][0]);
	for(int i=head[now];i;i=e[i].next){
		
	}
}
*/
int main(){
	cin>>n;
	for(i=1;i<=n;i++)c[i]=read();
	for(i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}dfs(1,0);//dfs2(1,0,0ll);
	cout<<ans<<endl;
}
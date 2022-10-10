#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=600010,mod=998244353;
struct edge{
	int next,to,w;
}e[maxn*2];
int head[maxn],len;
map<pair<pii,int>,bool>P;
void add(int x,int y,int z){
	if(P[make_pair(make_pair(x,y),z)])return;
	P[make_pair(make_pair(x,y),z)]=1;
	e[++len]={head[x],y,z};
	head[x]=len;
}
int i,j,k,n,m,T,size[maxn],cnt,num[maxn],vis[maxn],flag,w;
ll dp[maxn];
map<int,int>M;
void dfs(int now,int fa,int s=-1){
	//cout<<now<<' '<<fa<<' '<<s<<endl;
	if(vis[now]){flag=false;return;}
	vis[now]=1;++w;
	int len=0,is[2]={0,0};
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		is[e[i].w]++;
		if(u==fa && e[i].w+s==1)continue;
		dfs(u,now,e[i].w);
	}
	if(is[0]>=2 || is[1]>=2)flag=false;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		int len=read(),last=0;
		for(j=1;j<=len;j++){
			int now=read();
			if(last)add(last,now,1),add(now,last,0);
			last=now;
		}
	}
	for(i=1;i<=k;i++){
		if(vis[i])continue;
		flag=true;w=0;
		dfs(i,0);
		if(flag){
			if(M[w])num[M[w]]++;
			else num[M[w]=++cnt]=1,size[cnt]=w;
		}
	}
	dp[0]=1;
	for(j=0;j<=m;j++){
		for(i=1;i<=cnt;i++){
			if(j+size[i]>m)continue;
			//cout<<"i="<<i<<' '<<size[i]<<' '<<num[i]<<endl;
			dp[j+size[i]]+=dp[j]*num[i]%mod;
			dp[j+size[i]]%=mod;
		}
	}cout<<dp[m]<<endl;
}
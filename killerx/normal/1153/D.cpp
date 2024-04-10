#include<bits/stdc++.h>
#define ll long long
#define MP make_pair
#define PB push_back
using namespace std;
namespace io{
	const int Sz=1<<13;
	char ibuf[Sz],*ed=ibuf+Sz,*ips=ed-1;
	int getchar(){
		if(++ips==ed)ed=ibuf+fread(ips=ibuf,1,Sz,stdin);
		if(ips<ed)return*ips;else return EOF;
	}
}
#define getchar io::getchar
int read(){
	int x=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f^=1;
	for(; isdigit(c);c=getchar())x=x*10+c-48;
	return f?x:-x;
}
const int N=1<<20;
namespace g{
	int head[N],nxt[N],to[N],tot;
	void ini(){
		memset(head,-1,sizeof head);
		tot=0;
	}
	inline void add(int u,int v){
		nxt[tot]=head[u];head[u]=tot;
		to[tot]=v;++tot;
	}
}
int n;
int tp[N];
int cnt[N],dp[N];
int fa[N];
const int inf=0x3f3f3f3f;
void dfs(int u,int p){
	bool isleaf=1;
	if(tp[u]==0){
		dp[u]=0;
	}else{
		dp[u]=inf;
	}
	for(int e=g::head[u];~e;e=g::nxt[e]){
		int v=g::to[e];if(v!=p){
			isleaf=0;
			dfs(v,u);
			cnt[u]+=cnt[v];
			if(tp[u]==0){
				dp[u]+=cnt[v]-dp[v]+1;
			}else{
				dp[u]=min(dp[u],cnt[v]-dp[v]+1);
			}
		}
	}
	if(isleaf){
		cnt[u]=1;
		dp[u]=1;
	}else{
		if(tp[u]==0){
			dp[u]=cnt[u]-dp[u]+1;
		}else{
			dp[u]=cnt[u]-dp[u]+1;
		}
	}
	// cerr<<u<<" "<<cnt[u]<<" "<<dp[u]<<endl;
}
int main(){
	g::ini();
	n=read();
	for(int i=0;i<n;++i)tp[i]=read();
	for(int i=1;i<n;++i){
		fa[i]=read()-1;
		g::add(fa[i],i);
	}
	dfs(0,-1);
	printf("%d\n",dp[0]);
	return 0;
}
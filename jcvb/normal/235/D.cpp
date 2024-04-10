#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef double db;
struct edge{
	int v,next;
}e[6005];int etot=0;int g[3005];
void ae(int u,int v){e[etot].v=v;e[etot].next=g[u];g[u]=etot++;}
int n;
db ans=0.0;
int pre[3005],vis[3005];
int cyc[3005],len=0;
int oncy[3005]={0};
int dfs(int u){
	vis[u]=1;
	for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
		if(!vis[e[i].v]){
			pre[e[i].v]=u;
			if(dfs(e[i].v))return 1;
		}else{
			int p=u;
			while(1){
				cyc[++len]=u;
				oncy[u]=len;
				if(u==e[i].v)break;
				u=pre[u];
			}
			return 1;
		}
	}return 0;
}
int dis[3005];
int belong[3005],tot=0;
void dfs1(int u,int pre=-1){
	belong[u]=tot;
	for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre && !oncy[e[i].v]){
		dis[e[i].v]=dis[u]+1;
		dfs1(e[i].v,u);
	}
}
int cur;
void dfs2(int u,int pre,int d){
	ans+=1.0/d;
	for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre && belong[e[i].v]==cur){
		dfs2(e[i].v,u,d+1);
	}
}
int main()
{
	memset(g,-1,sizeof(g));
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);x++,y++;
		ae(x,y);ae(y,x);
	}
	dfs(1);
	for (int i=1;i<=len;i++)tot++,dfs1(cyc[i]);
	for (int i=1;i<=n;i++){
		cur=belong[i];dfs2(i,-1,1);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)if(belong[i]!=belong[j]){
			int tot=dis[i]+dis[j]+len,a=abs(belong[i]-belong[j])-1,b=len-2-a;
			ans+=1.0/tot*(1+a*1.0/(tot-a)+b*1.0/(tot-b));
		}
	printf("%.10lf\n",ans);
	return 0;
}
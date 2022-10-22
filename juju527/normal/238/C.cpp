#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
struct Edge{
	int to,w,nxt;
}e[2*maxn];
int cnt;
int head[maxn];
bool ban[2*maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
void add(int u,int v,int w){
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
int sum=0;
void dfs1(int x,int fa){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		if(ban[i])continue;
		int tmp=e[i].to;
		if(tmp==fa)continue;
		sum+=e[i].w;
		dfs1(tmp,x);
	}
	return ;
}
int d[maxn];
int X,dis=0x3f3f3f3f;
void dfs2(int x,int fa){
	if(x!=X&&dis>d[x])dis=d[x];
	for(int i=head[x];i!=-1;i=e[i].nxt){
		if(ban[i])continue;
		int tmp=e[i].to;
		if(tmp==fa)continue;
		d[tmp]=d[x]+(e[i].w?-1:1);
		dfs2(tmp,x);
	}
	return ;
}
int main(){
	int n;
	n=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v,0);
		add(v,u,1);
	}
	int ans=n;
	for(int i=1;i<=n;i++){
		sum=0;dfs1(i,0);
		ans=min(ans,sum);
	}
	for(int i=1;i<=n;i++){
		for(int j=head[i];j!=-1;j=e[j].nxt){
			int tmp=e[j].to;
			if(tmp<i)continue;
			ban[j]=ban[j^1]=1;
			sum=0;dfs1(i,0);dfs1(tmp,0);
			X=i;dis=0x3f3f3f3f;
			d[i]=0;
			dfs2(i,0);
			sum+=dis;
			X=i;dis=0x3f3f3f3f;
			d[tmp]=0;
			dfs2(tmp,0);
			sum+=dis;
			ban[j]=ban[j^1]=0;
			ans=min(ans,sum);
		}
	}
	printf("%d\n",ans);
	return 0;
}
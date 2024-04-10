#include<bits/stdc++.h>
using namespace std;
const int maxn=10005,maxm=2005,inf=0x3f3f3f3f;
struct Edge{
	int to,w;
	int nxt;
}e[2*(maxm*10+maxm+maxn)];
int cnt;
int head[maxm+maxn];
int s,t;
int p[maxn];
int lev[maxm+maxn];
queue<int>q;
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
bool bfs(){
	memset(lev,0,sizeof(lev));
	while(!q.empty())q.pop();
	q.push(s);
	lev[s]=1;
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for(int i=head[k];i!=-1;i=e[i].nxt){
			int tmp=e[i].to;
			if(e[i].w==0||lev[tmp])continue;
			lev[tmp]=lev[k]+1;
			q.push(tmp);
			if(tmp==t)return 1;
		}
	}
	return 0;
}
int dinic(int x,int flow){
	if(x==t)return flow;
	int rest=flow;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		if(!rest)break;
		int tmp=e[i].to;
		if(e[i].w==0||lev[tmp]!=lev[x]+1)continue;
		int inc=dinic(tmp,min(rest,e[i].w));
		if(!inc)lev[tmp]=0;
		e[i].w-=inc;
		e[i^1].w+=inc;
		rest-=inc;
	}
	return flow-rest;
}
int main(){
	int n,m,g,ans=0;
	n=read();m=read();g=read();
	s=1;t=n+m+2;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<=n;i++){
		int x;
		x=read();
		if(!p[i]){
			add(s,i+1,x);
			add(i+1,s,0);
		}
		else{
			add(i+1,t,x);
			add(t,i+1,0);
		}
	}
	for(int i=1;i<=m;i++){
		int x,w,k,opt;
		x=read();w=read();k=read();
		ans+=w;
		for(int j=1;j<=k;j++){
			int tmp;
			tmp=read();
			if(!x){
				add(i+n+1,tmp+1,inf);
				add(tmp+1,i+n+1,0);
			}
			else{
				add(tmp+1,i+n+1,inf);
				add(i+n+1,tmp+1,0);
			}
		}
		opt=read();
		int c=w+opt*g;
		if(!x){
			add(s,i+n+1,c);
			add(i+n+1,s,0);
		}
		else{
			add(i+n+1,t,c);
			add(t,i+n+1,0);
		}
	}
	int maxflow=0;
	while(bfs()){
		int flow=dinic(s,inf);
		while(flow){
			maxflow+=flow;
			flow=dinic(s,inf);
		}
	}
	printf("%d",ans-maxflow);
	return 0;
}
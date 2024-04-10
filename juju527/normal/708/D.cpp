#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105,maxm=105,inf=0x3f3f3f3f;
int n,m,s,t;
struct Edge{int to,w,c,nxt;}e[6*maxm+2*maxn];
int cnt;
int head[maxn];
int in[maxn],out[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w,int c){
	e[cnt]=(Edge){v,w,c,head[u]};
	head[u]=cnt++;
	return ;
}
int dis[maxn],inc[maxn],pre[maxn];
bool vis[maxn];
queue<int> q;
bool spfa(){
	for(int i=s;i<=t;i++)dis[i]=inf;
	while(q.size())q.pop();
	q.push(s);inc[s]=inf;dis[s]=0;vis[s]=1;
	while(q.size()){
		int k=q.front();
		q.pop();
		vis[k]=0;
		for(int i=head[k];i!=-1;i=e[i].nxt){
			int tmp=e[i].to,co=e[i].c,w=e[i].w;
			if(dis[tmp]<=dis[k]+e[i].c||!w)continue;
			dis[tmp]=dis[k]+e[i].c;
			inc[tmp]=min(inc[k],w);
			pre[tmp]=i;
			if(!vis[tmp])q.push(tmp),vis[tmp]=1;
		}
	}
	return dis[t]<inf;
}
int mincost=0;
void update(){
	int x=t;mincost+=dis[t]*inc[t];
	while(x^s){
		int ed=pre[x];
		e[ed].w-=inc[t],e[ed^1].w+=inc[t];
		x=e[ed^1].to;
	}
	return ;
}
int main(){
	n=read();m=read();s=0,t=n+1;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int u,v,c,f;
		u=read();v=read();c=read();f=read();
		out[u]+=f,in[v]+=f;
		if(f<=c){
			add(u,v,c-f,1),add(v,u,0,-1);
			add(u,v,inf,2),add(v,u,0,-2);
			add(v,u,f,1),add(u,v,0,-1);
		}
		else{
			mincost+=f-c;
			add(u,v,inf,2),add(v,u,0,-2);
			add(v,u,f-c,0),add(u,v,0,0);
			add(v,u,c,1),add(u,v,0,-1);
		}
	}
	add(n,1,inf,0),add(1,n,0,0);
	for(int i=1;i<=n;i++)
		if(in[i]>out[i])add(s,i,in[i]-out[i],0),add(i,s,0,0);
    	else if(out[i]>in[i])add(i,t,out[i]-in[i],0),add(t,i,0,0);
	while(spfa())update();
	printf("%d\n",mincost);
	return 0;
}
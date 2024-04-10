#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int maxn=505,maxm=5010,inf=1e8;
int n,r1,r2,s,t,S,T;
struct Edge{int to,w,c,nxt;}e[maxm];
int cnt,head[2*maxn];
int a[maxn];
int in[2*maxn],out[2*maxn];
vector<int> g[2*maxn];
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
int f[2*maxn],p[2*maxn];
void dfs(int x,int fa){
	f[x]=fa;
	for(int i=0;i<g[x].size();i++){
		int tmp=g[x][i];
		if(tmp==fa)continue;
		dfs(tmp,x);
	}
	return ;
}
bool ban[maxm];
int inc[2*maxn],dis[2*maxn],pre[2*maxn];
bool vis[2*maxn];
queue<int> q;
bool spfa(int s,int t){
	for(int i=0;i<=2*n+3;i++)dis[i]=-1e12;
	q.push(s);inc[s]=inf;dis[s]=0;vis[s]=1;
	while(q.size()){
		int k=q.front();
		q.pop();
		vis[k]=0;
		for(int i=head[k];i!=-1;i=e[i].nxt){
			int tmp=e[i].to;
			assert(e[i].w>=0);
			if(e[i].w==0||dis[tmp]>=dis[k]+e[i].c||ban[i])continue;
			dis[tmp]=dis[k]+e[i].c;
			inc[tmp]=min(inc[k],e[i].w);
			pre[tmp]=i;
			if(!vis[tmp])q.push(tmp),vis[tmp]=1;
		}
	}
	return dis[t]>-1e12;
}
int maxflow=0,maxcost=0;
void update(int s,int t){
	maxflow+=inc[t];
	maxcost+=inc[t]*dis[t];
	int p=t;
	while(p^s){
		int ed=pre[p];
		e[ed].w-=inc[t];e[ed^1].w+=inc[t];
		p=e[ed^1].to;
	}
	return ;
}
signed main(){
	n=read();r1=read();r2=read();
	for(int i=1;i<=n;i++)a[i]=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		g[u+n].push_back(v+n),g[v+n].push_back(u+n);
	}
	dfs(r1,0);dfs(r2+n,0);
	for(int i=1;i<=2*n;i++)p[i]=-1;
	int q1,q2;
	q1=read();
	for(int i=1;i<=q1;i++){
		int k,x;
		k=read();x=read();
		p[k]=x;
	}
	q2=read();
	for(int i=1;i<=q2;i++){
		int k,x;
		k=read();x=read();
		p[k+n]=x;
	}
	s=0,t=2*n+1;S=t+1;T=t+2;
	for(int i=1;i<=n;i++)add(i,i+n,1,a[i]),add(i+n,i,0,-a[i]);
	for(int i=1;i<=n;i++){
		if(i==r1){
			if(p[i]==-1)add(s,i,n,0),add(i,s,0,0);
			else out[s]+=p[i],in[i]+=p[i],add(s,i,0,0),add(i,s,0,0);
		}
		else{
			if(p[i]==-1)add(f[i],i,n,0),add(i,f[i],0,0);
			else in[i]+=p[i],out[f[i]]+=p[i],add(f[i],i,0,0),add(i,f[i],0,0);
		}
		int x=i+n;
		if(i==r2){
			if(p[x]==-1)add(x,t,n,0),add(t,x,0,0);
			else in[t]+=p[x],out[x]+=p[x],add(x,t,0,0),add(t,x,0,0);
		}
		else{
			if(p[x]==-1)add(x,f[x],n,0),add(f[x],x,0,0);
			else out[x]+=p[x],in[f[x]]+=p[x],add(x,f[x],0,0),add(f[x],x,0,0);
		}
	}
	int sum=0;
	for(int i=0;i<=2*n+1;i++){
		if(in[i]-out[i]>0)sum+=in[i]-out[i];
		if(in[i]>out[i])add(S,i,in[i]-out[i],0),add(i,S,0,0);
		else add(i,T,out[i]-in[i],0),add(T,i,0,0);
	}
	add(t,s,inf,-inf);add(s,t,0,inf);
	while(spfa(S,T))update(S,T);
	int C=inf*e[cnt-1].w;
	if(maxflow!=sum){puts("-1");return 0;}
	ban[cnt-1]=ban[(cnt-1)^1]=1;
	while(spfa(s,t)){
		if(dis[t]<=0)break;
		update(s,t);
	}
	printf("%lld\n",maxcost+C);
    return 0;
}
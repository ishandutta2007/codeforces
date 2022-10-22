#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
const long long inf=0x3f3f3f3f3f3f3f3f;
struct Edge{
	int to,w,nxt;
}e[20*maxn];
int cnt;
int head[maxn<<3];
int n,Q,s;
int tot;
int id1[maxn<<2],id2[maxn<<2];
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
void build1(int k,int l,int r){
	if(l==r){
		id1[k]=l;
		return ;
	}
	int mid=l+((r-l)>>1);
	id1[k]=++tot;
	build1(k<<1,l,mid);
	build1(k<<1|1,mid+1,r);
	add(id1[k],id1[k<<1],0);
	add(id1[k],id1[k<<1|1],0);
	return ;
}
void build2(int k,int l,int r){
	if(l==r){
		id2[k]=l;
		return ;
	}
	int mid=l+((r-l)>>1);
	id2[k]=++tot;
	build2(k<<1,l,mid);
	build2(k<<1|1,mid+1,r);
	add(id2[k<<1],id2[k],0);
	add(id2[k<<1|1],id2[k],0);
	return ;
}
void modify(int k,int l,int r,int x,int y,int u,int w,int opt){
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){
		if(opt==1)add(u,id1[k],w);
		else add(id2[k],u,w);
		return ;
	}
	int mid=l+((r-l)>>1);
	modify(k<<1,l,mid,x,y,u,w,opt);
	modify(k<<1|1,mid+1,r,x,y,u,w,opt);
	return ;
}
struct que{
	int id;
	long long data;
	bool operator <(que i)const{
		return data>i.data;
	}
};
priority_queue<que>q;
long long dis[maxn<<3];
bool vis[maxn<<3];
void dijkstra(){
	for(int i=1;i<=tot;i++)dis[i]=inf;
	q.push((que){s,0});
	dis[s]=0;
	while(!q.empty()){
		int k=q.top().id;
		q.pop();
		if(vis[k])continue;
		vis[k]=1;
		for(int i=head[k];i!=-1;i=e[i].nxt){
			int tmp=e[i].to;
			if(dis[tmp]<=dis[k]+e[i].w)continue;
			dis[tmp]=dis[k]+e[i].w;
			if(!vis[tmp])q.push((que){tmp,dis[tmp]});
		}
	}
	return ;
}
signed main(){
	n=read();Q=read();s=read();
	tot=n;
	memset(head,-1,sizeof(head));
	build1(1,1,n);build2(1,1,n);
	for(int i=1;i<=Q;i++){
		int opt,v,l,r,w;
		opt=read();v=read();l=read();r=read();
		if(opt==1)add(v,l,r);
		else if(opt==2){
			w=read();
			modify(1,1,n,l,r,v,w,1);
		}
		else{
			w=read();
			modify(1,1,n,l,r,v,w,2);
		}
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		if(dis[i]==inf)dis[i]=-1;
		printf("%lld ",dis[i]);
	}
	return 0;
}
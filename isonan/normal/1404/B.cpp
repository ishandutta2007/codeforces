#include <cstdio>
#include <algorithm>

int n,a,B,da,db,dis[3][100001],t,head[100001],nxt[200001],b[200001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getdis(int x,int f,int dis,int *dist){
	dist[x]=dis;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			getdis(b[i],x,dis+1,dist);
		}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d%d%d",&n,&a,&B,&da,&db);
		for(int i=1;i<=n;i++)head[i]=0;
		k=0;
		for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(v,u),push(u,v);
		getdis(1,0,0,dis[0]);
		int mx=0,mx2=0;
		for(int i=1;i<=n;i++)if(dis[0][mx]<dis[0][i])mx=i;
		getdis(mx,0,0,dis[1]);
		for(int i=1;i<=n;i++)if(dis[1][mx2]<dis[1][i])mx2=i;
		getdis(a,0,0,dis[2]);
		bool win=1;
		if(dis[2][B]<=da){
			win=0;
		}
		else{
			db=std::min(db,dis[1][mx2]);
			if(db>(da<<1))win=1;
			else win=0;
		}
		if(win)puts("Bob");
		else puts("Alice");
	}
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

int head[10001],nxt[5000001],b[5000001],v[5000001],k=1,dis[10001],S,T,q[10001],h,t,p[10001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void link(int s,int t,int val){
	push(s,t,val);
	push(t,s,0);
}
bool bfs(){
	for(int i=S;i<=T;i++)dis[i]=-1;
	dis[S]=h=t=0;
	q[++t]=S;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&dis[b[i]]==-1){
				dis[b[i]]=dis[q[h]]+1;
				if(b[i]==T)return 1;
				q[++t]=b[i];
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if(x==T||!flow)return flow;
	int used=0;
	for(int i=p[x];i;i=nxt[i])
		if(v[i]&&dis[b[i]]==dis[x]+1){
			int w=dfs(b[i],std::min(v[i],flow-used));
			used+=w;
			v[i]-=w;
			v[i^1]+=w;
			if(w)p[x]=i;
			if(flow==used)return flow;
		}
	if(!used)dis[x]=-1;
	return used;
}
int x[101],y[101],x1[51],y1[51],x2[51],y2[51],n,m,limx,limy;
signed main(){
	scanf("%I64d%I64d",&n,&m);
	S=0,T=(m<<2)+1;
	for(int i=1;i<=m;i++){
		scanf("%I64d%I64d%I64d%I64d",x1+i,y1+i,x2+i,y2+i);
		--x1[i],--y1[i];
		x[(i<<1)-1]=x1[i];
		x[i<<1]=x2[i];
		y[(i<<1)-1]=y1[i];
		y[i<<1]=y2[i];
	}
	std::sort(x+1,x+(m<<1)+1);
	limx=std::unique(x+1,x+(m<<1)+1)-x-1;
	for(int i=1;i<=m;i++)x1[i]=std::lower_bound(x+1,x+limx+1,x1[i])-x,x2[i]=std::lower_bound(x+1,x+limx+1,x2[i])-x;
	for(int i=1;i<=limx;i++)link(S,i,x[i]-x[i-1]);
	std::sort(y+1,y+(m<<1)+1);
	limy=std::unique(y+1,y+(m<<1)+1)-y-1;
	for(int i=1;i<=m;i++)y1[i]=std::lower_bound(y+1,y+limy+1,y1[i])-y,y2[i]=std::lower_bound(y+1,y+limy+1,y2[i])-y;
	for(int i=1;i<=limy;i++)link(i+limx,T,y[i]-y[i-1]);
	for(int i=1;i<=m;i++){
		for(int j=x1[i]+1;j<=x2[i];j++)
			for(int k=y1[i]+1;k<=y2[i];k++)
				link(j,k+limx,1e18);
	}
	int ans=0;
	while(bfs()){
		memcpy(p,head,sizeof p);
		ans+=dfs(S,1e18);
	}
	printf("%I64d\n",ans);
}
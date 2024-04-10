#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

using std::min;
using std::max;

int n,m,R,B,x[1000001],y[1000001],origx[1000001],origy[1000001],cons[1000001][2],lim1,lim2,d[1000001][2];
int head[2000100],nxt[3000100],b[3000100],k=1,S,T,SS,TT,dis[2000100],v[3000100],q[2000100],h,t,p[2000100];
int flow[2000100],pos[2001000];
bool vis[2000100];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void link(int s,int t,int val){
	push(s,t,max(val,0ll));
	push(t,s,0);
}
bool bfs(int SS,int TT){
	memset(dis,-1,sizeof dis);
	dis[SS]=0;
	h=t=0;
	q[++t]=SS;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&dis[b[i]]==-1){
				dis[b[i]]=dis[q[h]]+1;
				q[++t]=b[i];
			}
	}
	return ~dis[TT];
}
int dfs(int x,int TT,int flow){
	if(x==TT||!flow)return flow;
	int used=0;
	for(int i=p[x];i;i=nxt[i])
		if(v[i]&&dis[b[i]]==dis[x]+1){
			int w=dfs(b[i],TT,min(v[i],flow-used));
			used+=w;
			v[i]-=w;
			v[i^1]+=w;
			if(w)p[x]=i;
			if(flow==used)return flow;
		}
	if(!used)dis[x]=0;
	return used;
}
signed main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&R,&B);
	for(int i=1;i<=n;i++)scanf("%I64d%I64d",x+i,y+i),origx[i]=x[i],origy[i]=y[i];
	std::sort(origx+1,origx+n+1);
	std::sort(origy+1,origy+n+1);
	lim1=std::unique(origx+1,origx+n+1)-origx-1;
	lim2=std::unique(origy+1,origy+n+1)-origy-1;
	for(int i=1;i<=n;i++)x[i]=std::lower_bound(origx+1,origx+lim1+1,x[i])-origx,y[i]=std::lower_bound(origy+1,origy+lim2+1,y[i])-origy;
	for(int i=1;i<=lim1;i++)cons[i][0]=n;
	for(int i=1;i<=lim2;i++)cons[i][1]=n;
	for(int i=1,t,l,d;i<=m;i++){
		scanf("%I64d%I64d%I64d",&t,&l,&d);
		if(t==1){
			int tem=std::lower_bound(origx+1,origx+lim1+1,l)-origx;
			if(origx[tem]==l)cons[tem][0]=min(cons[tem][0],d);
		}
		else{
			int tem=std::lower_bound(origy+1,origy+lim2+1,l)-origy;
			if(origy[tem]==l)cons[tem][1]=min(cons[tem][1],d);
		}
	}
	S=lim1+lim2+1;
	T=S+1;
	SS=T+1;
	TT=SS+1;
	for(int i=1;i<=n;i++){
		link(x[i],y[i]+lim1,1);
		++d[x[i]][0];
		++d[y[i]][1];
		pos[i]=k-1;
	}
	for(int i=1;i<=lim1;i++){
		int l=max((d[i][0]-cons[i][0]+1)>>1,0ll),r=min((d[i][0]+cons[i][0])>>1,d[i][0]);
		if(l>r){
			puts("-1");
			return 0;
		}
		flow[S]-=l;
		flow[i]+=l;
		link(S,i,r-l);
	}
	for(int i=1;i<=lim2;i++){
		int l=max((d[i][1]-cons[i][1]+1)>>1,0ll),r=min((d[i][1]+cons[i][1])>>1,d[i][1]);
		if(l>r){
			puts("-1");
			return 0;
		}
		flow[i+lim1]-=l;
		flow[T]+=l;
		link(i+lim1,T,r-l);
	}
	int ans=0,x=0;
	for(int i=1;i<=T;i++)
		if(flow[i]<0)link(i,TT,-flow[i]);
		else if(flow[i]>0)link(SS,i,flow[i]),x+=flow[i];
	link(T,S,1000000000000000000ll);
	while(bfs(SS,TT)){
		memcpy(p,head,sizeof p);
		ans+=dfs(SS,TT,1000000000000000000ll);
	}
	if(ans!=x){
		puts("-1");
		return 0;
	}
	ans=0;
	while(bfs(S,T)){
		memcpy(p,head,sizeof p);
		ans+=dfs(S,T,1000000000000000000ll);
	}
	printf("%lld\n",min(R,B)*ans+max(R,B)*(n-ans));
	for(int i=1;i<=n;i++)
		if(v[pos[i]])vis[i]=R>B;
		else vis[i]=R<=B;
	for(int i=1;i<=n;i++)
		if(vis[i])putchar('r');
		else putchar('b');
}
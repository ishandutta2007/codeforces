// Hydro submission #62a44539cd1ee6a7e169b916@1654932793845
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
namespace code{
	inline int read(){
		int a=0,b=1;char s=getchar();
		while(s<48||s>57){if(s=='-'){b=-1;}s=getchar();}
		while(s>=48&&s<=57)a=(a<<1)+(a<<3)+s-48,s=getchar();
		return a*b;
	}
	int n,m,c[300005],r,b;
	#define R register
	struct xc{int x,y;}a[100005];
	struct Que{int t,l,d;}que[100005];
	const int INF=0x3f3f3f3f;
	int mx[600005],mn[600005],deg[600005],num[600005];
	int S,T,SS,TT;
	int head[600005],cnt=1;struct node{int to,next,f,w;}t[2000005];
	inline void add(int u,int v,int f,int w){t[++cnt]=(node){v,head[u],f,w},head[u]=cnt;}
	inline void link(int u,int v,int f,int w){add(u,v,f,w),add(v,u,0,-w);}
	long long ans,dist[600005];
	int dep[600005];bool inque[600005];
	inline bool spfa(){
		queue<int> q;q.push(SS);
		for(R int i=0;i<=TT;i=-~i)dist[i]=1000000000000000,dep[i]=0,inque[i]=false;
		dist[SS]=0,dep[SS]=1,inque[SS]=true;
		while(!q.empty()){
			int u=q.front();q.pop(),inque[u]=false;
			for(R int i=head[u];i;i=t[i].next){
				int v=t[i].to;
				if(t[i].f&&dist[v]>dist[u]+t[i].w){
					dist[v]=dist[u]+t[i].w,dep[v]=dep[u]+1;
					if(!inque[v])inque[v]=true,q.push(v);
				}
			}
		}
		return dep[TT];
	}
	int cur[600005];
	int dfs(int u,int in){
		if(u==TT)return in;
		int out=0;
		for(R int i=cur[u];i;i=t[i].next){
			int v=t[i].to;cur[u]=i;
			if(t[i].f&&dep[v]==dep[u]+1&&dist[v]==dist[u]+t[i].w){
				int k=dfs(v,min(t[i].f,in));
				if(!k)dep[v]=0;
				in-=k,out+=k,t[i].f-=k,t[i^1].f+=k;
				if(!in)break;
			}
		}
		return out;
	}
	inline void main(){
		n=read(),m=read(),r=read(),b=read();
		for(R int i=1;i<=n;i=-~i)a[i]=(xc){read(),read()},c[++c[0]]=a[i].x,c[++c[0]]=a[i].y;
		for(R int i=1;i<=m;i=-~i)que[i]=(Que){read(),read(),read()},c[++c[0]]=que[i].l;
		sort(c+1,c+c[0]+1),c[0]=unique(c+1,c+c[0]+1)-c-1;
		for(R int i=1;i<=n;i=-~i)a[i].x=lower_bound(c+1,c+c[0]+1,a[i].x)-c,a[i].y=lower_bound(c+1,c+c[0]+1,a[i].y)-c;
		for(R int i=1;i<=m;i=-~i)que[i].l=lower_bound(c+1,c+c[0]+1,que[i].l)-c;
		ans=1LL*n*min(b,r);
		for(R int i=1;i<=n;i=-~i)link(a[i].x,a[i].y+c[0],1,abs(r-b)),++num[a[i].x],++num[a[i].y+c[0]];
		for(R int i=1;i<=2*c[0];i=-~i)mx[i]=num[i];
		for(R int i=1;i<=m;i=-~i){
			if(que[i].t==1)mn[que[i].l]=max(mn[que[i].l],(num[que[i].l]-que[i].d+1)/2),mx[que[i].l]=min(mx[que[i].l],(que[i].d+num[que[i].l])/2);
			else mn[que[i].l+c[0]]=max(mn[que[i].l+c[0]],(num[que[i].l+c[0]]-que[i].d+1)/2),mx[que[i].l+c[0]]=min(mx[que[i].l+c[0]],(que[i].d+num[que[i].l+c[0]])/2);
		}
		S=0,T=2*c[0]+1,SS=T+1,TT=SS+1;
		for(R int i=1;i<=c[0];i=-~i){
			if(mx[i]<mn[i]){printf("-1\n");return;}
			if(!mn[i]&&mx[i])link(S,i,mx[i],0);
			else link(S,i,mx[i]-mn[i],0),deg[S]-=mn[i],deg[i]+=mn[i];
		}
		for(R int i=c[0]+1;i<=2*c[0];i=-~i){
			if(mx[i]<mn[i]){printf("-1\n");return;}
			if(!mn[i]&&mx[i])link(i,T,mx[i],0);
			else link(i,T,mx[i]-mn[i],0),deg[i]-=mn[i],deg[T]+=mn[i];
		}
		for(R int i=S;i<=T;i=-~i){
			if(deg[i]<0)link(i,TT,-deg[i],0);
			else if(deg[i]>0)link(SS,i,deg[i],0);
		}
		link(T,S,INF,0);
		while(spfa()){
			for(R int i=0;i<=TT;i=-~i)cur[i]=head[i];
			int flow;while((flow=dfs(SS,INF)))ans+=dist[TT]*flow;
		}
		for(R int i=head[SS];i;i=t[i].next)if(t[i].f){printf("-1\n");return;}
		for(R int i=head[TT];i;i=t[i].next)if(t[i^1].f){printf("-1\n");return;}
		printf("%lld\n",ans);
		if(b<r)for(R int i=1;i<=n;i=-~i)t[i*2+1].f?putchar('r'):putchar('b');
		else for(R int i=1;i<=n;i=-~i)t[i*2+1].f?putchar('b'):putchar('r');
		putchar('\n');
	}
}
int main(){return code::main(),0;}
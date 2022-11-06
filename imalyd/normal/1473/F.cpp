#include<bits/stdc++.h>
using namespace std;
#define ERR(...) fprintf(stderr,__VA_ARGS__);
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
typedef long long ll;
const int MAXN=3005,MAXE=MAXN*13,inf=1000000000;
namespace flow{
	int n,s,t,e,F[MAXN],Q[MAXN],D[MAXN];
	struct edge{
		int u,w,n;
	}E[MAXE<<1];
	inline void add(int v,int u,int w=inf){
		//printf("+ %d %d %d\n",v,u,w);
		E[e]=(edge){u,w,F[v]};F[v]=e++;
		E[e]=(edge){v,0,F[u]};F[u]=e++;
	}
	inline void init(int _,int __,int ___){
		n=_;s=__;t=___;
		int i;
		rep(i,1,n)F[i]=-1;
	}
	inline bool bfs(){
		int v,e,u,l=0,r=1;
		rep(v,1,n)D[v]=0;
		D[Q[1]=s]=1;
		while(l!=r){
			v=Q[++l];
			if(v==t)return true;
			for(e=F[v];~e;e=E[e].n)if(E[e].w){
				u=E[e].u;
				if(!D[u]){D[u]=D[v]+1;Q[++r]=u;}
			}
		}
		return false;
	}
	int dfs(int v,int flow){
		//printf("DFS %d %d\n",v,flow);
		if(v==t)return flow;
		int rest=flow,x,u,e;
		for(e=F[v];~e;e=E[e].n)if(E[e].w){
			u=E[e].u;
			if(D[u]==D[v]+1){
				x=dfs(u,min(rest,E[e].w));
				E[e  ].w-=x;
				E[e^1].w+=x;
				//printf("DFS %d e=%d u=%d x=%d\n",v,e,u,x);
				rest-=x;
				if(!rest)return flow;
			}
		}
		if(rest)D[v]=0;
		return flow-rest;
	}
	inline int solve(){
		int ans=0;
		while(bfs()){
			//int i,e;rep(i,1,n)printf("%d ",D[i]);printf("D\n");rep(i,1,n)for(e=F[i];~e;e=E[e].n)printf("%d --> %d    e = %d    w = %d\n",i,E[e].u,e,E[e].w);
			ans+=dfs(s,inf);
			//rep(i,1,n)printf("%d ",D[i]);printf("D\n");rep(i,1,n)for(e=F[i];~e;e=E[e].n)printf("%d --> %d    w = %d\n",i,E[e].u,E[e].w);printf("\n\n\n\n");
		}
		return ans;
	}
};
int A[105];
inline void ac(){
	int n,i,a,b;
	scanf("%d",&n);
	flow::init(n+2,n+1,n+2);
	rep(i,1,n){
		scanf("%d",&a);
		rep(b,1,a)if(!(a%b)&&A[b])flow::add(i,A[b]);
		A[a]=i;
	}
	b=0;
	rep(i,1,n){
		scanf("%d",&a);
		if(a>=0){flow::add(flow::s,i,a);b+=a;}
		else flow::add(i,flow::t,-a);
	}
	printf("%d\n",b-flow::solve());
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	//printf("MLE %d\n",(sizeof(flow::F)+sizeof(flow::Q)+sizeof(flow::D)+sizeof(flow::E))>>20);
	ac();
	return 0;
}
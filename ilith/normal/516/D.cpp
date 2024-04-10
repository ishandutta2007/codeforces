#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
typedef long long ll;
using namespace std;
const int N=100010;
int n,q,u,v,fa[N],ans,cnt[N],id[N];
ll f[N],d[N],w;
struct edge{int to,w;};
vector<edge>a[N];
void dfs(int x,int f){
	for(auto k:a[x])if(k.to!=f)d[k.to]=d[x]+k.w,dfs(k.to,x);
}
int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}
signed main(){
	scanf("%d",&n);
	FOR(i,2,n)scanf("%d%d%lld",&u,&v,&w),a[u].pbk({v,w}),a[v].pbk({u,w});
	dfs(1,0),u=1;
	FOR(i,2,n)if(d[i]>d[u])u=i;
	dfs(u,d[u]=0),u=1;
	FOR(i,1,n)if((f[i]=d[i])>d[u])u=i;
	dfs(u,d[u]=0);
	FOR(i,1,n)f[i]=max(f[i],d[i]),d[i]=i;
	sort(d+1,d+n+1,[](int x,int y){return f[x]>f[y];}),sort(f+1,f+n+1,greater<ll>());
	FOR(i,1,n)id[d[i]]=i;
	for(scanf("%d",&q);q--;printf("%d\n",ans)){
		scanf("%lld",&w),ans=v=1;
		FOR(i,1,n)fa[i]=i,cnt[i]=1;
		FOR(i,1,n){
			while(f[v]-f[i]>w)--cnt[F(d[v++])];
			for(auto k:a[d[i]])if(id[k.to]<i&&id[k.to]>=v){
				ans=max(ans,cnt[F(d[i])]+=cnt[F(k.to)]),fa[F(k.to)]=F(d[i]);
			}
		}
	}
	return 0;
}
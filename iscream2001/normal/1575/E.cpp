#include <bits/stdc++.h>
#define N 200009
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll dis[N],tr[2][N],cnt[2][N];
int now[N],p[N],a[N];
int n,k,tot,head[N],siz[N],dp[N],sum,rot; 
bool vis[N];
struct edge{
	int n,to,l;
}e[N<<1];
ll ans=0;
inline void MOD(ll &x){x=x>=mod?x-mod:x;}
inline void add(int u,int v,int l){
	e[++tot].n=head[u];
	e[tot].to=v;
	e[tot].l=l;
	head[u]=tot;
}
inline void upd(int co,int x,ll y){
	while(x<=n)MOD(tr[co][x]+=y),cnt[co][x]++,x+=x&-x;
}
inline void cl(int co,int x){
	while(x<=n)tr[co][x]=cnt[co][x]=0,x+=x&-x;
}
inline ll query1(int co,int x){
	if(x<=0)return 0;
	ll ans=0;
	x=min(x,n);
	while(x)MOD(ans+=tr[co][x]),x-=x&-x;
	return ans;
}
inline ll query2(int co,int x){
	if(x<=0)return 0;
	x=min(x,n);
	ll ans=0;
	while(x)MOD(ans+=cnt[co][x]),x-=x&-x;
	return ans;
}
void getdeep(int u,int fa,int co){
	upd(co,p[u],dis[u]); 
	for(int i=head[u];i;i=e[i].n)if(!vis[e[i].to]&&e[i].to!=fa){
		int v=e[i].to;
		MOD(dis[v]=dis[u]+a[v]);
		getdeep(v,u,co);
	}
}
void getans(int u,int fa,int co){
	MOD(ans+=(dis[u]*query2(co,k-p[u]+1)+query1(co,k-p[u]+1))%mod);	
	MOD(ans+=(dis[u]*query2(co^1,k-p[u])+query1(co^1,k-p[u]))%mod);
	if(p[u]<=k)MOD(ans+=dis[u]);
	//cout<<u<<" ?? "<<dis[u]<<" "<<p[u]<<endl;
	for(int i=head[u];i;i=e[i].n)if(!vis[e[i].to]&&e[i].to!=fa){
		int v=e[i].to;
		p[v]=e[i].l==now[u]?p[u]:p[u]+1;
		now[v]=e[i].l;
		MOD(dis[v]=dis[u]+a[v]);
		getans(v,u,co);
	}
}
void getcl(int u,int fa,int co){
	cl(co,p[u]);
	for(int i=head[u];i;i=e[i].n)if(!vis[e[i].to]&&e[i].to!=fa){
		int v=e[i].to;
		getcl(v,u,co);
	}
}
void calc(int u){
	MOD(ans+=a[u]);
	for(int i=head[u];i;i=e[i].n)if(!vis[e[i].to]){
		int v=e[i].to;
		MOD(dis[v]=a[u]+a[v]);p[v]=1;now[v]=e[i].l;
		getans(v,u,e[i].l);
	//	cout<<v<<" ?? "<<ans<<endl;
		dis[v]=a[v];
		getdeep(v,u,e[i].l);
	}
//	cout<<u<<" "<<ans<<endl;
	for(int i=head[u];i;i=e[i].n)if(!vis[e[i].to]){
		int v=e[i].to;
		getcl(v,u,e[i].l);
	}
}
void getroot(int u,int fa){
	siz[u]=1;dp[u]=0;
	for(int i=head[u];i;i=e[i].n)if(!vis[e[i].to]&&e[i].to!=fa){
		int v=e[i].to;
		getroot(v,u);
		siz[u]+=siz[v];
		dp[u]=max(dp[u],siz[v]);
	}
	dp[u]=max(dp[u],sum-siz[u]);
	if(dp[u]<dp[rot])rot=u;
}
void getsize(int u,int fa){
	siz[u]=1;
	for(int i=head[u];i;i=e[i].n)if(!vis[e[i].to]&&e[i].to!=fa){
		int v=e[i].to;
		getsize(v,u);	
		siz[u]+=siz[v];
	}
}
inline void solve(int u){
	calc(u);vis[u]=1;
	for(int i=head[u];i;i=e[i].n)if(!vis[e[i].to]){
		int v=e[i].to;
		sum=siz[v];
		rot=0;
		getroot(v,0);
		getsize(rot,0);
		solve(rot);
	}
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d%d",&n,&k);k++;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int u,v,w;
	for(int i=1;i<n;++i){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	dp[0]=n;
	sum=n;
	getroot(1,0);
	getsize(rot,0);
	solve(rot);
	printf("%lld\n",ans);
}

/*%4=0
0110
1001 */ 
//0110 1001 1001
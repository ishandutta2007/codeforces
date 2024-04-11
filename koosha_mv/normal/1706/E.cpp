#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=3e5+99,lg=20;

int n,m,q,t,node,Time,Min[N<<2],Max[N<<2],a[N],st[N],f[N],h[N],ans[N],par[lg][N],cmp[N];
vector<int> g[N];

void clear(){
	Time=0;
	f(i,0,2*n+10) ans[i]=0,f[i]=-1,cmp[i]=i,g[i].clear();
}
int getpar(int u){
	if(f[u]<0) return u;
	return f[u]=getpar(f[u]);
}
void merge(int u,int v){
	u=getpar(u),v=getpar(v);
	if(u==v) return ;
	if(f[u]>f[v]) swap(u,v);
	f[u]+=f[v];
	f[v]=u;
}
int lca(int u,int v){
	if(h[u]>h[v]) swap(u,v);
	f_(l,lg-1,0) if(h[par[l][v]]>=h[u]) v=par[l][v];
	if(u==v) return u;
	f_(l,lg-1,0) if(par[l][u]!=par[l][v]) u=par[l][u],v=par[l][v];
	return par[0][u];
}
void dfs1(int u){
	//cout<<u<<" : "<<ans[u]<<endl;
	f(l,1,lg) par[l][u]=par[l-1][par[l-1][u]];
	a[Time]=u;
	st[u]=Time++;
	for(auto v : g[u]){
		//cout<<u<<" -> "<<v<<endl;
		par[0][v]=u;
		h[v]=h[u]+1;
		dfs1(v);
	}
}
void build(){
	f(i,1,n+1) Min[i+n-1]=Max[i+n-1]=st[i];
	f_(i,n-1,1){
		Min[i]=min(Min[i<<1],Min[i<<1|1]);
		Max[i]=max(Max[i<<1],Max[i<<1|1]);
	}
}
int getmax(int l,int r){
	int ans=0;
	l--;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1){
			maxm(ans,Max[l++]);
		}
		if(r&1){
			maxm(ans,Max[--r]);
		}
	}
	return ans;
}
int getmin(int l,int r){
	int ans=2*N;
	l--;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1){
			minm(ans,Min[l++]);
		}
		if(r&1){
			minm(ans,Min[--r]);
		}
	}
	return ans;
}
void Main(){
	cin>>n>>m>>q; node=n;
	clear();
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		if(getpar(u)!=getpar(v)){
			node++;
			ans[node]=i+1;
			g[node].pb(cmp[getpar(u)]);
			g[node].pb(cmp[getpar(v)]);
			merge(u,v);
			cmp[getpar(u)]=node;
		}
	}
	h[node]=0;
	par[0][node]=node;
	dfs1(node);
	build();
	while(q--){
		int l,r;
		cin>>l>>r;
		int u=getmin(l,r),v=getmax(l,r);
		u=a[u],v=a[v];
		cout<<ans[lca(u,v)]<<" ";
	}
	cout<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
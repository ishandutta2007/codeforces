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

const int N=3e5+99,lg=20;

int n,m,Time,a[N],h[N],b[N],st[N],ft[N],ok[N],cnt[N],f[N],par[lg][N];
vector<int> g[N];

bool is_par(int u,int v){
	return st[u]<=st[v] && st[v]<ft[u];
}
int lca(int u,int v){
	if(h[u]>h[v]) swap(u,v);
	f_(l,lg-1,0) if(h[par[l][v]]>=h[u]) v=par[l][v];
	if(u==v) return u;
	f_(l,lg-1,0) if(par[l][u]!=par[l][v]) u=par[l][u],v=par[l][v];
	return par[0][u];
}
int Par(int u,int k){
	f(i,0,lg){
		if(k&(1<<i)){
			u=par[i][u];
		}
	}
	return u;
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
void dfs(int u,int p){
	st[u]=Time++;
	par[0][u]=p;
	f(l,1,lg) par[l][u]=par[l-1][par[l-1][u]];
	for(auto v : g[u]){
		if(v==p) continue ;
		h[v]=h[u]+1;
		dfs(v,u);
	}
	ft[u]=Time;
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(f,f+N,-1);
	cin>>n>>m;
	f(i,0,m){
		cin>>a[i]>>b[i];
		if(getpar(a[i])!=getpar(b[i])){
			//eror(i);
			merge(a[i],b[i]);
			g[a[i]].pb(b[i]);
			g[b[i]].pb(a[i]);
		}
	}
	dfs(1,1);
	f(i,0,m){
		int u=a[i],v=b[i];
		if(h[u]>h[v]) swap(u,v);
		//cout<<u<<" "<<v<<" -> "<<is_par(u,v)<<endl;
		if(is_par(u,v)){
			int x=Par(v,h[v]-h[u]-1);
			//eror(x);
			cnt[st[x]]--;
			cnt[ft[x]]++;
			cnt[0]++;	
		}
		else{
			cnt[st[u]]++;
			cnt[ft[u]]--;
		}
		cnt[st[v]]++;
		cnt[ft[v]]--;
	}
	f(i,0,n){
		cnt[i+1]+=cnt[i];
	}
	f(i,1,n+1){	
		if(cnt[st[i]]==m) cout<<1;
		else cout<<0;
	}
}
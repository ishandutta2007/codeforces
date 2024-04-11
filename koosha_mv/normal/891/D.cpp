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

const int N=1e6+99;

int n,t,cent,_m,odd,a[N],b[N],P[N],h[N],res[N],sz[N],mark[N];
ll ans;
vector<int> vec[N];
vector<pair<int,int>> g[N],Q[N];

void dfs1(int u,int p){
	sz[u]=1;
	for(auto [v,id] : g[u]){
		if(v==p) continue ;
		dfs1(v,u);
		sz[u]+=sz[v];
		a[id^1]=a[id]=2*bit(sz[v],0)-1;
	}
	odd+=bit(sz[u],0);
}
int dfs2(int u,int p){
	int sum=bit(sz[u],0);
	for(auto [v,id] : g[u]){
		if(v==p) continue ;
		int res=dfs2(v,u);
		if(sz[v]&1){
			b[id]=(odd-res)-(sz[1]-sz[v])/2;
			b[id^1]=(res-1)-sz[v]/2;
		}
		else{
			b[id^1]=b[id]=n;
			if(2*odd==n) ans+=1ll*sz[v]*(n-sz[v]);
		}
		sum+=res;
	}
	return sum;
}
void dfs3(int u,int p){
	sz[u]=1;
	for(auto [v,id] : g[u]){
		if(v==p) continue ;
		dfs3(v,u);
		sz[u]+=sz[v];
	}
	if(sz[u]*2>=_m && cent==0) cent=u;
}
void dfs4(int u,int p,int rt,int x){
	sz[rt]++;
	h[u]=h[p]+a[x];
	mark[h[u]+n]++;
	vec[P[rt]].pb(h[u]);
	Q[P[rt]].pb({x,b[x]-h[p]});
	for(auto [v,id] : g[u]){
		if(v==p) continue ;
		dfs4(v,u,rt,id); 
	}
}
void solve(int rt,int m){
	vector<pair<int,int>> adj;
	if(m==2){
		int id=g[rt][0].S;
		if(b[id]==0) res[id]++;
		if(b[id^1]==0) res[id^1]++;
		return ;
	}
	cent=0,_m=m;
	dfs3(rt,rt);
	rt=cent;
	h[rt]=0;
	int cnt=0;
	for(auto [v,id] : g[rt]){
		sz[v]=0;
		P[v]=cnt++;
		dfs4(v,rt,v,id);
	}
	for(auto [v,id] : g[rt]){
		adj.pb({v,id});
		for(auto x : vec[P[v]]) mark[x+n]--;
		for(auto p : Q[P[v]]) res[p.F]+=mark[p.S+n];	
		for(auto x : vec[P[v]]) mark[x+n]++;
	}
	for(auto [v,id] : g[rt]){
		for(auto x : vec[P[v]]) mark[x+n]--;
		Q[P[v]].clear();
		vec[P[v]].clear();
	}
	g[rt].clear();
	for(auto p : adj){
		g[rt].pb(p);
		solve(rt,sz[p.F]+1);
		g[rt].pop_back();
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	if(n&1) return cout<<0,0;
	f(i,0,n-1){
		int u,v;
		cin>>u>>v;
		g[u].pb({v,i<<1});
		g[v].pb({u,i<<1|1});
	}
	dfs1(1,1);
	dfs2(1,1);
	solve(1,n);
	f(i,0,n-1) ans+=1ll*res[i<<1]*res[i<<1|1];
	cout<<ans;
}
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

typedef pair<int,int> pii;

const int N=4e5+99,lg=20;

int n,m,q,rt,cntq,Time=1,a[N],p[N],h[N],inv[N],sz[N],st[N],ft[N],fenwik[N],type[N];
int ans[N],fmn[N],fmx[N],par[lg][N];
pii seg1[N];
set<int> s;
vector<pii> Q[N],op[N];
vector<int> g[N],vec[N];

void add(int x, int val){ for(x++;x<N;x+=x&-x) fenwik[x]+=val; }
int get(int x) { int res=0; for (x++;x>0;x-=x&-x) res+=fenwik[x]; return res; }
void update(int x, int val){ for (x++;x>0;x-=x&-x) minm(fmn[x],val),maxm(fmx[x],val); }
int getmn(int x) { int res=N; for(x++;x<N;x+=x&-x) minm(res,fmn[x]); return res; }
int getmx(int x) { int res=0; for(x++;x<N;x+=x&-x) maxm(res,fmx[x]); return res; }

void read(){
	fill(fmn,fmn+N,N);
	cin>>n>>q; rt=m=n;
	iota(a+1,a+n+1,1);
	iota(p+1,p+n+1,1);
	f(i,1,n+1) vec[i].pb(i);
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
}
int Par(int u,int k){
	f(i,0,lg){
		if(k&(1<<i)){
			u=par[i][u];
		}
	}
	return u;
}
int lca(int u,int v){
	if(h[u]>h[v]) swap(u,v);
	f_(l,lg-1,0) if(h[par[l][v]]>=h[u]) v=par[l][v];
	if(u==v) return u;
	f_(l,lg-1,0) if(par[l][u]!=par[l][v]) u=par[l][u],v=par[l][v];
	return par[0][u];
}
int dist(int u,int v){
	return h[u]+h[v]-2*h[lca(u,v)];
}
pii get1(int l,int r){
	pii res={0,0};
	l--,r--;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1){
			maxm(res,seg1[l++]);
		}
		if (r&1){
			maxm(res,seg1[--r]);
		}
	}
	return res;
}
void change1(int u){
	int x=st[u]+n-1;
	while(x){
		seg1[x]={p[u],u};
		x>>=1;
	}
}
void dfs1(int u,int p){
	sz[u]=1;
	st[u]=Time;
	inv[Time++]=u;
	par[0][u]=p;
	f(l,1,lg) par[l][u]=par[l-1][par[l-1][u]];
	f(i,0,g[u].size()) if(g[u][i]==p) g[u].erase(g[u].begin()+i);
	for(auto v : g[u]) h[v]=h[u]+1,dfs1(v,u),sz[u]+=sz[v];
	ft[u]=Time;
}
pii find(int u){
	if(u==rt) return {p[rt],rt};
	if(ft[u]<=st[rt] || st[rt]<st[u]){
		return get1(st[u],ft[u]);
	}
	int x=Par(rt,h[rt]-h[u]-1);
	return max(get1(1,st[x]),get1(ft[x],n+1));
}

void adds(int x,int z){
	s.insert(x);
	int l=*prev(s.lower_bound(x)),r=*s.upper_bound(x);
	op[l+1].pb({x,+z});
	op[l+1].pb({r,-z});
	op[x+1].pb({x,-z});
	op[x+1].pb({r,+z});
}
void dfs3(int u,int h){
	for(auto x : vec[u]) adds(x,h);
	for(auto v : g[u]){
		dfs3(v,h);
	}
}
void dfs2(int u,int h){
	sort(all(g[u]),[&](int u,int v){ return sz[u]<sz[v]; });
	for(auto v : g[u]){
		if(v==g[u].back()){
			dfs2(v,h+1);
		}
		else{
			dfs2(v,1);
			s.clear();
		}
	}
	for(auto v : g[u]){
		if(v!=g[u].back()){
			dfs3(v,h);
		}
	}
	if(g[u].size()==0){
		s.insert(0);
		s.insert(m+1);
	}
	for(auto x : vec[u]){
		adds(x,h);
	}
	
}
void solve(){
	dfs2(1,1);
	f(i,1,m+1){
		for(auto p : op[i]){
			add(p.F,p.S);
		}
		for(auto p : Q[i]){
			ans[p.S]+=get(p.F);
		}
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read();
	dfs1(1,1);
	f(i,1,n+1) change1(i),update(i,st[i]);
	f(i,1,q+1){
		int u,v;
		string s;
		cin>>s;
		if(s=="up"){
			cin>>u;
			m++;
			rt=u;
			a[m]=u;
			p[u]=m;
			change1(u);
			update(m,st[u]);
			vec[u].pb(m);
		}
		if(s=="when"){
			cntq++;
			type[cntq]=1;
			cin>>u;
			pair<int,int> v=find(u);
			ans[cntq]=-h[lca(inv[getmn(v.F)],inv[getmx(v.F)])]-dist(u,v.S);
			Q[v.F].pb({m,cntq});
		}
		if(s=="compare"){
			cntq++;
			cin>>u>>v;	
			pair<int,int> x=find(u),y=find(v);
			x.S=dist(u,x.S),y.S=dist(v,y.S);
			if(x<y){
				ans[cntq]=u;
			}
			else{
				ans[cntq]=v;
			}
		}
	}
	solve();
	f(i,1,cntq+1){
		if(type[i]) ans[i]=n+1-ans[i];
		cout<<ans[i]<<" ";
	}
}
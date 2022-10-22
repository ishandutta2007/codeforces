#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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

const int N=5e5+99;

int n,t,a[N],b[N],c[N],d[N],par[N];
pair<int,int> P[N];
vector<int> ans,g[N];
map<pair<int,int>,bool> mark;

int getpar(int u){
	if(par[u]<0) return u;
	return par[u]=getpar(par[u]);
}
void merge(int u,int v){
	u=getpar(u),v=getpar(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
void dfs1(int u,int p){
	if(getpar(u)!=getpar(p)){
		P[getpar(u)]={u,p};
	}
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs1(v,u);
	}
}
void dfs2(int u,int p){
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs2(v,u);
	}
	if(getpar(u)!=getpar(p)){
		ans.pb(u);
		ans.pb(p);
		ans.pb(P[getpar(u)].F);
		ans.pb(P[getpar(u)].S);
	}
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(par,par+N,-1);
	cin>>n;
	f(i,1,n){
		cin>>a[i]>>b[i];
		if(a[i]>b[i]) swap(a[i],b[i]);
		mark[mp(a[i],b[i])]=1;		
	}
	int cnt=n-1;
	f(i,1,n){
		cin>>c[i]>>d[i];
		if(c[i]>d[i]) swap(c[i],d[i]);
		if(mark[mp(c[i],d[i])]){
			merge(c[i],d[i]),cnt--;
		}	
	}
	f(i,1,n){
		g[c[i]].pb(d[i]);
		g[d[i]].pb(c[i]);
	}
	dfs1(1,1);
	f(i,1,n+1) g[i].clear();
	f(i,1,n){
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	dfs2(1,1);
	cout<<cnt<<'\n';
	for(int i=0;i<ans.size();i+=4){
		cout<<ans[i]<<" "<<ans[i+1]<<" "<<ans[i+2]<<" "<<ans[i+3]<<'\n';
	}
}
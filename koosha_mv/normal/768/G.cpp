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
 
int n,t,rt,a[N],sz[N],ans[N],Mid[N],Min[N],btc[N],type[N],par[N],res[N],prt[N];
vector<int> g[N];
set<pair<int,int> > s0,s1,s2;
 
int closest(set<pair<int,int> > &s,int x){
	if(s.size()==0) return N;
	int res=N;
	if((*s.begin()).F<x) minm(res,x-(*prev(s.lower_bound(mp(x,0)))).F);
	if((*s.rbegin()).F>=x) minm(res,(*s.lower_bound(mp(x,0))).F-x);
	return res;
}
void dfs1(int u){
	int id=-1;
	sz[u]=2;
	f(i,0,g[u].size()){
		dfs1(g[u][i]);
		sz[u]+=sz[g[u][i]];
		if(id==-1 || sz[g[u][i]]>sz[g[u][id]]){
			id=i;
		}
	}
	if(id!=-1) swap(g[u][0],g[u][id]);
}
void dfs3(int u){
	s1.insert(mp(sz[u],u));
	s2.erase(mp(sz[u],u));
	for(auto v : g[u]){
		dfs3(v);
	}
}
void dfs2(int u){
	if(type[u]){
		minm(Min[u],closest(s0,Mid[u]+sz[u]));
	}
	
	s0.insert(mp(sz[u],u));
	s2.erase(mp(sz[u],u));
	
	f(i,1,g[u].size()){
		int v=g[u][i];
		dfs2(v);
		for(auto x : s1){
			s2.insert(x);
		}
		s1.clear();
	}
	
	if(g[u].size()>0){
		dfs2(g[u][0]);
	}
	
	f(i,1,g[u].size()){
		int v=g[u][i];
		dfs3(v);
	}
	
	if(type[u]){
		minm(Min[u],closest(s2,Mid[u]));
	}
	
	
	if(prt[u]){
		minm(Min[par[u]],closest(s1,Mid[par[u]]));
	}
	s1.insert(mp(sz[u],u));
	s0.erase(mp(sz[u],u));
}
 
int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(Min,Min+N,N);
	cin>>n;
	f(i,1,n+1){
		int u,v;
		cin>>u>>v;
		par[v]=u;
		g[u].pb(v);
		if(u==0) rt=v;
	}		
	dfs1(rt);
	f(u,1,n+1){
		vector<int> vec(3);
		int mx=sz[rt]-sz[u],mn=sz[rt]-sz[u];
		vec[0]=sz[rt]-sz[u];
		sort(all(vec));
		if(u==rt) mx=0,mn=N;
		for(auto v : g[u]){
			maxm(mx,sz[v]);
			minm(mn,sz[v]);
			vec[0]=sz[v];
			sort(all(vec));
		}
		for(auto v : g[u]){
			if(sz[v]==mx){
				prt[v]=1;
				break;
			}
		}
		if(mx==sz[rt]-sz[u] && u!=rt) type[u]=1;
		btc[u]=mx;
		res[u]=vec[1];
		ans[u]=(mx+mn)/2;
		Mid[u]=ans[u]-mn;
		s2.insert(mp(sz[u],u));
	}
	dfs2(rt);
	f(i,1,n+1){
		cout<<max(res[i],min(btc[i],ans[i]+Min[i]))/2<<" ";
	}
}
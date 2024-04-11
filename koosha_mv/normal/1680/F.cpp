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

const int N=1e6+99;

int n,m,t,Time,nok,chosen,h[N],s1[N],s2[N],vis[N],st[N],ft[N];
vector<int> g[N];

void dfs1(int u,int p){
	st[u]=Time++;
	vis[u]=1;
	for(auto v : g[u]){
		if(v==p || vis[v]==0) continue ;
		if(h[u]!=h[v]){
			s1[u]++;
			s1[v]--;
		}
		if(h[u]==h[v]){
			nok++;
			s2[u]++;
			s2[v]--;
		}
	}
	for(auto v : g[u]){
		if(vis[v]) continue ;
		h[v]=h[u]^1;
		dfs1(v,u);
	}
	ft[u]=Time++;
}
void dfs2(int u){
	vis[u]=1;
	for(auto v : g[u]){
		if(vis[v]) continue ;
		dfs2(v);
		s1[u]+=s1[v];
		s2[u]+=s2[v];
	}
	if(s1[u]==0 && s2[u]==nok){
		chosen=u;
	}
}
void Main(){
	cin>>n>>m;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,1);
	if(nok<2){
		int b=0;
		f(u,1,n+1) for(auto v : g[u]) if(h[u]==0 && h[v]==0) b=1;
		cout<<"YES"<<'\n';
		f(i,1,n+1) cout<<(h[i]^b);
		cout<<'\n';
		return ;
	}
	fill(vis,vis+N,0);
	dfs2(1);
	if(chosen==0){
		cout<<"NO"<<'\n';
		return ;
	}
	cout<<"YES"<<'\n';
	f(i,1,n+1) h[i]^=(st[chosen]<=st[i] && st[i]<ft[chosen]);
	if(h[chosen]==0) f(i,1,n+1) h[i]^=1;
	f(i,1,n+1) cout<<h[i]; cout<<'\n';
	
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		Time=chosen=nok=0;
		f(i,1,n+1) vis[i]=s1[i]=s2[i]=h[i]=0,g[i].clear();
	}
}
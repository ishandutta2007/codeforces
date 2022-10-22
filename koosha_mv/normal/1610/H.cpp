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

const int N=3e5+99,lg=20;

int n,m,ans=N,a[N],dist[N],dp[N],pd[N],sum[N],par[lg][N];
vector<int> vs[N],vt[N],g[N];

int Par(int u,int k){
	f(i,0,lg){
		if(k&(1<<i)){
			u=par[i][u];
		}
	}
	return u;
}
int is_par(int u,int v){
	int ans=Par(v,max(0,dist[v]-dist[u]-1));
	if(par[0][ans]==u) return ans;
	return 0;
}
void dfs1(int u){
	vector<int> vec;
	sort(g[u].begin(),g[u].end());
	for(auto x : vs[u]){
		int v=is_par(u,x);
		if(v>0){
			vt[*lower_bound(g[u].begin(),g[u].end(),v)].pb(x);
		}
	}
	for(auto v : g[u]){
		dfs1(v);
		sum[u]+=dp[v];
	}	
	dp[u]=sum[u];
	for(auto x : vt[u]){
		if(is_par(u,x)){
			maxm(dp[u],dp[x]+1);
		}
	}
}
void dfs2(int u){
	if(u>1){
		pd[u]=sum[par[0][u]]+pd[par[0][u]]-dp[u];
	}
	for(auto x : vs[u]){
		if(is_par(u,x)) continue;
		int s=is_par(x,u);
		if(s>0){
			maxm(pd[u],pd[s]+1);
		}
		else{
			maxm(pd[u],dp[x]+1);
		}
	}
	for(auto v : g[u]){
		dfs2(v);
	}
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;	
	f(i,2,n+1){ int x; cin>>x; g[x].pb(i); par[0][i]=x; dist[i]=dist[x]+1; }
	f(i,0,m){
		int x,y;
		cin>>x>>y;
		if(par[0][x]==y || par[0][y]==x) return cout<<-1,0;
		vs[x].pb(y);
		vs[y].pb(x);
	}
	f(l,1,lg){
		f(u,1,n+1){
			par[l][u]=par[l-1][par[l-1][u]];
		}
	}
	dfs1(1);
	dfs2(1);
	f(u,1,n+1){
		int res=pd[u];
		for(auto v : g[u]){
			res+=dp[v];
		}
		minm(ans,res);
	}
	cout<<ans+1;
}
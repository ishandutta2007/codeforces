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

const int N=1e6+99;

int n,t,cnt,black,a[N],prt[N],col[N],ans[N],mark[N];
vector<int> v,vtx,g[N];

void dfs(int u){
	v.pb(u);
	mark[u]=1;
	for(auto v : g[u]){
		cnt+=col[v];
		prt[u]+=col[v];
		if(mark[v] || col[v]) continue ;
		dfs(v);
	}
}
void dfs1(int u){
	vtx.pb(u);
	mark[u]=1;
	for(auto v : g[u]){
		cnt+=(prt[v]>0);
		if(mark[v] || prt[v]) continue ;
		dfs1(v);
	}
}
int main(){
	cin>>n;
	f(i,1,n+1){ cin>>col[i]; ans[i]=1; black+=col[i]; }
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,n+1){
		if(!mark[i] && !col[i]){
			v.clear();
			cnt=0;
			dfs(i);
			if(cnt==black){
				fill(mark,mark+N,0);
				for(auto u : v){
					if(mark[u] || prt[u]) continue ;
					cnt=0;
					dfs1(u);
					if(cnt==black){
						for(auto x : vtx){
							ans[x]=0;
						}
					}
				}	
				break;
			}
		}
	}
	f(u,1,n+1){
		for(auto v : g[u]){
			ans[u]|=col[v];
		}
	}
	f(i,1,n+1) cout<<ans[i]<<" ";
}
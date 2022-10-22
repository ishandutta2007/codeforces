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

const int N=4444;

struct Flow{
	int n,m,source,sink,MaxFlow=0,to[4*N],from[4*N],cap[4*N],vis[N];
	vector<int> g[N];
	Flow(int n1,int n2){
		n=n1+n2+2;
		source=0;
		sink=n-1;
	}
	void Add_edge(int u,int v,int c=0){
		g[u].pb(m);
		cap[m]=c;
		from[m]=u;
		to[m]=v;
		m++;
		
		g[v].pb(m);
		cap[m]=0;
		from[m]=v;
		to[m]=u;
		m++;
	}
	void Add_cap(int id,int c){
		cap[id]+=c;
	}
	bool dfs(int u){
		vis[u]=1;
		if(u==sink){
			return 1;
		}
		for(auto e : g[u]){
			int u=to[e];
			if(cap[e] && !vis[u] && dfs(u)){
				cap[e]--;
				cap[e^1]++;
				return 1;
			}
		}
		return 0;
	}
	void Max_Flow(){
		fill(vis,vis+N,0);
		while(dfs(source)){
			MaxFlow++;
			fill(vis,vis+N,0);
		}	
	}
};

int main(){
	int n1,n2,m,mindeg=N,deg[N];
	vector<int> ans[N];
	cin>>n1>>n2>>m;
	Flow flow(n1,n2);
	f(i,1,n1+1){
		flow.Add_edge(flow.source,i);
	}
	f(i,n1+1,n1+n2+1){
		flow.Add_edge(i,flow.sink);
	}
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		deg[u]++,deg[v+n1]++;
		flow.Add_edge(u,v+n1,1);
	}
	f(i,1,n1+n2+1){
		minm(mindeg,deg[i]);
	}
	f(i,0,n1+n2){
		flow.Add_cap(i<<1,deg[i+1]-mindeg);
	}
	f_(deg,mindeg,0){
		flow.Max_Flow();
		f(i,n1+n2,n1+n2+m){
			if(flow.cap[i<<1]){
				ans[deg].pb(i-n1-n2+1);
			}
		}
		f(i,0,n1+n2){
			flow.Add_cap(i<<1,1);
		}
	}
	f(i,0,mindeg+1){
		cout<<ans[i].size()<<" ";
		f(j,0,ans[i].size()) cout<<ans[i][j]<<" "; cout<<endl;
	}
}
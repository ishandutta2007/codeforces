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

const int N=2e5+99,lg=20;

int n,m,X,deg[N],h[N],dp[N],mark[N],ted[N],par[lg][N];
vector<int> Ans,g[N],gb[N];

mt19937 rng(time(nullptr));

void delvtx(){
	queue<int> q;
	f(i,1,n+1) if(deg[i]==0) q.push(i);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v : g[u]){
			if(--deg[v]==0){
				q.push(v);
			}
		}
	}	
	f(i,1,n+1) if(deg[i]>0) return ;
	//cout<<n<<'\n';
	//f(i,1,n+1) cout<<i<<" "; cout<<'\n';
	cout<<1<<'\n';
	exit(0);
}
int find(){
	vector<int> vec,q;
	f(i,1,n+1) if(deg[i]>0) vec.pb(i);
	shuffle(all(vec),rng);
	for(auto x : vec){
		if(mark[x]) continue ;
		int dg=deg[x];
		deg[x]=0;
		q.pb(x);
		f(i,0,q.size()){
			int u=q[i];
			mark[u]=1;
			for(auto v : g[u]){
				if(--deg[v]==0){
					q.pb(v);
				}
			}	
		}
		if(q.size()==vec.size()) return x;
		f(i,0,q.size()){
			int u=q[i];
			for(auto v : g[u]){
				deg[v]++;
			}	
		}
		deg[x]=dg;
		q.clear();
	}
	//cout<<0<<'\n';
	cout<<-1<<'\n';
	exit(0);
}
int Lca(int u,int v){
	if(h[u]>h[v]) swap(u,v);
	while(h[u]<h[v]) v=par[0][v];
	if(u==v) return u;
	f_(l,lg-1,0){
		if(par[l][u]!=par[l][v]){
			u=par[l][u];
			v=par[l][v];
		}
	}
	return par[0][u];
}
void dfs1(int u){
	f(l,1,lg) par[l][u]=par[l-1][par[l-1][u]];
	mark[u]=1;
	for(auto v : g[u]){
		if(v==X)  ted[u]++;
		if(mark[v]) continue ;
		h[v]=h[u]+1;
		//cout<<u<<" -> "<<v<<endl;
		par[0][v]=u;
		dfs1(v);
		ted[u]+=ted[v];
	}
}
void dfs2(int u){
	mark[u]=1;
	for(auto v : g[u]){
		if(mark[v]) continue ;
		dfs2(v);
		dp[u]+=dp[v];
	}
	if(dp[u]==0 && ted[u]==ted[X]){
		Ans.pb(u);
	}
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		deg[v]++;
		g[u].pb(v);
		gb[v].pb(u);
	}
	delvtx();
	X=find();
	fill(mark,mark+N,0);
	par[0][X]=X; dfs1(X);
	return cout<<X<<'\n',0;
	f(u,1,n+1){
		if(par[0][u]==0) continue ;
		for(auto v : g[u]){
			if(ted[v]==0) continue ;
			//cout<<u<<" --> "<<v<<endl;
			//cout<<par[0][v]<<" "<<Lca(u,v)<<endl;
			dp[par[0][v]]++;
			dp[Lca(u,v)]--;
		}
	}
	fill(mark,mark+N,0);
	dfs2(X);
	sort(all(Ans));
	cout<<Ans.size()<<'\n';
	for(auto u : Ans) cout<<u<<" ";
}
/*
6 7
1 2
2 3
3 5
2 4
5 6
4 6
6 1
*/
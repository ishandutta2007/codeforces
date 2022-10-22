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

const int N=5e5+99,MAXN=N;

struct _2SAT {
	vector<int> adj[MAXN << 1], adj_r[MAXN << 1];
	bool vis[MAXN << 1], ans[MAXN];
	int col[MAXN << 1], n = -1, C;
	stack<int> order;
 
	void dfs(int v) {
		vis[v] = true;
		for (int u : adj[v])
			if (!vis[u])
				dfs(u);
 
		order.push(v);
	}
 
	void sfd(int v) {
		col[v] = C;
		for (int u : adj_r[v])
			if (!col[u])
				sfd(u);
	}
 
	void add(int u, int v) {
		adj[u ^ 1].push_back(v);
		adj[v ^ 1].push_back(u);
		adj_r[u].push_back(v ^ 1);
		adj_r[v].push_back(u ^ 1);
	}
 
	void init(int _n) {
		memset(vis, false, sizeof vis);
		memset(col, 0, sizeof col);
		memset(ans, false, sizeof ans);
		C = 0;
		n = _n;
	}
 
	bool solve() {
		for (int v = 0; v < 2 * n; v++)
			if (!vis[v])
				dfs(v);
 
		while (!order.empty()) {
			int v = order.top();
			order.pop();
			if (!col[v]){
				C++, sfd(v);
			}
		}
 
		for (int i = 0; i < n; i++) {
			if (col[i << 1] == col[i << 1 | 1]){
				return false;
			}
			ans[i] = col[i << 1] < col[i << 1 | 1];
		}
 
		return true;
	}
} sat;

int n,q,a[N],b[N],h[N],par[N];
string s[N];
vector<int> g[N];
vector<pair<int,pair<int,int>>> v[N];

void dfs1(int u,int p){
	par[u]=p;
	for(auto v : g[u]){
		if(v==p) continue ;
		h[v]=h[u]+1;
		dfs1(v,u);
	}
}
vector<int> path(int u,int v){
	vector<int> vec1,vec2;
	while(u!=v){
		if(h[u]>h[v]) vec1.pb(u),u=par[u];
		else vec2.pb(v),v=par[v];
	}
	vec1.pb(u);
	reverse(all(vec2));
	for(auto x : vec2) vec1.pb(x);
	return vec1;
}
vector<pair<int,int>> G(pair<int,pair<int,int>> u){
	vector<pair<int,int>> res;
	res.pb({u.F<<1,u.S.F});
	res.pb({u.F<<1|1,u.S.S});
	return res;
}
int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,1);
	sat.init(q);
	f(i,0,q){
		cin>>a[i]>>b[i]>>s[i];
		vector<int> vec=path(a[i],b[i]);		
		f(j,0,vec.size()){
			int u=vec[j];
			v[u].pb({i,{s[i][j]-'a',s[i][s[i].size()-j-1]-'a'}});
		}
	}
	f(u,1,n+1){
		vector<pair<int,pair<int,int>>> vec=v[u];
		f(i,0,vec.size()){
			pair<int,pair<int,int>> now=vec[i],nxt=vec[(i+1)%vec.size()];
			vector<pair<int,int>> vec1=G(now),vec2=G(nxt);
			f(k,0,2) f(p,0,2) {
				if(vec1[k].S!=vec2[p].S){
					sat.add(vec1[k^1].F,vec2[p^1].F);
				}
			}
		}
	}
	if(sat.solve()==0) return cout<<"NO",0;
	cout<<"YES"<<'\n';
	string res;
	f(i,0,n) res+='a';
	f(i,0,q){
		vector<int> vec=path(a[i],b[i]);
		if(sat.ans[i]==0){
			f(j,0,vec.size()) res[vec[j]-1]=s[i][j];
		}	
		else{
			f(j,0,vec.size()) res[vec[j]-1]=s[i][s[i].size()-j-1];
		}
	}
	cout<<res;
}
/*
10 2
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 4 aa
10 2 aba
*/
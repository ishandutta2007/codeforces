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

const int N=1e5+99,inf=1e9;

int n,q,a[N],ans[N],par[N];
set<int> s[N];
vector<int> v[N],g[N];

void dfsp(int u){
	for(auto v : g[u]){
		if(v!=par[u]){
			par[v]=u;
			dfsp(v);
		}
	}
}
void dfs(int u,int p){
	map<int,int> mark;
	set<int> tek;
	int x=0;
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs(v,u);
		if(s[v].size()>s[x].size()){
			x=v;
		}
	}
	swap(s[u],s[x]);
	for(auto w : v[u]){
		mark[w]=1;
		if(s[u].find(w)!=s[u].end()) ans[w]++;
		s[u].insert(w);
	}
	for(auto v : g[u]){
		if(v==p || v==x) continue ;
		for(auto w : s[v]){
			if(mark[w]) ans[w]++;
			else{
				if(s[u].find(w)!=s[u].end()){
					tek.insert(w);
				}
				else{
					s[u].insert(w);
				}
			}
		}
	}
	for(auto w : tek){
		ans[w]++;
		s[u].erase(w);
	}
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}	
	dfsp(1);
	cin>>q;
	f(t,0,q){
		vector<int> vec;
		int k,x;
		cin>>k;
		f(i,0,k){
			cin>>x;
			vec.pb(x);
			v[x].pb(t);
		}
		sort(all(vec));
		f(i,0,vec.size()){
			int u=par[vec[i]],p=lower_bound(vec.begin(),vec.end(),u)-vec.begin();
			if(p<vec.size() && u==vec[p]){
				ans[t]=-inf;
			}
		}
	}
	dfs(1,0);
	f(i,0,q){
		cout<<(ans[i]<0 ? -1 : ans[i])<<" ";
	}
}
/*
4
1 3
2 3
4 3
1
2 1 2
*/
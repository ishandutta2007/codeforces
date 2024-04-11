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

int n,m,t,a[N],dist[N],deg[N];
vector<int> g[N];

void Main(){
	cin>>n>>m;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		g[v].pb(u);
		deg[u]++;
	}
	set<pair<int,int>> s;
	dist[n]=0;
	f(i,1,n) dist[i]=N;
	f(i,1,n+1) s.insert({dist[i],i});
	while(s.size()){
		int u=(*s.begin()).S;
		s.erase(*s.begin());
		//cout<<u<<" "<<dist[u]<<endl;
		for(auto v : g[u]){
			deg[v]--;
			if(dist[u]+deg[v]+1<dist[v]){
				s.erase({dist[v],v});
				dist[v]=dist[u]+deg[v]+1;
				s.insert({dist[v],v});
			}
		}
	}
	cout<<dist[1]<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin>>t;
	t=1;
	while(t--){
		Main();
	}
}
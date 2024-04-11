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
 
typedef pair<int,int> pii; 

const int N=1e6+99,inf=1e15;

int n,q,p,a[N],dist[N],mark[N];
vector<pair<int,int>> g[N];

void add0(int l,int r,int u,int w,int shift){
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1){
			g[u].pb({l+shift,w});
			l+=1;
		}
		if(r&1){
			r-=1;
			g[u].pb({r+shift,w});
		}
	}
}
void add1(int l,int r,int u,int w,int shift){
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1){
			g[l+shift].pb({u,w});
			l+=1;
		}
		if(r&1){
			r-=1;
			g[r+shift].pb({u,w});
		}
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q>>p; p--;
	while(q--){
		int t,u,v,l,r,w;
		cin>>t;
		if(t==1){
			cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
		}
		if(t==2){
			cin>>u>>l>>r>>w; u--,l--;
			add0(l,r,u,w,n);
		}
		if(t==3){
			cin>>u>>l>>r>>w; u--,l--;
			add1(l,r,u,w,3*n);
		}
	}
	f(i,2,n<<1){
		int par=i>>1;
		g[par+n].pb({i+n,0});
		g[i+3*n].pb({par+3*n,0});
	}
	f(i,n,2*n){
		g[i+n].pb({i-n,0});
		g[i-n].pb({i+3*n,0});
	}
	fill(dist,dist+N,inf);
	priority_queue<pii,vector<pii>,greater<pii>> s;
	dist[p]=0;
	f(i,0,5*n) s.push({dist[i],i});
	while(s.size()){
		auto [d,u]=s.top();
		s.pop();
		if(mark[u]==1) continue ;
		mark[u]=1;
		for(auto [v,w] : g[u]){
			if(d+w>=dist[v]) continue ;
			//s.erase({v,dist[v]});
			dist[v]=d+w;
			s.push({dist[v],v});
		}
	}
	f(i,0,n) cout<<(dist[i]== inf ? -1 : dist[i])<<" "; cout<<'\n';
}
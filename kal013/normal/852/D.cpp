#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> ostream& operator <<(ostream& os, vector<T> V){
	os << "[ "; for(auto v : V) os << v << " "; return os <<"]";
}
template<class L, class R> ostream& operator<<(ostream& os , pair<L, R> P){
	os <<"(" << P.first << " , " << P.second << ")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << endl;
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma=strchr(names+1 , ',');
	cout.write(names, comma-names) << " : " << arg1 << " | ";
	__f(comma+1 , args...);
}
#else
#define trace(...) 1
#endif 
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pii pair<ll, ll>
#define vll vector<ll>
#define vi vector<ll>
#define I insert
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x) x.begin(), x.end()
#define For(i,n) for(ll i = 0;i < n; i++)
#define Rep(i,n) for(ll i = 1;i <= n ;i++)
const ll INF=1e18;
struct edge
{	
	ll x , y  , cap , flow;
};
struct DinicFlow
{
	const ll inf = (1e18);
	vector<edge> e; vll cur, d;
	vector<vll> adj; ll n , source , sink;
	DinicFlow() {}
	DinicFlow(ll v){
		n = v; cur = vll(n+1);
		d = vll(n+1); adj = vector<vll>(n+1);
	}
	void addEdge(ll from, ll to , ll cap){
		edge e1 = {from, to , cap ,0};
		edge e2 = {to , from , 0 , 0};
		adj[from].pb(e.size()); e.pb(e1);
		adj[to].pb(e.size()); e.pb(e2);
	}
	ll bfs(){
		queue<ll> q;
		for(ll i = 0;i <= n ; i++) d[i] = -1;
		q.push(source);
		d[source] = 0;
		while(!q.empty() and d[sink] < 0){
			ll x = q.front(); q.pop();
			for(ll i = 0;i < (ll)adj[x].size() ; ++i){
				ll id = adj[x][i], y = e[id].y;
				if(d[y] < 0 and e[id].flow < e[id].cap){
					q.push(y); d[y] = d[x]+1;
				}
			}

		}
		return d[sink] >= 0;
	}
	ll dfs(ll x , ll flow){
		if(!flow) return 0;
		if(x == sink) return flow;
		for( ; cur[x] < (ll)adj[x].size() ; ++cur[x]){
			ll id = adj[x][cur[x]] , y = e[id].y;
			if(d[y] != d[x] + 1) continue;
			ll pushed = dfs(y , min(flow , e[id].cap - e[id].flow));
			if(pushed){
				e[id].flow += pushed;
				e[id^1].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}
	ll maxFlow(ll src , ll snk){
		this->source = src; this->sink = snk;
		ll flow = 0;
		while(bfs()){
			for(ll i = 0;i <= n ; ++i) cur[i] = 0;
			while(ll pushed = dfs(source , inf))
				flow += pushed;
		}
		return flow;
	}

};	


const ll N=650;
ll d[N][N];

ll cnt[N];


bool pos(ll x,ll k,ll n){
	DinicFlow U(2*n+3);
	ll s=0,t=2*n+2;

	Rep(i,n){
		U.addEdge(s,i,cnt[i]);
	}
	Rep(i,n){
		Rep(j,n){
			if (d[i][j]<=x) U.addEdge(i,j+n,1);
		}
		U.addEdge(i+n,t,1);
	}
	ll res=U.maxFlow(s,t);
	// trace(res);
	return (res>=k);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << setprecision(25);
	ll n,v,e,k,u,a,b,t;
	cin>>v>>e>>n>>k;
	For(i,n){
		cin>>u;
		++cnt[u];
	}
	Rep(i,v){
		Rep(j,v){
			d[i][j]=(i==j)?0:INF;
		}
	}
	Rep(i,e){
		cin>>a>>b>>t;
		d[a][b]=d[b][a]=min(t,d[b][a]);
	}
	Rep(mid,v){
		Rep(src,v){
			Rep(dst,v){
				d[src][dst]=min(d[src][dst],d[src][mid]+d[mid][dst]);
			}
		}
	}
	// Rep(j,v){
	// 	Rep(i,v) trace(i,j,d[i][j]);
	// }
	
	ll lo=0,hi=1731311;
	ll ans=-1;

	while(lo<=hi){
		ll mid=(lo+hi)/2;

		if (pos(mid,k,v)){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, l, x[maxn], d[maxn], t[maxn], p[maxn], dis[maxn], par[maxn], ramp[maxn];

bool vis[maxn];

vector<pll> vec;

vector<ll> ans;

map<ll, ll> id[maxn];

priority_queue<pll> q;

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> l;
	
	vec.pb({0, 0});
	vec.pb({l, 0});
	
	for(ll i = 1; i <= n; i++){
		cin >> x[i] >> d[i] >> t[i] >> p[i];
		vec.pb({x[i] - p[i], i});
		vec.pb({x[i] + d[i], i});
	}
	
	sort(vec.begin(), vec.end());
	
	for(ll i = 0; i < vec.size(); i++){
		swap(vec[i].F, vec[i].S);
		id[vec[i].F][vec[i].S] = i;
		dis[i] = inf;
	}
	
	v = id[0][0];
	
	dis[v] = 0;
	q.push({0, v});
	
	while(!q.empty()){
		v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		if(vec[v].S < 0) continue;
		if(vec[v].F && vec[v].S == x[vec[v].F] - p[vec[v].F]){
			u = id[vec[v].F][x[vec[v].F] + d[vec[v].F]];
			c = p[vec[v].F] + t[vec[v].F];
			if(dis[u] > dis[v] + c){
				dis[u] = dis[v] + c;
				par[u] = v;
				ramp[u] = vec[v].F;
				q.push({-dis[u], u});
			}
		}
		if(v - 1 >= 0){
			u = v - 1;
			c = vec[v].S - vec[u].S;
			if(dis[u] > dis[v] + c){
				dis[u] = dis[v] + c;
				par[u] = v;
				ramp[u] = 0;
				q.push({-dis[u], u});
			}
		}
		if(v + 1 < vec.size()){
			u = v + 1;
			c = vec[u].S - vec[v].S;
			if(dis[u] > dis[v] + c){
				dis[u] = dis[v] + c;
				par[u] = v;
				ramp[u] = 0;
				q.push({-dis[u], u});
			}
		}
	}
	
	v = id[0][l];
	
	u = v;
	
	while(u){
		if(ramp[u]) ans.pb(ramp[u]);
		u = par[u];
	}
	
	cout << dis[v] << '\n' << ans.size() << '\n';
	
	reverse(ans.begin(), ans.end());
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << ' ';
	}
	
	return 0;
}
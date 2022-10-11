//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, v, u, a[maxn], b[maxn];

vector<ll> g[maxn], ans;

queue<ll> q;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == b[i]){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		if(a[v] != b[v]) continue;
		b[v]++;
		ans.pb(v);
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			b[u]++;
			if(a[u] == b[u]){
				q.push(u);
			}
		}
	}
	
	cout << ans.size() << endl;
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 1e5;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, c[maxn], dis[maxn], vis[maxn];
vector<ll> a[maxn];

array<ll, 10> g[maxn], b;
priority_queue<pll> q;
map<array<ll, 10>, ll> mp;
map<array<ll, 10>, ll> bad;

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> c[i];
    	a[i].resize(c[i]);
    	for(ll j = 0; j < c[i]; j++){
    		cin >> a[i][j];
		}
		reverse(all(a[i]));
	}
	cin >> m;
	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < n; j++){
			cin >> b[j];
			b[j] = c[j] - b[j];
		}
		bad[b] = 1;
	}
	ll ptr = 2;
	mp[g[1]] = 1;
	q.push(Mp(-dis[1], 1));
	while(!q.empty()){
		ll v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		array<ll, 10> gu = g[v];
		if(!bad[gu]){
			for(ll i = 0; i < n; i++){
				cout << c[i] - gu[i] << " ";
			}
			cout << "\n";
			return 0;
		}
		for(ll i = 0; i < n; i++){
			if(gu[i] + 1 == c[i]) continue;
			gu[i]++;
			ll u = mp[gu];
			if(u){
				dis[u] = min(dis[u], dis[v] - a[i][gu[i]] + a[i][gu[i] - 1]);
				q.push(Mp(-dis[u], u));
			}
			else{
				u = ptr++;
				mp[gu] = u;
				g[u] = gu;
				dis[u] = dis[v] - a[i][gu[i]] + a[i][gu[i] - 1];
				q.push(Mp(-dis[u], u));
			}
			gu[i]--;
		}
	}
 
    return 0;
}
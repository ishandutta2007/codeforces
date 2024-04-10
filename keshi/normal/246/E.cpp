//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, q, t, st[maxn], ft[maxn], p[maxn], a[maxn], h[maxn], b[maxn], fen[maxn], ls[maxn], ans[maxn];
vector<ll> g[maxn];
vector<ll> vec[maxn];
map<string, ll> mp;
vector<pair<pll, ll> > v2[maxn];

void dfs(ll v){
	b[st[v] = t++] = v;
	vec[h[v]].pb(st[v]);
	for(ll u : g[v]){
		h[u] = h[v] + 1;
		dfs(u);
	}
	ft[v] = t++;
}
void upd(ll x, ll y){
	for(x += 5; x < maxn; x += x & -x){
		fen[x] += y;
	}
	return;
}
ll get(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y += fen[x];
	}
	return y;
}

int main(){
    fast_io;
    
    cin >> n;
    t = 1;
    for(ll i = 1; i <= n; i++){
    	string s;
    	cin >> s;
    	if(!mp[s]) mp[s] = t++;
		a[i] = mp[s];
    	cin >> p[i];
    	g[p[i]].pb(i);
	}
	t = 0;
	dfs(0);
	cin >> q;
	for(ll i = 0; i < q; i++){
		ll v, x;
		cin >> v >> x;
		if(h[v] + x >= maxn) continue;
		ll l = lower_bound(all(vec[h[v] + x]), st[v]) - vec[h[v] + x].begin();
		ll r = lower_bound(all(vec[h[v] + x]), ft[v]) - vec[h[v] + x].begin();
		if(l == r) continue;
		v2[h[v] + x].pb(Mp(Mp(l, r), i));
	}
	for(ll i = 0; i < maxn; i++){
		if(v2[i].empty()) continue;
		sort(all(v2[i]));
		ll ptr = Sz(v2[i]) - 1;
		for(ll j = Sz(vec[i]); j--;){
			ll v = b[vec[i][j]];
			if(ls[a[v]]) upd(ls[a[v]], -1);
			ls[a[v]] = j;
			upd(j, 1);
			while(ptr >= 0 && v2[i][ptr].F.F == j){
				ans[v2[i][ptr].S] = get(v2[i][ptr].F.S - 1);
				ptr--;
			}
		}
		for(ll j = 0; j < Sz(vec[i]); j++){
			ll v = b[vec[i][j]];
			if(ls[a[v]] == j){
				upd(j, -1);
				ls[a[v]] = 0;
			}
		}
	}
	for(ll i = 0; i < q; i++){
		cout << ans[i] << "\n";
	}
 
    return 0;
}
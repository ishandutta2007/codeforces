//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll lg = 20;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, T, c[maxn], t[maxn], p[maxn], l[maxn], h[maxn], b[maxn];
pll a[maxn];
vector<ll> g[maxn];
ll fen1[maxn], fen2[maxn];
void upd(ll x, ll y, ll z){
	for(; x < maxn; x += x & -x){
		fen1[x] += y;
		fen2[x] += z;
	}
}
ll get(ll x){
	ll l = 0, y = 0;
	for(ll i = lg; i--;){
		if(l + (1 << i) <= n && fen2[l + (1 << i)] <= x){
			l += (1 << i);
			x -= fen2[l];
			y += fen1[l];
		}
	}
	if(l < n) y += x / a[l + 1].F;
	return y;
}

ll dfs(ll v){
	upd(b[v], c[v], c[v] * t[v]);
	ll ans = get(T - h[v] * 2);
	ll mx = -inf, xm = -inf;
	for(ll u : g[v]){
		h[u] = h[v] + l[u];
		ll x = dfs(u);
		if(x > xm) swap(x, xm);
		if(xm > mx) swap(xm, mx);
	}
	upd(b[v], -c[v], -c[v] * t[v]);
	if(v == 1) swap(mx, xm);
	return max(ans, xm);
}

int main(){
    fast_io;
    
    cin >> n >> T;
    for(ll i = 1; i <= n; i++){
    	cin >> c[i];
	}
	for(ll i = 1; i <= n; i++){
		cin >> t[i];
		a[i] = Mp(t[i], i);
	}
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++){
		b[a[i].S] = i;
	}
	for(ll i = 2; i <= n; i++){
		cin >> p[i] >> l[i];
		g[p[i]].pb(i);
	}
	cout << dfs(1);
 
    return 0;
}
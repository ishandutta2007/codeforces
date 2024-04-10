//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
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

ll n, q, a[maxn], p[maxn], dp[maxn], ps[maxn], ans[maxn], o[maxn];
vector<pll> g[maxn], vec;

void add(ll j, ll x){
	if(x <= 0){
		vec.pb(Mp(j, x));
		ps[Sz(vec)] = ps[Sz(vec) - 1] + x;
		return;
	}
	if(vec.empty()) return;
	ll y = x;
	for(ll i = 0; i < j - vec.back().F; i++){
		y = y * 2;
		if(y + vec.back().S > mod) break;
	}
	if(y + vec.back().S > mod){
		vec.clear();
		return;
	}
	j = vec.back().F;
	y += vec.back().S;
	vec.pop_back();
	add(j, y);
	return;
}

int main(){
    fast_io;
	p[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = p[i - 1] * 2;
		if(p[i] >= mod) p[i] -= mod;
	}
	cin >> n >> q;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll i = n; i--;){
		dp[i] = (a[i] + dp[i + 1] * 2) % mod;
	}
	for(ll i = 0; i < q; i++){
		ll v, u;
		cin >> v >> u;
		o[i] = v - 1;
		g[u - 1].pb(Mp(v, i));
	}
	for(ll i = 0; i < n; i++){
		add(i, a[i]);
		for(pll j : g[i]){
			ll x = lower_bound(all(vec), Mp(j.F, -inf)) - vec.begin();
			if(x == Sz(vec)){
				ans[j.S] = (dp[j.F] - dp[i + 1] * p[i + 1 - j.F]) % mod;
			}
			else{
				ans[j.S] = (dp[j.F] - dp[vec[x].F] * p[vec[x].F - j.F] + ps[Sz(vec)] - ps[x]) % mod;
			}
		}
	}
	for(ll i = 0; i < q; i++){
		cout << ((a[o[i]] + ans[i] * 2) % mod + mod) % mod << "\n";
	}

    return 0;
}
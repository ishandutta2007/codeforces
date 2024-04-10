//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
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

ll n, g[maxn][26], nxt[maxn][26], par[maxn], q[maxn], t, a[maxn], b[maxn], f[maxn];
vector<ll> gg[maxn];
ll st[maxn], ft[maxn], t2;
string s[maxn];

void bld(){
	ll l = 0, r = 0;
	q[r++] = 0;
	while(l < r){
		ll v = q[l++];
		if(b[v]) f[v] = v;
		else f[v] = f[par[v]];
		for(ll i = 0; i < 26; i++){
			if(g[v][i]){
				nxt[v][i] = g[v][i];
				if(v) par[nxt[v][i]] = nxt[par[v]][i];
				q[r++] = nxt[v][i];
			}
			else{
				nxt[v][i] = nxt[par[v]][i];
			}
		}
	}
}

void dfs(ll v){
	st[v] = t2++;
	for(ll u : gg[v]){
		dfs(u);
	}
	ft[v] = t2;
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		ll x = 0;
		for(char c : s[i]){
			if(!g[x][c - 'a']) g[x][c - 'a'] = ++t;
			x = g[x][c - 'a'];
		}
		a[i] = x;
		b[x] = Sz(s[i]);
	}
	bld();
	for(ll i = 1; i <= t; i++){
		gg[par[i]].pb(i);
	}
	dfs(0);
	long long ans = 0;
	for(ll i = 0; i < n; i++){
		ll x = 0;
		set<pll> h;
		h.insert(Mp(-inf, -inf));
		h.insert(Mp(inf, inf));
		vector<pll> vec;
		vector<ll> vec2;
		ll j = 0;
		for(char c : s[i]){
			if(f[x]){
				ll v = f[x];
				while(!vec.empty() && vec.back().F <= j + b[f[v]]){
					vec2.pb(vec.back().S);
					vec.pop_back();
				}
				vec.pb(Mp(j + b[f[v]], v));
				pll p = Mp(st[v], ft[v]);
				auto it = h.lower_bound(p);
				if(it -> F >= p.S){
					it--;
					if(it -> S > p.F) h.erase(it);
					h.insert(p);
				}
			}
			x = g[x][c - 'a'];
			j--;
		}
		ll v = f[par[x]];
		if(v){
			while(!vec.empty() && vec.back().F <= j + b[f[v]]){
				vec2.pb(vec.back().S);
				vec.pop_back();
			}
			vec.pb(Mp(j + b[f[v]], v));
			pll p = Mp(st[v], ft[v]);
			auto it = h.lower_bound(p);
			if(it -> F >= p.S){
				it--;
				if(it -> S > p.F) h.erase(it);
				h.insert(p);
			}
		}
		for(ll v : vec2){
			h.erase(Mp(st[v], ft[v]));
		}
		ans += Sz(h) - 2;
	}
	cout << ans;
	
	return 0;
}
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll hmod = 1000009559ll;
const ll base = 29;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, q, x, h[maxn], hp[maxn], h2[maxn], hp2[maxn], p[maxn], m, f[maxn], p2[maxn], ps[maxn], ans[maxn];
string s, t, st, sr;
vector<pair<ll, pll> > g[maxn];

int main(){
    fast_io;

	p[0] = p2[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = p[i - 1] * base % hmod;
		p2[i] = p2[i - 1] * 2;
		if(p2[i] >= mod) p2[i] -= mod;
	}
	fill(f, f + maxn, inf);

	cin >> n >> q >> s >> t;
	st = s;
	for(ll i = 0; i <= Sz(s); i++){
		f[i] = 1;
	}
	for(ll i = 0; i < Sz(t); i++){
		if(Sz(st) * 2 + 1 >= maxn) break;
		ll e = Sz(st);
		st = st + t[i] + st;
		for(ll j = e + 1; j <= Sz(st); j++){
			f[j] = i + 2;
		}
	}
	for(ll i = 1; i <= Sz(st); i++){
		h[i] = (h[i - 1] * base + ll(st[i - 1] - 'a')) % hmod;
		hp[i] = (hp[i - 1] + p[i - 1] * ll(st[Sz(st) - i] - 'a')) % hmod;
	}
	for(ll ii = 0; ii < q; ii++){
		cin >> x >> sr;
		m = Sz(sr);
		if(m > Sz(st)){
			cout << "0\n";
			continue;
		}
		for(ll i = 1; i <= m; i++){
			h2[i] = (h2[i - 1] * base + ll(sr[i - 1] - 'a')) % hmod;
			hp2[i] = (hp2[i - 1] + p[i - 1] * ll(sr[Sz(sr) - i] - 'a')) % hmod;
		}
		for(ll i = 0; i < m; i++){
			if(hp[i] == h2[i] && h[m - i - 1] == hp2[m - i - 1]){
				ll y = max(f[i], f[m - i - 1]);
				if(x < y) continue;
				//ans[ii] = (ans[ii] + ps[x][sr[i] - 'a'] - ps[y - 1][sr[i] - 'a'] * p2[x - y + 1]) % mod;
				g[x].pb(Mp(ii, Mp(sr[i] - 'a', 1)));
				g[y - 1].pb(Mp(ii, Mp(sr[i] - 'a', -p2[x - y + 1])));
			}
		}
		if(ans[ii] < 0) ans[ii] += mod;
		for(ll i = 0; i + m <= Sz(s); i++){
			ll e = (h[i + m] - h[i] * p[m]) % hmod;
			if(e < 0) e += hmod;
			if(e == h2[m]){
				ans[ii] += p2[x];
				if(ans[ii] >= mod) ans[ii] -= mod;
			}
		}
	}
	for(ll i = 1; i <= Sz(t); i++){
		for(ll j = 0; j < 26; j++){
			ps[j] = ps[j] * 2;
			if(ps[j] >= mod) ps[j] -= mod;
		}
		ps[t[i - 1] - 'a']++;
		if(ps[t[i - 1] - 'a'] >= mod) ps[t[i - 1] - 'a'] -= mod;
		for(ll j = 0; j < Sz(g[i]); j++){
			ans[g[i][j].F] = (ans[g[i][j].F] + ps[g[i][j].S.F] * g[i][j].S.S) % mod;
		}
	}
	for(ll i = 0; i < q; i++){
		cout << (ans[i] + mod) % mod << "\n";
	}

    return 0;
}
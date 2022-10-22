#include <bits/stdc++.h>

#define fileopen(a, b) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)b + ".out").c_str(), "w", stdout);
#define fileopen1(a) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)a + ".out").c_str(), "w", stdout);

using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
ll const mod = 1e9 + 7, MAXN = 2e5 + 5,oo = 3e18;
    
// fenwick tree
class fenwick {
private : vector<ll> ft;
public :
	vector<ii> save;
	
	fenwick (ll n){
		ft.assign(n + 5,0);
	}
	ll ls (ll x){
		return x & (-x);
	}
	void reset(){
	    for (ll &cur : ft){
	        cur = 0;
	    }
	    save.clear();
	}
	// increase one to avoid zero
	void inc (ll pos,ll val){
		pos++;
		if (pos <= 0) return;
		for ( ; pos < ft.size() ; pos += ls(pos)){
			ft[pos] = (ft[pos] + val + mod) % mod;
		}
	}
	ll rsq (ll pos){
		pos++;
		if (pos <= 0) return 0;
		ll res = 0;
		for ( ; pos ; pos -= ls(pos)){
			res = (res + ft[pos] + mod) % mod;
		}
		return res;
	}
	void update (ll pos,ll val){
		save.pb(mp(pos,val)); inc(pos,val);
	}
	void rollback (ll sz){
		while (save.size() > sz){
			ii cur = save.back(); save.pop_back();
			inc(cur.fi,-cur.se);
		}
	}
};

fenwick black(MAXN); // path (cen,node) starts with black and number of transition
fenwick white(MAXN); // path (cen,node) starts with white and number of transition
fenwick cum_black(MAXN);
fenwick cum_white(MAXN);

ll tc,n,m;
ll a[MAXN],sum[MAXN];
vector<ii> g[MAXN];
ll ANS;

// centroid decomp
ll sz[MAXN];
bool re[MAXN];

ll find_size (ll u,ll p = -1){
	sz[u] = 1;
	for (auto cur : g[u]){
		ll v = cur.fi;
		if (v == p || re[v]) continue;
		sz[u] += find_size(v,u);
	}
	return sz[u];
}

ll find_centroid (ll u,ll sub,ll p = -1){
	for (auto cur : g[u]){
		ll v = cur.fi;
		if (v == p || re[v]) continue;
		if (sz[v] > sub / 2) return find_centroid(v,sub,u);
	}
	return u;
}

ll cur_cen;

void dfs (ll u,ll p,ll col,ll trans,ll cur_down,bool filling){
    
    if (trans > m) return;
    
    if (!filling){
        sum[u] = (sum[p] + a[u] + mod) % mod;
    }

	if (filling){
		// path sum excluding centroid
		ll exc = (sum[u] + mod - a[cur_cen]) % mod;
		if (cur_down == 0){
			black.update(trans,1); cum_black.update(trans,exc);
		}
		else {
			white.update(trans,1); cum_white.update(trans,exc);
		}
	}
	else {
	    
	    if (trans <= m){
	        ANS = (ANS + sum[u] + mod) % mod;
	    }
	    
	    ll tmp = 0;
		if (cur_down == 0){
			tmp = sum[u] * black.rsq(m - trans) % mod;
			tmp = (tmp + cum_black.rsq(m - trans)) % mod;
			tmp = (tmp + sum[u] * white.rsq(m - 1 - trans) % mod) % mod;
			tmp = (tmp + cum_white.rsq(m - 1 - trans)) % mod;
			//cout << "node " << u << " " << tmp << endl;
			ANS = (ANS + tmp) % mod;
		}
		else {
			tmp = sum[u] * white.rsq(m - trans) % mod;
			tmp = (tmp + cum_white.rsq(m - trans)) % mod;
			tmp = (tmp + sum[u] * black.rsq(m - 1 - trans) % mod) % mod;
			tmp = (tmp + cum_black.rsq(m - 1 - trans)) % mod;
			//cout << "node " << u << " " << tmp << endl;
			ANS = (ANS + tmp) % mod;
		}
	}

	for (auto edge : g[u]){
		ll v = edge.fi,t = edge.se;
		if (v == p || re[v]) continue; 
		if (t != col){
			dfs(v,u,t,trans + 1,cur_down,filling);
		}
		else {
			dfs(v,u,t,trans,cur_down,filling);
		}
	}
}

void centroid (ll u = 1){
	u = find_centroid (u,find_size(u));
	re[u] = true; cur_cen = u;
	// save size
	
	//cout << "centroid " << u << " " << ANS << endl;
	
	ll black_size = black.save.size();
	ll white_size = white.save.size();
	ll cum_black_size = cum_black.save.size();
	ll cum_white_size = cum_white.save.size();

	sum[u] = a[u];
	for (auto edge : g[u]){
		ll v = edge.fi,t = edge.se;
		if (re[v]) continue;
		dfs(v,u,t,0,t,0); dfs(v,u,t,0,t,1);
	}

	// rollback everything
	black.rollback(black_size); white.rollback(white_size);
	cum_black.rollback(cum_black_size); cum_white.rollback(cum_white_size);
    
	for (auto edge : g[u]){
		ll v = edge.fi;
		if (re[v]) continue;
		centroid(v);
	}
}


void caau(){
	// calm
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i];
		ANS = (ANS + a[i] + mod) % mod;
	}
	for (int i = 1 ; i < n ; i++){
		ll u,v,w; cin >> u >> v >> w;
		g[u].pb(mp(v,w)); g[v].pb(mp(u,w));
	}
	centroid();
	cout << ANS << endl;
}

signed main() {
#ifdef thisiscaau
	fileopen("input", "output");
#endif
#ifndef thisiscaau
	// fileopen1("LAH");
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	tc = 1;
	while (tc--) caau();
}
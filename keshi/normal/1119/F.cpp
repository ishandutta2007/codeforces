//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
const ll lg = 20;
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

ll n, h[maxn], ti, st[maxn], ft[maxn], dp[maxn][2], ind[maxn], pd[maxn], sx[maxn];
pll par[maxn];
vector<pll> g[maxn];
bool vis[maxn];
vector<pll> vec[maxn], pnx[maxn], fen[maxn];
vector<ll> v2[maxn], ve[maxn];
set<pll> s, t;

void upd(ll id, ll x, pll y){
	for(; x < Sz(fen[id]); x += x & -x){
		fen[id][x].F += y.F;
		fen[id][x].S += y.S;
	}
	return;
}

void dfs(ll v){
	st[v] = ti++;
	vis[v] = 1;
	for(pll u : g[v]){
		if(vis[u.F]){
			par[v] = u;
			continue;
		}
		sx[v] += u.S;
		dfs(u.F);
		vec[v].pb(Mp(u.S, u.F));
	}
	ft[v] = ti;
	sort(all(vec[v]), greater<pll>());
//	cout << "! " << v << "\n";
//	for(pll u : vec[v]){
//		cout << u.F << " " << u.S << " - ";
//	}
//	cout << "\n";
	for(ll i = 0; i < Sz(vec[v]); i++){
		ind[vec[v][i].S] = i + 1;
	}
	pnx[v].resize(Sz(vec[v]) + 2);
	fen[v].resize(Sz(vec[v]) + 2);
	for(ll i = 0; i < Sz(pnx[v]); i++){
		pnx[v][i] = Mp(i - 1, i + 1);
	}
	for(ll i = 0; i < Sz(vec[v]); i++){
		upd(v, i + 1, Mp(1ll, vec[v][i].F));
	}
	return;
}
ll g2(ll id, ll x){
	ll y = 0;
	for(; x > 0; x -= x & -x){
		y += fen[id][x].S;
	}
	return y;
}
pll get(ll id, ll x){
//	cout << "get " << id << " " << x << "\n";
	if(x == 0) return Mp(0ll, 0ll);
	ll y = 0;
	for(ll i = lg; i--;){
		if(y + (1ll << i) >= Sz(fen[id]) - 1) continue;
		if(fen[id][y + (1ll << i)].F < x){
			y += (1ll << i);
			x -= fen[id][y].F;
		}
	}
//	cout << "^ "  << y + 1 << "  " << g2(id, y + 1) << "\n";
	return Mp(y + 1, g2(id, y + 1));
}

int main(){
    //fast_io;

	cin >> n;
	for(ll i = 1; i < n; i++){
		ll v, u, c;
		cin >> v >> u >> c;
		g[v].pb(Mp(u, c));
		g[u].pb(Mp(v, c));
		pd[0] += c;
	}
	for(ll i = 1; i <= n; i++){
		v2[Sz(g[i])].pb(i);
	}
	dfs(1);
	for(ll i = n - 1; i > 0; i--){
//		cout << "------ " << i << " -------\n";
		for(ll v : v2[i]){
			ll u = par[v].F;
			ll j = ind[v];
			s.insert(Mp(-st[v], v));
			if(v == 1) continue;
			pnx[u][pnx[u][j].F].S = pnx[u][j].S;
			pnx[u][pnx[u][j].S].F = pnx[u][j].F;
			upd(u, j, Mp(-1ll, -par[v].S));
			ve[u].pb(v);
			sx[u] -= par[v].S;
		}
		for(pll jj : s){
			ll v = jj.S;
			dp[v][0] = dp[v][1] = inf;
//			cout << "?          " << v << " " << st[v] << " " << ft[v] << "\n";
			auto it = t.lower_bound(Mp(st[v], v));
			ll x = sx[v];
//			for(pll y : t){
//				cout << y.F << " " << y.S << " - ";
//			}
//			cout << "\n";
			while(it != t.end() && it->F < ft[v]){
				ll u = it->S;
//				cout << "x " << u << "\n";
				if(par[u].F == v){
//					cout << "*\n";
					x += min(dp[u][0], dp[u][1]) + par[u].S;
				}
				else{
					x += min(dp[u][0] + par[u].S, dp[u][1]);
				}
				it = t.erase(it);
//				cout << "@ " << it->F << " " << it->S << "\n";
			}
			vector<ll> vc;
			for(ll u : ve[v]){
				if(dp[u][1] < min(dp[u][0], dp[u][1]) + par[u].S){
					vc.pb(par[u].S + min(dp[u][0], dp[u][1]) - dp[u][1]);
				}
			}
			sort(all(vc));
			reverse(all(vc));
			dp[v][0] = min(dp[v][0], x - get(v, i).S);
			if(Sz(vc) > i){
				vc.resize(i);
			}
//			cout << "%   ";
			for(ll j : vc){
//				cout << j << " ";
				x -= j;
			}
//			cout << "\n";
//			cout << " !! " << x << "\n";
			if(Sz(vc) == i){
				dp[v][0] = min(dp[v][0], x);
				x += vc.back();
				vc.pop_back();
			}
			pll p = get(v, i - Sz(vc) - 1);
			x -= p.S;
			ll j = p.F;
//			cout << "wtf " << p.F << " " << p.S << "\n";
//			cout << "ha\n";
			cout.flush();
			dp[v][1] = min(dp[v][1], x);
//			cout << " @@ " << x << "\n";
			for(ll k = Sz(vc); k--;){
				if(j < Sz(pnx[v])) j = pnx[v][j].S;
				if(j > 0 && j - 1 < Sz(vec[v])) x -= vec[v][j - 1].F;
//				cout << "$ " << k << " " << j << " " << x << "\n";
				dp[v][0] = min(dp[v][0], x);
				x += vc[k];
				dp[v][1] = min(dp[v][1], x);
			}
			dp[v][0] = min(dp[v][0], dp[v][1]);
//			cout << "# " << v << " " << dp[v][0] << " " << dp[v][1] << "\n";
			t.insert(Mp(st[v], v));
		}
		for(pll u : t){
//			cout << "$ " << u.F << " " << u.S << "\n";
			pd[i] += min(dp[u.S][0] + par[u.S].S, dp[u.S][1]);
		}
		t.clear();
	}
	for(ll i = 0; i < n; i++){
		cout << pd[i] << " ";
	}

    return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()


using namespace std;

const ll N = 6e5 + 10;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll n, m;

vector<pill> g[N];

vector<pair<pill, ll>> q[N];

ll ans[N];

pill z[N];

struct seg {
	ll t[4 * N] = {0};
	ll u[4 * N] = {0};
	void push(ll v) {
		u[v * 2] += u[v];
		u[v * 2 + 1] += u[v];
		t[v] += u[v];
		u[v] = 0;
	}
	void upd(ll l, ll r, ll x, ll v = 1, ll tl = 1, ll tr = n) {
		push(v);
		if(l > tr || tl > r)
			return;
		if(l <= tl && tr <= r) {
			u[v] += x;
			push(v);
			return;
		}
		ll tm = (tl + tr) >> 1;
		upd(l, r, x, v * 2, tl, tm);
		upd(l, r, x, v * 2 + 1, tm + 1, tr);
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
	ll get(ll l, ll r, ll v = 1, ll tl = 1, ll tr = n) {
		push(v);
		if(l > tr || tl > r)
			return big;
		if(l <= tl && tr <= r) 
			return t[v];
		ll tm = (tl + tr) / 2;
		return min(get(l, r, v * 2, tl, tm),
				   get(l, r, v * 2 + 1, tm + 1, tr));
	}
} t;

void dfs(ll v = 1,ll W = 0, ll l = 1, ll r = n) {
	z[v] = {l, r};
	if(r - l)
		t.upd(v, v, big);
	else
		t.upd(v, v, W);
	int i = 0;
	for(auto u : g[v]) {
		if(i == g[v].size() - 1)
			dfs(u.f,W + u.s, u.f, r);
		else
			dfs(u.f,W + u.s, u.f, g[v][i + 1].f - 1);
		i++;
	}
}

void otv(ll v) {
	for(auto u : q[v]) {
		ans[u.s] = t.get(u.f.f, u.f.s);
	}
}

void perepod(ll v = 1,ll w = 0) {
	t.upd(1, n, w);
	t.upd(z[v].f, z[v].s, -2 * w);
	otv(v);
	for(auto u : g[v])
		perepod(u.f, u.s);
	t.upd(1, n, -w);
	t.upd(z[v].f, z[v].s, 2 * w);
}

int main() {
    speed;
	cin >> n >> m;
	for(int i = 2 ; i <= n ; i++) {
		ll a, w;
		cin >> a >> w;
		g[a].pb({i, w});
	}	
	ll z = 0;
	while(m--) {
		ll v1, l, r;
		cin >> v1 >> l >> r;
		q[v1].pb({{l, r}, z});
		z++;
	}
	dfs();
	perepod();
	for(int i = 0 ; i < z ; i++)
		cout << ans[i] << '\n';
}

/*
	11 1
	1 7
	2 1
	1 20
	1 2
	5 6
	6 2
	6 3
	5 1
	9 10
	9 11
	11 4 5
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
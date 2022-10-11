//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll sq = 320;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, t, g[maxn][26], nxt[maxn][26], q[maxn], par[maxn], a[maxn], asq[maxn], bsq[maxn], ans[maxn], cnt[maxn], ps[maxn];
string s[maxn];
vector<ll> vec[maxn], b[maxn], gg[maxn];
vector<pair<pll, ll> > qe[maxn];

void bld(){
	ll l = 0, r = 0;
	q[r++] = 0;
	while(l < r){
		ll v = q[l++];
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

void upd(ll x, ll y){
	x += 5;
	ll i = 0;
	while((i + 1) * sq <= x){
		asq[i++] += y;
	}
	for(ll j = i * sq; j <= x; j++){
		bsq[j] += y;
	}
}
ll get(ll x){
	x += 5;
	return asq[x / sq] + bsq[x];
}

void dfs(ll v){
	for(ll i : b[v]){
		upd(i, 1);
	}
	for(ll i : vec[v]){
		for(auto x : qe[i]){
			ans[x.S] += get(x.F.F) - get(x.F.S);
		}
	}
	for(ll u : gg[v]){
		dfs(u);
	}
	for(ll i : b[v]){
		upd(i, -1);
	}
}
void dfs2(ll v){
	for(ll u : gg[v]){
		dfs2(u);
		cnt[v] += cnt[u];
	}
	for(ll i : b[v]){
		ps[i + 5] += cnt[v];
	}
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		ll x = 0;
		for(char c : s[i]){
			if(!g[x][c - 'a']) g[x][c - 'a'] = ++t;
			x = g[x][c - 'a'];
			if(Sz(s[i]) < sq) vec[x].pb(i);
		}
		a[i] = x;
		b[x].pb(i);
	}
	bld();
	for(ll i = 0; i < m; i++){
		ll l, r, x;
		cin >> l >> r >> x;
		l--;
		x--;
		qe[x].pb(Mp(Mp(l, r), i));
	}
	for(ll i = 1; i <= t; i++){
		gg[par[i]].pb(i);
	}
	dfs(0);
	for(ll i = 0; i < n; i++){
		if(Sz(s[i]) < sq) continue;
		fill(cnt, cnt + t + 10, 0);
		fill(ps, ps + n + 10, 0);
		ll x = 0;
		for(char c : s[i]){
			x = g[x][c - 'a'];
			cnt[x]++;
		}
		dfs2(0);
		for(ll j = 1; j < n + 10; j++){
			ps[j] += ps[j - 1];
		}
		for(auto x : qe[i]){
			ans[x.S] = ps[x.F.S + 5 - 1] - ps[x.F.F + 5 - 1];
		}
	}
	for(ll i = 0; i < m; i++){
		cout << ans[i] << "\n";
	}
	
	return 0;
}
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ll sig = 26;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()


namespace aho{
ll nxt[maxn][sig], t, F[maxn], h[maxn], q[maxn];
vector<ll> g[maxn];

ll add(string s){
	ll x = 0;
	for(char c : s){
		if(!nxt[x][c - 'a']) h[nxt[x][c - 'a'] = ++t] = h[x] + 1;
		x = nxt[x][c - 'a'];
	}
	return x;
}

void bld_aho(){
	ll l = 0, r = 0;
	for(ll i = 0; i < sig; i++){
		if(nxt[0][i]) q[r++] = nxt[0][i];
	}
	while(l < r){
		ll v = q[l++];
		g[F[v]].pb(v);
		for(ll i = 0; i < sig; i++){
			if(nxt[v][i]){
				F[nxt[v][i]] = nxt[F[v]][i];
				q[r++] = nxt[v][i];
			}
			else nxt[v][i] = nxt[F[v]][i];
		}
	}
}
}

namespace fen{
ll fen[maxn];
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
}

ll n, m, tt, a[maxn], st[maxn], ft[maxn], is[maxn];

void dfs(ll v){
	st[v] = tt++;
	for(ll u : aho::g[v]){
		dfs(u);
	}
	ft[v] = tt;
}

ll get(ll v){
	return fen::get(st[v]);
}
void upd(ll v, ll x){
	fen::upd(st[v], x);
	fen::upd(ft[v], -x);
}

int main(){
    fast_io;

	cin >> m >> n;
	for(ll i = 0; i < n; i++){
		string s;
		cin >> s;
		a[i] = aho::add(s);
	}
	aho::bld_aho();
	dfs(0);
	for(ll i = 0; i < n; i++){
		upd(a[i], 1);
		is[i] = 1;
	}

	for(ll i = 0; i < m; i++){
		char c;
		cin >> c;
		if(c == '?'){
			string s;
			cin >> s;
			ll v = 0;
			long long x = 0;
			for(char ch : s){
				v = aho::nxt[v][ch - 'a'];
				x += get(v);
			}
			cout << x << "\n";
		}
		if(c == '+'){
			ll x;
			cin >> x;
			if(!is[x - 1]) upd(a[x - 1], 1);
			is[x - 1] = 1;

		}
		if(c == '-'){
			ll x;
			cin >> x;
			if(is[x - 1]) upd(a[x - 1], -1);
			is[x - 1] = 0;
		}
	}


    return 0;
}
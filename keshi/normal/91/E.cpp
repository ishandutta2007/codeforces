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
#define lc (id << 1)
#define rc (lc | 1)

ll n, q, a[maxn], b[maxn];
vector<pll> vec[maxn << 2];

ll flr(ll x, ll y){
	return x / y - ll((x ^ y) < 0 && (x / y) * y != x);
}

ll cal(ll i, ll j){
	return flr(a[i] - a[j], b[j] - b[i]);
}
bool cmp(ll i, ll j){
	return (Mp(b[i], -a[i]) <= Mp(b[j], -a[j]));
}

void add(ll id, ll i){
	if(!vec[id].empty() && b[vec[id].back().S] == b[i]) return;
	while(Sz(vec[id]) > 1 && vec[id].back().F >= cal(vec[id].back().S, i)) vec[id].pop_back();
	if(vec[id].empty()) vec[id].pb(Mp(-inf, i));
	else vec[id].pb(Mp(cal(vec[id].back().S, i), i));
	return;
}
pll query(ll id, ll x){
	ll i = vec[id][lower_bound(all(vec[id]), Mp(x, -inf)) - vec[id].begin() - 1].S;
	return Mp(a[i] + b[i] * x, i);
}

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		vec[id].pb(Mp(-inf, s));
		return;
	}
	ll mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	ll pl = 0, pr = 0;
	while(pl < Sz(vec[lc]) || pr < Sz(vec[rc])){
		if(pr == Sz(vec[rc]) || (pl < Sz(vec[lc]) && cmp(vec[lc][pl].S, vec[rc][pr].S))) add(id, vec[lc][pl++].S);
		else add(id, vec[rc][pr++].S);
	}
	return;
}
pll get(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return Mp(-inf, -inf);
	if(l <= s && e <= r) return query(id, x);
	ll mid = (s + e) >> 1;
	return max(get(lc, s, mid, l, r, x), get(rc, mid, e, l, r, x));
}

int main(){
    fast_io;

	cin >> n >> q;
	for(ll i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	bld(1, 0, n);
	for(ll i = 0; i < q; i++){
		ll l, r, x;
		cin >> l >> r >> x;
		cout << get(1, 0, n, l - 1, r, x).S + 1 << "\n";
	}

    return 0;
}
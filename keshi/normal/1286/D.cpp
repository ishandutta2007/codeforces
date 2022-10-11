//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull od(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};
FastMod M(mod);

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], v[maxn], p[maxn], pp[maxn], ans;
ll seg[maxn][2][2];
bool val[maxn][2][2];
vector<pair<pll, pll> > vec;

ll powlog(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = M.od(c * a);
		a = M.od(a * a);
		b >>= 1;
	}
	return c;
}

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		seg[id][0][0] = p[s];
		seg[id][1][1] = pp[s];
		return;
	}
	ll mid = (s + e) / 2;
	bld(id * 2, s, mid);
	bld(id * 2 + 1, mid, e);
	seg[id][0][0] = seg[id][0][1] = seg[id][1][0] = seg[id][1][1] = 0;
	for(ll i = 0; i < 2; i++){
		for(ll j = 0; j < 2; j++){
			for(ll k = 0; k < 2; k++){
				for(ll o = 0; o < 2; o++){
					if(val[mid][j][k]) seg[id][i][o] += M.od(seg[id * 2][i][j] * seg[id * 2 + 1][k][o]);
				}
			}
		}
	}
	for(ll i = 0; i < 2; i++){
		for(ll j = 0; j < 2; j++){
			seg[id][i][j] = M.od(seg[id][i][j]);
		}
	}
	return;
}
bool cmp(pair<pll, pll> c1, pair<pll, pll> c2){
	return (c1.S.F * c2.S.S < c2.S.F * c1.S.S);
}
void upd(ll id, ll s, ll e, ll l){
	if(l <= s || l >= e) return;
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l);
	upd(id * 2 + 1, mid, e, l);
	seg[id][0][0] = seg[id][0][1] = seg[id][1][0] = seg[id][1][1] = 0;
	for(ll i = 0; i < 2; i++){
		for(ll j = 0; j < 2; j++){
			for(ll k = 0; k < 2; k++){
				for(ll o = 0; o < 2; o++){
					if(val[mid][j][k]) seg[id][i][o] += M.od(seg[id * 2][i][j] * seg[id * 2 + 1][k][o]);
				}
			}
		}
	}
	for(ll i = 0; i < 2; i++){
		for(ll j = 0; j < 2; j++){
			seg[id][i][j] = M.od(seg[id][i][j]);
		}
	}
	for(ll i = 0; i < 2; i++){
		for(ll j = 0; j < 2; j++){
			seg[id][i][j] = M.od(seg[id][i][j]);
		}
	}
	return;
}

int main(){
	fast_io;
	ll x = powlog(100, mod - 2);
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i] >> v[i] >> p[i];
		p[i] = M.od(p[i] * x);
		pp[i] = M.od(mod + 1 - p[i]);
		val[i][0][0] = val[i][0][1] = val[i][1][0] = val[i][1][1] = 1;
	}
	bld(1, 0, n);
	for(ll i = 1; i < n; i++){
		vec.pb(Mp(Mp(i, 1), Mp(a[i] - a[i - 1], v[i] + v[i - 1])));
		if(v[i] > v[i - 1]) vec.pb(Mp(Mp(i, 3), Mp(a[i] - a[i - 1], v[i] - v[i - 1])));
		if(v[i] < v[i - 1]) vec.pb(Mp(Mp(i, 0), Mp(a[i] - a[i - 1], v[i - 1] - v[i])));
	}
	sort(vec.begin(), vec.end(), cmp);
	for(ll i = 0; i < vec.size(); i++){
		ll x = M.od(seg[1][0][0] + seg[1][0][1] + seg[1][1][0] + seg[1][1][1]);
		val[vec[i].F.F][vec[i].F.S / 2][vec[i].F.S % 2] = 0;
		upd(1, 0, n, vec[i].F.F);
		x -= M.od(seg[1][0][0] + seg[1][0][1] + seg[1][1][0] + seg[1][1][1]);
		if(x < 0) x += mod;
		ans = M.od(ans + M.od(x * vec[i].S.F) * powlog(vec[i].S.S, mod - 2));
	}
	cout << ans;
	
	return 0;
}
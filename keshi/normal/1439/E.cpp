//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 2e9;
const ll del = 1e9 + 1;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

pll nxt(pll a){
	ll x = a.F, y = a.S;
	if(x == 0 || y == 0) return Mp(0, 0);
	if((y & ((x & -x) - 1)) == 0) return Mp(x - (x & ((y & -y) - 1)), y);
	return Mp(x, y - (y & ((x & -x) - 1)));
}

ll n;
pair<pll, pll> a[maxn];
vector<pair<ll, pll> > vec;

int main(){
    fast_io;

	cin >> n;
	vector<pll> v1, v2, v3, v4;
	for(ll i = 0; i < n; i++){
		cin >> a[i].F.F >> a[i].F.S >> a[i].S.F >> a[i].S.S;
		v1.clear();
		v2.clear();
		v3.clear();
		v4.clear();
		v1.pb(a[i].F);
		v2.pb(a[i].S);
		while(v1.back() != Mp(0, 0)) v1.pb(nxt(v1[Sz(v1) - 1]));
		while(v2.back() != Mp(0, 0)) v2.pb(nxt(v2[Sz(v2) - 1]));
		reverse(all(v1));
		reverse(all(v2));
		while(Sz(v1) < Sz(v2)) v1.pb(v1[Sz(v1) - 1]);
		while(Sz(v2) < Sz(v1)) v2.pb(v2[Sz(v2) - 1]);
		bool f = 1;
		for(ll j = 0; j < Sz(v1) && j < Sz(v2); j++){
			if(v1[j] == v2[j]) continue;
			if(f && (v1[j].F == v1[j - 1].F) == (v2[j].F == v2[j - 1].F)){
				pll p = min(v1[j], v2[j]);
				if(p == v1[j]) v4.pb(p);
				else v3.pb(p);
			}
			else if(f){
				v3.pb(v1[j - 1]);
				v4.pb(v2[j - 1]);
			}
			v3.pb(v1[j]);
			v4.pb(v2[j]);
			f = 0;
		}
		if(v3.empty()){
			v3 = v1;
			v4 = v2;
		}
		while(Sz(v3) > 1 && v3[Sz(v3) - 1] == v3[Sz(v3) - 2]) v3.pop_back();
		while(Sz(v4) > 1 && v4[Sz(v4) - 1] == v4[Sz(v4) - 2]) v4.pop_back();
		if(v3[0].S & (v3[0].F - 1)) vec.pb(Mp(v3[0].F, Mp(v3[0].S - 1, v3[0].S)));
		else vec.pb(Mp(v3[0].S + del, Mp(v3[0].F - 1, v3[0].F)));
		for(ll j = 0; j + 1 < Sz(v3); j++){
			if(v3[j].F == v3[j + 1].F){
				vec.pb(Mp(v3[j].F, Mp(v3[j].S, v3[j + 1].S)));
			}
			else{
				vec.pb(Mp(v3[j].S + del, Mp(v3[j].F, v3[j + 1].F)));
			}
		}
		v3.swap(v4);
		for(ll j = 0; j + 1 < Sz(v3); j++){
			if(v3[j].F == v3[j + 1].F){
				vec.pb(Mp(v3[j].F, Mp(v3[j].S, v3[j + 1].S)));
			}
			else{
				vec.pb(Mp(v3[j].S + del, Mp(v3[j].F, v3[j + 1].F)));
			}
		}
	}
	sort(all(vec));
	map<ll, ll> cnt;
	ll prv;
	for(ll i = 0; i < Sz(vec); i++){
		if(i == 0 || vec[i].F != vec[i - 1].F) prv = -inf;
		ll x = vec[i].F;
		if(x >= del) x -= del;
		cnt[x + max(prv, vec[i].S.F)]++;
		cnt[x + max(prv, vec[i].S.S)]++;
		prv = max(prv, vec[i].S.S);
	}
	cnt[-1] = 0;
	ll ans = 0;
	for(auto x : cnt){
		if(x.S & 1) ans++;
	}
	cout << ans;

    return 0;
}
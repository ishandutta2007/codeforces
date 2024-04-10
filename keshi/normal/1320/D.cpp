//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll cmod = 3;
const ll mod[cmod] = {1000000007, 1000696969, 998244353};
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
FastMod M[cmod] = {FastMod(mod[0]), FastMod(mod[1]), FastMod(mod[2])};

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, h[cmod][maxn], hp[cmod][maxn], ps[maxn], p[cmod][maxn];
string s;
vector<ll> vec;

ll get(ll c, ll l, ll r){
	ll x = M[c].od(h[c][l - 1] * p[c][r - l]);
	if(h[c][r - 1] >= x) return h[c][r - 1] - x;
	return h[c][r - 1] - x + mod[c];
}
ll getp(ll c, ll l, ll r){
	ll x = M[c].od(hp[c][l - 1] * p[c][r - l]);
	if(hp[c][r - 1] >= x) return hp[c][r - 1] - x;
	return hp[c][r - 1] - x + mod[c];
}

int main(){
	fast_io;
	for(ll i = 0; i < cmod; i++){
		p[i][0] = 1;
	}
	for(ll i = 1; i < maxn; i++){
		for(ll j = 0; j < cmod; j++){
			p[j][i] = p[j][i - 1] * 2;
			if(p[j][i] >= mod[j]) p[j][i] -= mod[j];
		}
	}
	
	cin >> n >> s;
	vec.pb(0);
	for(ll i = 0; i < n; i++){
		ps[i + 1] = ps[i];
		if(s[i] == '0') vec.pb(i + 1);
		else ps[i + 1]++;
	}
	vec.pb(n + 1);
	for(ll i = 1; i < vec.size(); i++){
		for(ll j = 0; j < cmod; j++){
			h[j][i] = M[j].od(h[j][i - 1] * 2 + ps[vec[i]] % 2);
			hp[j][i] = M[j].od(hp[j][i - 1] * 2 + 1 - ps[vec[i]] % 2);
		}
	}
	ll l1, l2, r1, r2, t;
	bool f, fp;
	cin >> m;
	for(ll i = 0; i < m; i++){
		cin >> l1 >> l2 >> t;
		if(ps[l2 + t - 1] - ps[l2 - 1] != ps[l1 + t - 1] - ps[l1 - 1]){
			cout << "No\n";
			continue;
		}
		if(ps[l2 + t - 1] == ps[l2 - 1] + t){
			cout << "Yes\n";
			continue;
		}
		fp = 0;
		if(ps[l1 - 1] % 2 != ps[l2 - 1] % 2) fp = 1;
		r1 = lower_bound(vec.begin(), vec.end(), l1 + t) - vec.begin();
		l1 = lower_bound(vec.begin(), vec.end(), l1) - vec.begin();
		r2 = lower_bound(vec.begin(), vec.end(), l2 + t) - vec.begin();
		l2 = lower_bound(vec.begin(), vec.end(), l2) - vec.begin();
		bool f = 1;
		for(ll j = 0; j < cmod; j++){
			if(fp == 0 && get(j, l1, r1) != get(j, l2, r2)) f = 0;
			if(fp && get(j, l1, r1) != getp(j, l2, r2)) f = 0;
		}
		cout << (f ? "Yes\n" : "No\n");
	}
	
	return 0;
}
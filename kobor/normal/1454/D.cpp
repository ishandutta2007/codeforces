#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define X first
#define Y second

ll binary_gcd(ll u, ll v){
    if(min(u, v) == 0) return u|v;
    int shift = __builtin_ctzll(u|v);
    u >>= __builtin_ctzll(u);
    while(v){
        v >>= __builtin_ctzll(v);
        if(u > v) swap(u, v);
        v -= u;
    }
    return u << shift;
}

ll pov(ll base, ll exp, ll mod){
	ll ret = 1;
	while(exp){
		if(exp&1) ret = (__int128)ret * base % mod;
		base = (__int128)base * base % mod;
		exp >>= 1;
	}
	return ret;
}

bool check_composite(ll n, int a, ll d, int s){
	ll x = pov(a, d, n);
	if(x == 1 || x == n-1) return 0;
	FOR(r, 0, s-1){
		x = (__int128)x * x % n;
		if(x == n-1) return 0;
	}
	return 1;
}

bool MillerRabin(ll n, int iter = 5){
	if(n < 4) return  n == 2 || n == 3;
	int s = __builtin_ctzll(n-1);
	ll d = (n-1) >> s;
	FOR(i, 0, iter){
		int a = rand() % (n-3) + 2;
		if(check_composite(n, a, d, s)) return 0;
	}
    return 1;
}

ll rho_pollard(ll n){
	if((n&1) == 0) return 2;
	ll x, y, c, g = 1;
	x = y = rand() % n + 1;
	c = rand() % n + 1;
	while(g == 1){
		x = ((__int128)x*x+c) % n;
		y = ((__int128)y*y+c) % n;
		y = ((__int128)y*y+c) % n;
		g = binary_gcd(abs(x-y), n);
	}
	return g;
}

void factorize(ll num, vector<ll> &facts){
	if(num == 1) return;
	if(MillerRabin(num)){
		facts.PB(num);
		return;
	}
	ll divis = rho_pollard(num);
	factorize(divis, facts);
	factorize(num/divis, facts);
}

void solve(){
	ll n;
	cin >> n;
	vector<ll> f;
	factorize(n, f);
	sort(f.begin(), f.end());
	vector<pair<ll, int>> fc;
	TRAV(x, f){
		if(SZ(fc) == 0 || x != fc.back().X) fc.PB({x, 0});
		fc.back().Y++;
	}
	int maks = 0;
	TRAV(x, fc) maks = max(maks, x.Y);
	cout << maks << '\n';
	FOR(i, 0, maks){
		ll val = 1;
		TRAV(x, fc) if(i+x.Y >= maks) val *= x.X;
		cout << val << ' ';
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}
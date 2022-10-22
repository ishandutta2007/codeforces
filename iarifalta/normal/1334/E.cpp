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

const ll N = 1e5;
const ll big = 1e18;
const ll block = 800;
const ll mod = 998244353;

vector<ll> razl;

ll D, q;

ll u, v;

ll fact[N];

ll ifact[N];

ll bin_pow(ll x,ll s) {
	if(!s)
		return 1;
	if(s % 2)
		return (bin_pow(x, s - 1) * x) % mod;
	ll z = bin_pow(x, s / 2);
	return (z * z) % mod;
}

ll inv(ll x) {
	return bin_pow(x, mod - 2);
}

void precalc() {
	fact[0] = 1;
	for(int i = 1; i < N; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		ifact[i] = inv(fact[i]);
	}
}

ll ans(ll z) {
	ll gl = 0;
	ll dw = 1;
	for(int i = 0 ; i < razl.size() ; i++) {
		u = razl[i];
		if(z % u)
			continue;
		ll loc = 0;
		while(z % u == 0)
			z /= u,loc++;
		dw = (dw * ifact[loc]) % mod;
		gl += loc;
	}
	return (fact[gl] * dw) % mod;
}

int main() {
	speed;
	precalc();
	cin >> D >> q;
	ll x = D;
	for(ll i = 2 ; i * i <= x ; i++) {
		if(x % i == 0) {
			razl.pb(i);
			while(x % i == 0)
				x /= i;
		}
	}
	if(x > 1)
		razl.pb(x);
	while(q--) {
		cin >> u >> v;
		ll p = __gcd(u, v);
		cout << (ans(u / p) * ans(v / p)) % mod << '\n';
	}
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
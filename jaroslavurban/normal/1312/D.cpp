#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector

#define N 300000
#define mod 998244353
ll powermod (ll b, ll p){
    ll res = 1;
	b %= mod;
    while (p) {
        if (p & 1) res = (res*b)%mod;
        b = (b*b)%mod;
        p >>= 1;
    }
    return res;
}

ll inv (ll x) {
    return powermod(x, mod-2);
}

ll mul(ll x, ll y){
	return (x * y) % mod;
}

ll divide(ll x, ll y){
	return mul(x, inv(y));
}

ll add(ll x, ll y){
	x = (x + y) % mod;
	while (x < 0) x += mod;
	return x;
}

ll F[N];

void compF(){
	F[0] = 1;
	for (ll i = 1; i < N; ++i)
		F[i] = mul(F[i-1], i);
}


int main(){
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	compF();
	if (n > 2)
		ans = mul(divide(F[m], mul(F[n-1], F[m-(n-1)])), mul(n-2, powermod(2, n-3)));
	cout << ans << endl;
}
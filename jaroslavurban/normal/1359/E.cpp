#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

#define N 500010
#define mod 998244353
ll powmod(ll a,ll b){
	if(!b)return 1;
	if(b%2)return powmod(a*a%mod,b/2)*a%mod;
	return powmod(a*a%mod,b/2);
}
ll powermod (ll x, ll n){
    if (n==0) return 1;
    if (n==1) return x;
    if (n%2==0) return powermod((x*x)%mod, n/2);
    if (n%2==1) return (x*powermod((x*x)%mod, n/2))%mod;
}

// black magic, x^mod-1 is supposed to equal to 1, so 1/x is x^mod-2
// WORKS ONLY IF MOD IS PRIME -- use extended euclid otherwise
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

// factorial for all numbers upto N;
ll F[N];

void compF(){
    F[0] = 1;
    for (ll i = 1; i < N; ++i)
        F[i] = mul(F[i-1], i);
}


int main(){
	ll n,k;cin>>n>>k;
	compF();
	ll res=0;
	for(int i=1;i*k<=n;++i)
		res=add(res,divide(F[n/i-1],mul(F[k-1],F[n/i-k])));
	cout<<res<<endl;
}
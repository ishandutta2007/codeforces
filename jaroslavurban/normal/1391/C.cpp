#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const ll mod=1e9+7;
const int N=1000010;
ll powermod (ll x, ll n){
    if (n==0) return 1;
    if (n==1) return x;
    if (n%2==0) return powermod((x*x)%mod, n/2);
    if (n%2==1) return (x*powermod((x*x)%mod, n/2))%mod;
}
ll mul(ll x, ll y){
    return (x * y) % mod;
}

ll inv (ll x) {
    return powermod(x, mod-2);
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
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	compF();
	ll n;cin>>n;
	ll pos=1;
	for(int i=n;i>1;--i)pos=mul(pos,i);
	ll res=0;
	for(int i=0;i<n;++i)res=res+divide(F[n-1],mul(F[n-i-1],F[i]));
	cout<<add(pos,-res)<<endl;
}
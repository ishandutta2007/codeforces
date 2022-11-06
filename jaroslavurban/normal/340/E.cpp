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



const int N=2020,mod=1e9+7;
ll powmod(ll a,ll b){
	if(!b)return 1;
	if(b%2)return powmod(a*a%mod,b/2)*a%mod;
	return powmod(a*a%mod,b/2);
}

// black magic, x^mod-1 is supposed to equal to 1, so 1/x is x^mod-2
// WORKS ONLY IF MOD IS PRIME -- use extended euclid otherwise
ll inv (ll x) {
    return powmod(x, mod-2);
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


int a[N];
bool found[N];
int n,emp,conf;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	compF();
	for(int i=0;i<n;++i)
		if(~a[i])found[a[i]]=true;
		else ++emp;
	for(int i=0;i<n;++i)
		if(a[i]==-1&&!found[i+1])++conf;

	ll res=F[emp];
	for(int i=1;i<=conf;++i)
		res=add(res,(i%2?-1:1)*F[emp-i]*divide(F[conf],mul(F[conf-i],F[i]))%mod);
	cout<<res<<endl;
}
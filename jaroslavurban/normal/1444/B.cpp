#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300100,mod=998244353;
int a[N];
ll f[N];
int n;

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

ll divide(ll x, ll y){
    return x* inv(y)%mod;
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<2*n;++i)cin>>a[i];
	f[0]=1;
	for(int i=1;i<=2*n;++i)f[i]=f[i-1]*i%mod;
	ll sm=0;
	sort(a,a+2*n);
	for(int i=0;i<n;++i)sm+=-a[i];
	for(int i=n;i<2*n;++i)sm+=a[i];
	sm%=mod;
	cout<<divide(f[2*n],f[n]*f[n]%mod)*sm%mod<<endl;;
}
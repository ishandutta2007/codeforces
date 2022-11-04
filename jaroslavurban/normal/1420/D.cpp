#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll mod=998244353;
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

const int N=300100;
// factorial for all numbers upto N;
ll F[N];

void compF(){
    F[0] = 1;
    for (ll i = 1; i < N; ++i)
      F[i] = mul(F[i-1], i);
}
pair<int,int>segs[2*N];
int n,k;
ll res;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	compF();
	for(int i=0;i<n;++i){
		int l,r;cin>>l>>r;
		segs[2*i]={l,0};
		segs[2*i+1]={r,1};
	}
	sort(segs,segs+2*n);
	ll cnt=0;
	for(int i=0;i<2*n;++i){
		int t=segs[i].second;
		if(t){--cnt;continue;}
		++cnt;
		if(cnt>=k)res=add(res,divide(F[cnt-1],mul(F[k-1],F[cnt-k])));
	}
	cout<<res<<endl;
}
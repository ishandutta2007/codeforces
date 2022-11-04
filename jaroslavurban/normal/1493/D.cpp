#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100,mod=1e9+7;
vector<int>g[N];
int n,q;
unordered_map<int,int>a[N];
ll res=1;

ll powmod(ll a,ll b){
	if(!b)return 1;
	if(b%2)return powmod(a*a%mod,b/2)*a%mod;
	return powmod(a*a%mod,b/2);
}

ll inv (ll x) {
    return powmod(x, mod-2);
}

ll mul(ll x, ll y){
    return (x * y) % mod;
}

ll divide(ll x, ll y){
    return mul(x, inv(y));
}

vector<ll> prime; // a[i]=highest prime factor of i
vector<ll> erat (ll n){
    prime = vector<ll>(n,0);
    vector<ll> primes;
    prime[0] = prime[1] = 1;
    for (ll i = 2; i < n; ++i){
        if (!prime[i]){
            primes.push_back(i);
            for (ll j = i; j < n; j += i) prime[j] = i;
        }
    }
    return primes;
}

void add(int p,int cnt){
	if(g[p].empty())g[p].push_back(0);
	assert(cnt<=g[p].size());
	if(g[p].size()==cnt)g[p].push_back(0);
//	cerr<<p<<" "<<cnt<<" "<<g[p][cnt]<<endl;
	if(++g[p][cnt]==n)res=mul(res,p);
}

void mulnum(int idx,int val){
	while(val!=1){
//		cerr<<idx<<" "<<val<<" "<<prime[val]<<endl;
		add(prime[val],++a[idx][prime[val]]);
		val/=prime[val];
	}
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	erat(N);
	cin>>n>>q;
	for(int i=0;i<n;++i){
		int ca;cin>>ca;mulnum(i,ca);
	}
//	cout<<res<<endl;
	int i,x;
	while(q--){
		cin>>i>>x;--i;
		mulnum(i,x);
		cout<<res<<'\n';
	}
}
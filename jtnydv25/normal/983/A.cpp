#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll mod = 1e16 + 61;

ld inv = 1. / (ld)mod;

ll mul(ll a, ll b){
    ll x = (ll)((ld)a*(ld)b*inv +(ld)(1)/2.);
    ll ret = a*b-mod*x;
    if((ll)(ret) < 0)
        ret+=mod;
    return ret;
}

ll add(ll a, ll b){
	 a += b;
	 if(a >= mod) a -= mod;
	 return a;
}

ll sub(ll a, ll b){
	a -= b;
	if(a < 0) a += mod;
	return a;
}

string get(ll p, ll q, ll b){
	p %= q;
	mod = q;
	inv = 1. / (ld)mod;
	for(int i = 0; i <= 62; i++){
		if(p == 0) return "Finite";
		p = mul(p, b);
	}
	return "Infinite";
}

int main(){
	ll p, q, b;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld %lld", &p, &q, &b);
		printf("%s\n", get(p, q, b).c_str());
	}
}
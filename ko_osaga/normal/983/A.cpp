#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint mul(lint a, lint b, lint mod){
	a %= mod;
	b %= mod;
	lint ans = 0;
	while(b){
		if(b & 1){
			ans += a;
			if(ans >= mod) ans -= mod;
		}
		b >>= 1;
		a <<= 1;
		if(a >= mod) a -= mod;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		lint p, q, b;
		scanf("%lld %lld %lld",&p,&q,&b);
		lint real = __gcd(p, q);
		q /= real;
		for(int i=0; i<6; i++){
			b = mul(b, b, q);
		}
		b %= q;
		if(b == 0) puts("Finite");
		else puts("Infinite");
	}
}
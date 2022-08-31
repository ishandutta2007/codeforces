#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

lint ipow(lint x, lint p){
	lint ret = 1, piv = x % mod;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret % mod;
}

//f(n) = (2 * (-1) ^ n + 2 ^ n)  / (3 * 2 ^ n)
// f(n) = 1/3 * (2 ^ n-1 += (-1)^n) / (2^(n-1))
// if n = 2k, f(n) = 1/3 (1 + 2^n-1) / (2^n-1)
// else f(n) = 1/3 (-1 + 2^n-1) / (2^n-1)
// (T + 1) / 3T
// (T - 1) / 3T

int main(){
	lint t = 2;
	int q;
	scanf("%d",&q);
	int even = 0;
	while(q--){
		lint x;
		scanf("%lld",&x);
		t = ipow(t, x);
		if(x % 2 == 0) even = 1;
	}
	t *= ipow(2, mod - 2);
	t %= mod;
	lint k = t;
	if(even) k++;
	else k += mod - 1;
	k *= ipow(3, mod - 2);
	k %= mod;
	printf("%lld/%lld", k, t);

}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a, b, c, ax, ay = -1;

void f(ll x){
	ll aa = (a + x - 1) / x * x;
	ll bb = (b + x - 1) / x * x;
	ll t = aa * bb / x;
	ll y = aa - a;
	if(ay < 0 || t < ax || (t == ax && ay > y)){
		ax = t;
		ay = y;
	}
}

int main(){
	scanf("%lld%lld", &a, &b);
	if(a < b) swap(a, b);
	if(a == b){ puts("0"); return 0; }
	c = a - b;
	for(ll i = 1; i * i <= c; i++){
		if(c % i) continue;
		f(i);
		f(c / i);
	}
	printf("%lld\n", ay);
}
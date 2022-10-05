#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int q;
	ll k, n, a, b;
	scanf("%d", &q);
	while(q--){
		scanf("%lld%lld%lld%lld", &k, &n, &a, &b);
		ll s = 0, e = n;
		while(s <= e){
			ll m = (s + e) / 2;
			if(a * m + b * (n - m) < k) s = m + 1;
			else e = m - 1;
		}
		printf("%lld\n", e);
	}
}
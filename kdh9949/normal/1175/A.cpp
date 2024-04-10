#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll x, y;
		scanf("%lld%lld", &x, &y);
		ll r = 0;
		while(x){
			r += (x % y) + 1;
			x /= y;
		}
		printf("%lld\n", r - 1);
	}
}
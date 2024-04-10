#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll a, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &a, &m);
		ll x = m / __gcd(a, m), y = x, ans = x;
		for(int i = 2;1ll * i * i <= y && x != 1;i++){
			if(x % i == 0){
				while(x % i == 0) x /= i;
				ans /= i, ans *= i - 1;
			}
		}
		if(x != 1) ans /= x, ans *= x - 1;
		printf("%lld\n", ans);
	}
}
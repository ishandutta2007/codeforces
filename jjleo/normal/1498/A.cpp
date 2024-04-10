#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll n;

ll sum(ll n){
	ll x = 0;
	while(n) x += n % 10, n /= 10;
	return x;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		for(;;n++){
			if(__gcd(sum(n), n) > 1){
				printf("%lld\n", n); 
				break;
			}
		}
	} 
}
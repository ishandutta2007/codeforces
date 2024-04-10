#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, s;
ll n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%d", &n, &s);
		int sum = 0;
		for(ll i = n;i;i /= 10) sum += i % 10;
		if(sum <= s){
			puts("0");
			continue;
		} 
		ll ans = 0;
		ll y = 1;
		while(1){
			int x = n % 10;
			n /= 10;
			if(x) ans += (10 - x) * y, n++;
			y *= 10;
			sum = 0;
			for(ll i = n;i;i /= 10) sum += i % 10;
			if(sum <= s){
				printf("%lld\n", ans);
				break;
			}
		}
	}
}
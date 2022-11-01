#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll a, b, c, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld%lld%lld", &a, &c, &b, &d);
		if(a == b || c == d){
			puts("1");
			continue;
		}
		ll x = min(b - a, d - c);
		if(x == 1) printf("%lld\n", 1 + max(b - a, d - c)); 
		else printf("%lld\n", x * (x - 1) + x + 1 + abs(b - a + (d - c) - 2 * (x - 1) - 2) * x); 
	}
}
#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

ll t, n, x, y, a, b;

int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld%lld", &n, &x, &y);
		ll b = 0;
		while(n--) scanf("%lld", &a), b ^= a;
		puts((x ^ b ^ y) & 1 ? "Bob" : "Alice");
	}
}
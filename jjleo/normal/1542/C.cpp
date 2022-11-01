#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

const int p = 1e9 + 7;

int t;
ll n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		__int128 sum = 1;
		int ans = 0;
		for(int i = 2;n;i++){
			ll x = i / __gcd(sum, (__int128)i);
			ans = (ans + (n - n / x) % p * (i % p)) % p;
			n /= x, sum *= x;
			//printf("%lld %lld--\n", n, x);
		}
		printf("%d\n", ans);
	}
}
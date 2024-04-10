#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

ll x;
ll ans = 1;
ll a[maxn];
int cnt = -1;

ll X, Y;


int main(){
	scanf("%lld", &x);
	if(x == 1) return printf("1 1"), 0;
	ll y = x;
	for(ll i = 2;i * i <= x && y != 1;i++){
		ll z = 1;
		while(y % i == 0) y /= i, z *= i;
		if(z ^ 1) a[++cnt] = z;
	}
	if(y != 1) a[++cnt] = y;
	ll sum = 1e18;
	for(int i = 0;i < (1 << (cnt + 1));i++){
		x = 1, y = 1;
		for(int j = 0, k = 1;j <= cnt;j++, k <<= 1){
			if(i & k) x *= a[j];
			else y *= a[j];
		}
		if(max(x, y) < sum){
			sum = max(x, y), X = x, Y = y;
		}
	}
	printf("%lld %lld", X, Y);
}
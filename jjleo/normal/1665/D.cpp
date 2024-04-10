#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

void exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) x = 1, y = 0;
	else exgcd(b, a % b, y, x), y -= a / b * x;
}

inline ll inv(ll a, ll p){
    ll x, y;
    exgcd(a, p, x, y);
    return x < 0 ? x + p : x;
}

int a[9];

int t;
const int p[9] = {2, 3, 7, 11, 13, 17, 19, 23, 29};

int main(){
	scanf("%d", &t);
	int sum = 1;
	for(int i = 0;i < 9;i++) sum *= p[i];
	while(t--){
		for(int i = 1;i <= 29;i++){
			printf("? %d %d\n", i, i + sum), fflush(stdout);
			int x;
			scanf("%d", &x);
			for(int j = 0;j < 9;j++) if(x % p[j] == 0) a[j] = (p[j] - i % p[j]) % p[j];
		}
		ll ans = 0;
		for(int i = 0;i < 9;i++) ans += 1ll * a[i] * sum / p[i] * inv(sum / p[i], p[i]);
		printf("! %lld\n", ans % sum);
	}
}
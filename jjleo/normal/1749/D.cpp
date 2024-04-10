#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

const int p = 998244353;

typedef long long ll;

int n;
ll m;
int prm[maxn], cnt;
bool tag[maxn];

int main(){
	scanf("%d%lld", &n, &m);
	for(int i = 2;i <= n;i++){
		if(!tag[i]) prm[++cnt] = i;
		for(int j = 1;j <= cnt && prm[j] * i <= n;j++){
			tag[prm[j] * i] = true;
			if(i % prm[j] == 0) break;
		}
	}
	int val = 1, sum = 1, ans = 0;
	ll x = 1;
	for(int i = 2;i <= n;i++){
		val = 1ll * val * (m % p) % p;
		if(x <= m && !tag[i]) x = x * i / __gcd(x, 1ll * i);
		sum = 1ll * sum * (m / x % p) % p;
		ans = (ans + 1ll * val + p - sum) % p;
	}
	printf("%lld", 1ll * ans * (m % p) % p);
}
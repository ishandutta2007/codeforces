#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1000000007;
int n;
ll a[200010], ans, f[200010], fi[200010];

ll pw(ll x, ll k){
	if(k == 1) return x;
	return (k % 2 ? x : 1) * pw(x * x % M, k / 2) % M;
}

ll cm(int n, int r){
	if(r < 0 || r > n) return 0;
	return f[n] * fi[r] % M * fi[n - r] % M;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	f[0] = 1;
	for(int i = 1; i <= 200005; i++) f[i] = f[i - 1] * i % M;
	for(int i = 0; i <= 200005; i++) fi[i] = pw(f[i], M - 2);
	for(int i = 1; i <= n; i++){
		ll c;
		if(n % 4 == 0){
			c = (i % 2 ? 1 : -1) * cm(n / 2 - 1, (i - 1) / 2);
		}
		else if(n % 4 == 1){
			c = (i % 2 ? 1 : 0) * cm(n / 2, (i - 1) / 2);
		}
		else if(n % 4 == 2){
			c = cm(n / 2 - 1, (i - 1) / 2);
		}
		else{
			if(i == 1) c = 1;
			else c = cm(n / 2 - 1, (i - 1) / 2) + (i % 2 ? -1 : 1) * cm(n / 2 - 1, (i - 2) / 2);
		}
		while(c < 0) c += M;
		ans += c * a[i] % M;
		ans %= M;
	}
	printf("%lld\n", ans);
}
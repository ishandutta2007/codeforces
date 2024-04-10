#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

typedef long long ll;

int n, k;
ll f[maxn];
int l[maxn], r[maxn], a[maxn];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d%d%d", &l[i], &r[i], &a[i]);
	for(int i = n;i;i--){
		ll x = a[i];
		if(r[i] == l[i + 1]) x += f[i + 1];
		f[i] = max(0ll, x - 1ll * (r[i] - l[i]) * k);
		if(f[i] > k) return printf("-1"), 0;
	}
	ll ans = 0, x = k;
	for(int i = 1;i <= n;i++){
		if(x < f[i]) ans += x, x = k;
		ans += a[i], x = (x + k - a[i] % k) % k;
	}
	printf("%lld", ans);
}
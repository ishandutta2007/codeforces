#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

int n;
ll x;
ll a[maxn];
ll ans;

inline ll cal(int x){
	return 1ll * a[x] * (a[x] + 1) / 2;
}

int main(){
	scanf("%d%lld", &n, &x);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]), a[i + n] = a[i];
	n *= 2;
	int l = n / 2 + 1;
	ll sum = 0;
	ll y = 0;
	while(l > 1 && y + a[l - 1] <= x) y += a[--l], sum += cal(l);
	for(int i = n / 2 + 1;i <= n;i++){
		y += a[i], sum += cal(i);
		while(y > x) y -= a[l], sum -= cal(l++);
		if(y < x){
			ans = max(ans, sum + 1ll * (x - y) * (a[l - 1] + a[l - 1] - (x - y) + 1) / 2);
		}else{
			ans = max(ans, sum);
		}
		/*if(x <= a[i]) ans = max(ans, 1ll * x * (a[i] + a[i] - x + 1) / 2);
		if(tag[i - 1]) sum -= cal(i - 1), y -= a[i - 1];
		r = max(r, i - 1);
		while(r + 1 < n){
			if(y + a[r + 1] <= x) r++, tag[r] = true, sum += cal(r), y += a[r];
			else break;
		}
		printf("%d %d--\n", i, r);
		ll z = min(x - y, a[i - 1]);
		ans = max(ans, sum + 1ll * z * (a[i - 1] + a[i - 1] - z + 1) / 2 + 1ll * (x - y - z) * (x - y - z + 1) / 2);*/
	}
	printf("%lld", ans);
}
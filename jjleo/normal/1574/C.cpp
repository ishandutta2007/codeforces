#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
ll a[maxn];
int m;
ll x, y;

int main(){
	scanf("%d", &n);
	ll sum = 0;
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]), sum += a[i];
	sort(a + 1, a + 1 + n);
	scanf("%d", &m);
	while(m--){
		scanf("%lld%lld", &x, &y);
		int pos = lower_bound(a + 1, a + 1 + n, x) - a;
		ll ans = 4e18;
		if(pos <= n) ans = min(ans, max(0ll, x - a[pos]) + max(0ll, y - (sum - a[pos])));
		pos--;
		if(pos >= 1) ans = min(ans, max(0ll, x - a[pos]) + max(0ll, y - (sum - a[pos])));
		printf("%lld\n", ans);
	}
}
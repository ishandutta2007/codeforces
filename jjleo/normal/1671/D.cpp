#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n, x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		ll ans = 0;
		for(int i = 2;i <= n;i++) ans += abs(a[i] - a[i - 1]);
		int mn = *min_element(a + 1, a + 1 + n), mx = *max_element(a + 1, a + 1 + n);
		ans += min({(mn - 1) * 2, a[1] - 1, a[n] - 1});
		if(mx <= x) ans += min({(x - mx) * 2, x - a[n], x - a[1]});
		printf("%lld\n", ans);
	}
}
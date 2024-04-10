#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n;
ll a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%lld", &b[i]);
		ll ans = min(abs(a[1] - b[1]) + abs(a[n] - b[n]), abs(a[1] - b[n]) + abs(a[n] - b[1]));
		ll a1 = 2e9, b1 = 2e9, an = 2e9, bn = 2e9;
		for(int i = 1;i <= n;i++){
			a1 = min(a1, abs(a[1] - b[i]));
			b1 = min(b1, abs(b[1] - a[i]));
			an = min(an, abs(a[n] - b[i]));
			bn = min(bn, abs(b[n] - a[i]));
		}
		ans = min(ans, a1 + b1 + an + bn);
		ans = min(ans, abs(a[1] - b[1]) + an + bn);
		ans = min(ans, abs(a[n] - b[n]) + a1 + b1);
		ans = min(ans, abs(a[1] - b[n]) + an + b1);
		ans = min(ans, abs(a[n] - b[1]) + a1 + bn);
		printf("%lld\n", ans);
	}
}
#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n = 4;
pair<ll, ll> p[maxn];
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 1;i <= n;i++) scanf("%lld%lld", &p[i].first, &p[i].second);
		for(int i = 1;i <= n;i++) a[i] = i;
		ll ans = 1e18;
		do{
			ll lu = a[1], ld = a[2], ru = a[3], rd = a[4];
			ll xsegl = min(abs(min(p[lu].first, p[ld].first) - max(p[ru].first, p[rd].first)), abs(max(p[lu].first, p[ld].first) - min(p[ru].first, p[rd].first)));
			ll xsegr = max(abs(min(p[lu].first, p[ld].first) - max(p[ru].first, p[rd].first)), abs(max(p[lu].first, p[ld].first) - min(p[ru].first, p[rd].first)));
			ll ysegl = min(abs(min(p[lu].second, p[ru].second) - max(p[ld].second, p[rd].second)), abs(max(p[lu].second, p[ru].second) - min(p[ld].second, p[rd].second)));
			ll ysegr = max(abs(min(p[lu].second, p[ru].second) - max(p[ld].second, p[rd].second)), abs(max(p[lu].second, p[ru].second) - min(p[ld].second, p[rd].second)));
			ll sum = 
				abs(p[lu].first - p[ld].first) +
				abs(p[ru].first - p[rd].first) +
				abs(p[lu].second - p[ru].second) +
				abs(p[ld].second - p[rd].second) +
				2 * max(0ll, max(xsegl, ysegl) - min(xsegr, ysegr));
			ans = min(ans, sum);
		}while(next_permutation(a + 1, a + 1 + n));
		printf("%lld\n", ans);
	}
}
#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int n;
i64 a[maxN];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	i64 ans = 1ll << 60;
	for (int i = 1; i <= n; i++) {
		i64 num = 0, tmp = 0;
		for (int j = i + 1; j <= n; j++) {
			i64 v = (num + a[j]) / a[j];
			tmp += v;
			num = v * a[j];
		}
		num = 0;

		for (int j = i - 1; j >= 1; j--) {
			i64 v = (num + a[j]) / a[j];
			tmp += v;
			num = v * a[j];
		}
		ans = min(ans, tmp);
	}
	printf("%lld\n", ans);
}
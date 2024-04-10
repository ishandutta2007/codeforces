#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
ll x, f,a[200001];
int main() {
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)scanf("%lld", a + i);
	scanf("%lld%lld", &x, &f);
	ll ans = 0;
	for (i = 0; i < n; i++)ans += (a[i]+f-1) / (x + f);
	printf("%lld", ans*f);
}
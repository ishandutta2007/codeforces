#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[35],sa[1<<17],sb[1<<18];
int main() {
	int n,a,b,i,j;
	ll m;
	scanf("%d%lld", &n, &m);
	for (i = 0; i < n; i++)scanf("%d", num + i);
	a = n / 2, b = n - a;
	for (i = 0; i < 1 << a; i++) {
		for (j = 0; j < a; j++)if ((i >> j) & 1)sa[i] += num[j];
		sa[i] %= m;
	}
	for (i = 0; i < 1 << b; i++) {
		for (j = 0; j < b; j++)if ((i >> j) & 1)sb[i] += num[j + a];
		sb[i] %= m;
	}
	sort(sa, sa + (1 << a));
	sort(sb, sb + (1 << b));
	ll ans = 0;
	for (i = 0; i < 1 << a; i++)ans = max(ans, (sa[i] + sb[(1 << b) - 1]) % m);
	int cur = (1 << b) - 1;
	for (i = 0; i < 1 << a; i++) {
		while (b&&sa[i] + sb[cur] >= m)cur--;
		ans = max(ans, (sa[i] + sb[cur]) % m);
	}
	printf("%d", ans);
}
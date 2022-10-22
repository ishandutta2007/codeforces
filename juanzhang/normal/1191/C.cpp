#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
ll n, k, a[maxn];
int m, pos;

ll get(ll x) {
	return (x - 1) / k + 1;
}

int main() {
	scanf("%I64d %d %I64d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%I64d", a + i);
	}
	pos = 1;
	int val = 0, ans = 0;
	while (pos <= m) {
		int cnt = 0;
		ll now = get(a[pos] - val);
		while (pos <= m && get(a[pos] - val) == now) {
			pos++, cnt++;
		}
		val += cnt, ans++;
	}
	printf("%d", ans);
  return 0;
}
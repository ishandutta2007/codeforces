#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[100001];
int main() {
	int n, m,i,ans=0; ll l;
	scanf("%d%d%lld", &n, &m, &l);
	for (i = 1; i <= n; i++)scanf("%lld", h + i);
	bool cur = 0;
	for (i = 1; i <= n; i++) {
		if (h[i] <= l)ans += cur, cur = 0;
		else cur = 1;
	}
	ans += cur;
	while (m--) {
		int a, b;
		scanf("%d", &a);
		if (a == 0)printf("%d\n", ans);
		else {
			scanf("%d%d", &a, &b);
			h[a] += b;
			if (h[a] <= l || h[a] - b > l)continue;
			int num=0;
			if (h[a - 1] > l)num++;
			if (h[a + 1] > l)num++;
			ans += 1 - num;
		}
	}
	getchar(); getchar();
}
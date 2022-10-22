#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100002];
int main() {
	int n,m, i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)scanf("%d", a + i);
	a[0] = 0;
	a[n + 1] = m;
	int on = 0, off = 0;
	int ans = 0;
	for (i = n; i >= 0; i--) {
		if (i % 2)off += a[i+1]-a[i] - 1;
		else on += a[i + 1] - a[i] - 1;
		if(a[i+1]!=a[i]+1)ans = max(ans, off - on);
		if (i % 2)off ++;
		else on ++;
	}
	printf("%d", ans + on);
}
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

int n, m;
LL a[100010], sum[100010], ans;
LL nc[100010], tnc;

void l(int i, int p) {
	if(p <= 0 || a[i-1] >= a[i] - p) return ;
	LL nans;
	if(i & 1) nans = nc[i] - p + sum[n] - sum[i] - (tnc - nc[i]);
	else nans = nc[i-1] + p + sum[n] - sum[i] - (tnc - nc[i-1]);
	ans = max(ans, nans);
}

int main() {
	scanf("%d%d", &n, &m);
	++ n;
	for(int i=1; i<=n; i++) {
		if(i < n) scanf("%lld", &a[i]);
		else a[i] = m;

		sum[i] = sum[i-1] + a[i] - a[i-1];

		if(i & 1) {
			ans += a[i] - a[i-1];
			if(i == 1) nc[i] = a[i];
			else nc[i] = nc[i-2] + a[i] - a[i-1];
		}
	}
	tnc = (n & 1) ? nc[n] : nc[n-1];

	for(int i=1; i<=n; i++) l(i, 1), l(i, a[i]-a[i-1]-1);
	printf("%lld\n", ans);
	return 0;
}
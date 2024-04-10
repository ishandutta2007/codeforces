#include <cstdio>

typedef long long LL;

int n, m, w;
LL a[100010], d[100010];

bool Check(LL mid) {
	LL cnt = 0, now = 0, c, r;
	for(int i = 1; i <= n; i ++) d[i] = 0;
	for(int i = 1; i <= n; i ++) {
		if(a[i] + now < mid)  {
			c = mid - now - a[i];
			r = i + w - 1;
			if(r <= n) d[r] -= c;
			cnt += c;
			now += c;
			if(cnt > m) return false;
		}
		now += d[i];
	}
	return cnt <= m;
}

int main() {
	scanf("%d%d%d", &n, &m, &w);
	for(int i = 1; i <= n; i ++)
		scanf("%lld", &a[i]);
	LL l = 0, r = 1e17, mid, ans = -1;
	while(l <= r) {
		mid = l + r >> 1;
		if(Check(mid)) l = (ans = mid) + 1;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
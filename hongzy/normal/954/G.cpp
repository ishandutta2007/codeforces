#include <cstdio>

typedef long long LL;

int n, w;
LL a[500010], d[500010], cf[500010], m, r;

bool Check(LL mid) {
	LL cnt = 0, now = 0, c, r;
	for(int i = 1; i <= n; i ++) d[i] = 0;
	for(int i = 1; i <= n; i ++) {
		now += cf[i];
		if(now < mid)  {
			c = mid - now;
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
	scanf("%d%d%lld", &n, &r, &m);
	w = 2 * r + 1;
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
		LL lf = i - r;
		if(lf < 1) lf = 1;
		LL rt = i + r;
		if(rt > n) rt = n;
		cf[lf] += a[i];
		cf[rt + 1] -= a[i];
	}
	LL l = 0, r = 2e18, mid, ans = 0;
	while(l <= r) {
		mid = (unsigned long long)l + r >> 1;
		if(Check(mid)) l = (ans = mid) + 1;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
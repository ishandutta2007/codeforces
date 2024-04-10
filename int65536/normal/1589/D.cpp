#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll query(ll l, ll r) {
	if (l >= r) {
		return 0;
	}
	printf("? %lld %lld\n", l + 1, r + 1);
	fflush(stdout);
	ll count;
	scanf("%lld", &count);
	return count;
}

ll dfs(ll l, ll r) {
	if (l == r) {
		return l;
	}
	ll m = (l + r) / 2;
	ll total = query(0, m);
	if (total == 0) {
		return dfs(m + 1, r);
	}
	else {
		return dfs(l, m);
	}
}

void output(ll p1, ll p2, ll p3) {
	printf("! %lld %lld %lld\n", p1 + 1, p2 + 1, p3 + 1);
	fflush(stdout);
}

int main()
{
	int t;
	for (scanf("%d", &t); t > 0; --t) {
		ll n;
		scanf("%lld", &n);

		ll total = query(0, n - 1);
		ll s = dfs(0, n - 1);
		--s;
		ll x = total - query(s + 1, n - 1) + 1;
		ll lo = 1;
		ll hi = n + 1;
		while (hi - lo > 1) {
			ll y = (lo + hi) / 2;
			if (x * (x - 1) / 2 + y * (y - 1) / 2 <= total) {
				lo = y;
			} else {
				hi = y;
			}
		}
		ll y = lo;
		output(s, s + x, s + x + y - 1);
	}
	return 0;
}
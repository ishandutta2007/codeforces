#if 0
2020.03.31

 k = 2 

 k > 2 x^k  O(V^(2/k))  x^k 
 log 
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 100005;
int tot[maxn];

int main () {
	int n = read, k = read;
	ll ans = 0;

	if (k == 2) {
		for (int i = 1; i <= n; i ++) {
			int x = read, y = 1;
			for (int d = 2; d * d <= x; d ++)
				if (x % d == 0) {
					int t = 0;
					while (x % d == 0) x /= d, ++ t;
					if (t & 1) y *= d;
				}
			if (x > 1)
				y *= x;
			ans += tot[y];
			++ tot[y];
		}
	}

	else {
		std::vector<ll> ve;
		ll V = 100000;
		for (int x = 1; x <= V; x ++) {
			ll y = 1;
			for (int i = 0; i < k and y <= V * V; i ++) y *= x;
			if (y <= V * V) ve.push_back(y);
		}

		for (int i = 1; i <= n; i ++) {
			int x = read;
			for (ll y : ve)
				if (y % x == 0 and y / x <= V)
					ans += tot[y / x];
			++ tot[x];
		}
	}

	printf("%lld\n", ans);
}
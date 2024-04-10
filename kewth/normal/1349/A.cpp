#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 200005;
int minp[maxn];
std::vector<int> pv[maxn];

int main () {
	int N = 200000;
	minp[1] = 1;
	for (int i = 2; i <= N; i ++) {
		if (!minp[i]) {
			for (int j = i; j <= N; j += i)
				if (!minp[j])
					minp[j] = i;
		}
	}

	int n = read;
	for (int i = 1; i <= n; i ++) {
		int x = read;
		while (x > 1) {
			int p = minp[x], k = 0;
			while (x % p == 0)
				x /= p, ++ k;
			pv[p].push_back(k);
		}
	}

	ll ans = 1;
	for (int i = 1; i <= N; i ++)
		if (minp[i] == i and int(pv[i].size()) >= n - 1) {
			if (int(pv[i].size()) == n - 1)
				pv[i].push_back(0);
			std::sort(pv[i].begin(), pv[i].end());
			int k = pv[i][1];
			while (k --) ans *= i;
		}

	printf("%lld\n", ans);
}
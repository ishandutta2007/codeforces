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

const int maxn = 1010;
ll h[maxn];
std::vector<int> a, b, ans;

int X[maxn], Y[maxn];
ll query (int o, int i, int j, int k) {
#ifdef LOCAL
	ll x1 = X[j] - X[i], y1 = Y[j] - Y[i];
	ll x2 = X[k] - X[i], y2 = Y[k] - Y[i];
	ll cross = x1 * y2 - x2 * y1;
	if (o == 1) return std::abs(cross * 2);
	if (o == 2) return cross > 0 ? 1 : -1;
	return 666;
#else
	printf("%d %d %d %d\n", o, i, j, k);
	fflush(stdout);
	return read;
#endif
}

void solve (int start, std::vector<int> &v) {
	int mid = 0;
	for (int x : v)
		if (h[x] > h[mid])
			mid = x;
	std::vector<int> v1, v2;
	for (int x : v)
		if (x != mid) {
			if (query(2, start, mid, x) < 0) v1.push_back(x);
			else v2.push_back(x);
		}
	std::sort(v1.begin(), v1.end(), [](int x, int y) {
				return h[x] < h[y];
			});
	std::sort(v2.begin(), v2.end(), [](int x, int y) {
				return h[x] > h[y];
			});
	ans.push_back(start);
	for (int x : v1) ans.push_back(x);
	if (mid) ans.push_back(mid);
	for (int x : v2) ans.push_back(x);
}

int main () {
	int n = read;

#ifdef LOCAL
	for (int i = 1; i <= n; i ++)
		read(X[i], Y[i]);
#endif

	for (int i = 3; i <= n; i ++) {
		if (query(2, 1, 2, i) < 0) a.push_back(i);
		else b.push_back(i);
		h[i] = query(1, 1, 2, i);
	}

	solve(1, a);
	solve(2, b);
	printf("0");
	for (int x : ans) printf(" %d", x);
	puts("");
}
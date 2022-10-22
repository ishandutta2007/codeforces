#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 200005;
struct Cate {
	int a, t;
} ca[maxn];

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		ca[i].a = read;
	for(int i = 1; i <= n; i ++)
		ca[i].t = read;

	std::sort(ca + 1, ca + n + 1, [](Cate a, Cate b) {
				return a.a < b.a;
			});

	std::multiset<int> s;
	int l = 1, r = 0;
	ll sum = 0, ans = 0;
	ca[n + 1] = {2000000000, 0};
	for(int i = 1; i <= n + 1; i ++) {
		while(l <= r and l < ca[i].a) {
			auto it = -- s.end();
			sum -= *it;
			ans += sum;
			++ l;
			s.erase(it);
		}
		if(l > r)
			l = r = ca[i].a;
		else
			++ r;
		sum += ca[i].t;
		s.insert(ca[i].t);
	}

	printf("%lld\n", ans);
}
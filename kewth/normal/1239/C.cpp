#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005;

struct P {
	ll ti;
	int id;
} pe[maxn];
bool operator < (P x, P y) {
	if (x.ti == y.ti) return x.id < y.id;
	return x.ti < y.ti;
};
bool operator > (P x, P y) {
	if (x.ti == y.ti) return x.id > y.id;
	return x.ti > y.ti;
};
ll ans[maxn];

int main () {
	int n = read, p = read;
	for (int i = 1; i <= n; i ++) pe[i] = {read, i};
	std::sort(pe + 1, pe + n + 1);

	std::set<int> inque;
	std::set<int> wait;
	std::priority_queue<P, std::vector<P>, std::greater<P> > que;
	ll las = 0;

	for (int i = 1; i <= n; i ++) {
		/* while (!que.empty() and las < pe[i].ti) { */
		/* } */
		while (!que.empty() and que.top().ti < pe[i].ti) {
			P tmp = que.top();
			inque.erase(tmp.id);
			que.pop();
			if (wait.upper_bound(tmp.id) != wait.end()) {
				int j = *wait.upper_bound(tmp.id);
				if (inque.upper_bound(j) == inque.begin()) {
					wait.erase(j);
					ans[j] = las = las + p;
					inque.insert(j);
					que.push({las, j});
				}
			}
		}
		if (inque.upper_bound(pe[i].id) == inque.begin()) {
			/* debug("%d %d\n", pe[i].id, *inque.upper_bound(pe[i].id)); */
			ans[pe[i].id] = las = std::max(pe[i].ti, las) + p;
			inque.insert(pe[i].id);
			que.push({las, pe[i].id});
		}
		else
			wait.insert(pe[i].id);
	}

	for (int i : wait)
		ans[i] = las = las + p;

	for (int i = 1; i <= n; i ++) printf("%lld ", ans[i]);
	puts("");
}
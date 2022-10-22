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
std::set<int> G[maxn];

int main () {
	int n = read, m = read;
	for (int i = 1; i <= m; i ++) {
		int u = read, v = read;
		G[u].insert(v);
		G[v].insert(u);
	}

	std::set<int> set, tmp;
	for (int i = 1; i <= n; i ++)
		set.insert(i);

	int tot = 0;
	while (!set.empty()) {
		++ tot;
		std::queue<int> q;
		int s = *set.begin();
		q.push(s);
		set.erase(s);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			tmp.clear();
			for (int v : set)
				if (!G[u].count(v)) {
					/* debug("%d -> %d\n", u, v); */
					tmp.insert(v);
					q.push(v);
				}
			for (int v : tmp)
				set.erase(v);
		}
	}

	printf("%d\n", tot - 1);
}
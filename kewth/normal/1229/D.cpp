#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
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

const int maxn = 200005, maxi = 128;
int id_to_per[maxi][6];
int mul[maxi][maxi];
int code_to_id[54322];
int per[maxn];

int getcode (int *a) {
	int c = 0;
	for (int i = 1, j = 10000; i <= 5; i ++, j /= 10)
		c += a[i] * j;
	return c;
}

int force_mul (int a, int b) {
	int c = 0;
	for (int i = 1, j = 10000; i <= 5; i ++, j /= 10)
		c += id_to_per[a][id_to_per[b][i]] * j;
	return code_to_id[c];
}

struct group {
	std::vector<int> bas;
	bool ing[maxi];
	int pos, size;
	void build () {
		std::queue<int> q;
		std::fill(ing, ing + maxi, 0);
		q.push(1);
		ing[1] = 1;
		size = 1;
		while (!q.empty()) {
			int P = q.front();
			q.pop();
			for (int Q : bas) {
				int R = mul[P][Q];
				if (!ing[R]) {
					q.push(R);
					ing[R] = 1;
					++ size;
				}
			}
		}
	}
};

bool operator != (group a, group b) {
	for (int i = 1; i <= 120; i ++)
		if (a.ing[i] != b.ing[i])
			return 1;
	return 0;
}

int main () {
	int p[6];
	for (int i = 1; i <= 5; i ++)
		p[i] = i;
	int id = 0;
	do {
		int code = getcode(p);
		code_to_id[code] = ++ id;
		for (int i = 1; i <= 5; i ++)
			id_to_per[id][i] = p[i];
	} while (std::next_permutation(p + 1, p + 6));

	for (int i = 1; i <= id; i ++)
		for (int j = 1; j <= id; j ++)
			mul[i][j] = force_mul(i, j);

	int n = read, m = read;
	for (int i = 1; i <= n; i ++) {
		int a[6];
		for (int j = 1; j <= m; j ++) read(a[j]);
		for (int j = m + 1; j <= 5; j ++) a[j] = j;
		int code = getcode(a);
		per[i] = code_to_id[code];
	}

	ll ans = 0;
	std::vector<group> las, now;
	for (int i = 1; i <= n; i ++) {
		int P = per[i];
		group Pg;
		Pg.bas.push_back(P);
		Pg.build();
		Pg.pos = i;
		las.push_back(Pg);
		now.clear();
		for (group g : las) {
			if (!g.ing[P]) {
				g.bas.push_back(P);
				g.build();
			}
			if (now.empty() or g != now.back())
				now.push_back(g);
		}
		int ls = 0;
		for (group g : now) {
			/* debug("%d -> %d : %d\n", g.pos, i, g.size); */
			ans += (g.size - ls) * (i - g.pos + 1);
			ls = g.size;
		}
		las = now;
	}

	printf("%lld\n", ans);
}
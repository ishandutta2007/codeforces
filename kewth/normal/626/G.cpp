#if 0
2020.02.21

(cf626g)

 x  x 
 x >= l  0 








#endif
#include <cstdio>
#include <algorithm>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef long double ld;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 200005;
int p[maxn], l[maxn], u[maxn];

inline ld calc(int i, int x) {
	x = std::min(x, l[i]);
	if(x == -1) return - 1e100;
	return ld(p[i]) * x / (l[i] + x);
}

struct Pool {
	int i, x;
	ld val;
	Pool (int i, int x): i(i), x(x), val(calc(i, x + 1) - calc(i, x)) { }
	inline Pool dec() { return Pool(i, x - 1); }
	inline Pool inc() { return Pool(i, x + 1); }
};
bool operator < (Pool a, Pool b) {
	return a.val == b.val ? a.i < b.i : a.val < b.val;
}

std::set<Pool> get, wait;
ld ans = 0;
inline void add() {
	Pool P = *(-- wait.end());
	ans += P.val;
	++ u[P.i];
	get.erase(P.dec());
	get.insert(P);
	wait.erase(P);
	wait.insert(P.inc());
}

inline void remove() {
	Pool P = *get.begin();
	ans -= P.val;
	-- u[P.i];
	get.erase(P);
	get.insert(P.dec());
	wait.erase(P.inc());
	wait.insert(P);
}

int main() {
	int n = read, t = read, q = read;
	for(int i = 1; i <= n; i ++)
		p[i] = read;
	for(int i = 1; i <= n; i ++)
		l[i] = read;

	for(int i = 1; i <= n; i ++)
		wait.insert(Pool(i, 0));
	while(t --) add();

	while(q --) {
		int o = read, i = read;

		ans -= calc(i, u[i]);
		get.erase(Pool(i, u[i] - 1));
		wait.erase(Pool(i, u[i]));

		if(o == 1) ++ l[i];
		if(o == 2) -- l[i];

		ans += calc(i, u[i]);
		get.insert(Pool(i, u[i] - 1));
		wait.insert(Pool(i, u[i]));

		while(*get.begin() < *(-- wait.end())) {
			remove();
			add();
		}

		printf("%.7lf\n", double(ans));
	}
}
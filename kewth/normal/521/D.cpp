#if 0
date












#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef long double ld;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int maxn = 100005;
struct modify {
	int o, t, id;
	ll x, y;
};

bool cmp(modify a, modify b) {
	if(a.o == b.o)
		// return a.x * b.y > b.x * a.y;
		return ld(1) * a.x / a.y > ld(1) * b.x / b.y;
	return a.o < b.o;
}

ll a[maxn];
modify mo[maxn];
bool vis[maxn];
int type[maxn];

int main() {
	int n = read, m = read, lim = read;
	for(int i = 1; i <= n; i ++)
		a[i] = read;

	for(int i = 1; i <= m; i ++) {
		type[i] = mo[i].o = read;
		mo[i].t = read;
		mo[i].x = read;
		mo[i].y = 1;
		mo[i].id = i;
	}

	std::sort(mo + 1, mo + m + 1, cmp);

	for(int i = 1; mo[i].o == 1; i ++)
		if(!vis[mo[i].t]) {
			vis[mo[i].t] = 1;
			mo[i].o = 2;
			mo[i].x -= a[mo[i].t];
		} else {
			mo[i].o = 3;
			mo[i].x = 0;
		}

	std::sort(mo + 1, mo + m + 1, cmp);

	for(int i = 1; mo[i].o == 2; i ++) {
		mo[i].o = 3;
		mo[i].x += a[mo[i].t];
		mo[i].y = a[mo[i].t];
		a[mo[i].t] = mo[i].x;
	}

	std::sort(mo + 1, mo + m + 1, cmp);

	while(mo[lim].x < mo[lim].y)
		-- lim;

	for(int i = 1; i <= lim; i ++)
		mo[i].o = type[mo[i].id];
	std::sort(mo + 1, mo + m + 1, cmp);

	printf("%d\n", lim);
	for(int i = 1; i <= lim; i ++)
		printf("%d ", mo[i].id);
	puts("");
}
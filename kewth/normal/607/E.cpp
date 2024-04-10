#pragma GCC optimize(3)
#if 0
2020.02.05

 m  x  x 

 (s, t) 



 x  O(n^2) 
 x  y  y 


 cdq 
 k  x  (m - k) x 


#endif
#include <cstdio>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef long double ld;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 50005;
ld lk[maxn], lb[maxn];

struct Vector {
	ld x, y, at;
	int id;
} vec[maxn << 1];

struct Range {
	int l, r;
	int id;
} ran[maxn];

int getCross(ld p, ld q, ld r, int n) {
	// debug("get cross\n");
	int vp = 0;
	for(int i = 1; i <= n; i ++) {
		ld a = lk[i] * lk[i] + 1;
		ld b = 2 * (lk[i] * (lb[i] - q) - p);
		ld c = p * p + (lb[i] - q) * (lb[i] - q) - r * r;

		ld dt = b * b - 4 * a * c;
		if(dt < 0) continue;

		ld x1 = (-b - sqrt(dt)) / a / 2;
		ld x2 = (-b + sqrt(dt)) / a / 2;
		ld y1 = lk[i] * x1 + lb[i];
		ld y2 = lk[i] * x2 + lb[i];

		vec[++ vp] = {x1 - p, y1 - q, atan2l(y1 - q, x1 - p), i};
		vec[++ vp] = {x2 - p, y2 - q, atan2l(y2 - q, x2 - p), i};
	}

	std::sort(vec + 1, vec + vp + 1, [](Vector a, Vector b) {
				return a.at < b.at;
			});
	// for(int i = 1; i <= vp; i ++)
		// debug("%lf %lf %d\n", vec[i].x, vec[i].y, vec[i].id);
	return vp;
}

int bit[maxn << 1];
int query(int p) {
	int res = 0;
	for(int k = p; k; k -= k & -k)
		res += bit[k];
	return res;
}
void modify(int p, int lim) {
	for(int k = p; k <= lim; k += k & -k)
		++ bit[k];
}

int vis[maxn];
ll check(ld p, ld q, ld r, int n) {
	// debug("check %lf\n", r);
	int vp = getCross(p, q, r, n);
	ll res = 0;
	std::fill(vis + 1, vis + n + 1, 0);
	std::fill(bit + 1, bit + vp + 1, 0);

	for(int i = 1; i <= vp; i ++)
		if(!vis[vec[i].id]) {
			vis[vec[i].id] = i;
			res -= query(i);
		} else {
			res += query(vis[vec[i].id]);
			modify(vis[vec[i].id], vp);
		}

	// debug(" -> %lld\n", res);
	return res;
}

ld crossdis(ld p, ld q, int i, int j) {
	ld x = (lb[i] - lb[j]) / (lk[j] - lk[i]);
	ld y = lk[i] * x + lb[i];
	// debug("cross %lf %lf\n", x, y);
	return sqrt((p - x) * (p - x) + (q - y) * (q - y));
}

Range tmp[maxn];
ld ans = 0;
int tot = 0;
void cdq(ld p, ld q, int l, int r) {
	if(l == r) return;
	int mid = (l + r) >> 1;

	cdq(p, q, l, mid);
	cdq(p, q, mid + 1, r);

	// debug("cdq %d %d\n", l, r);
	// for(int i = l; i <= r; i ++)
		// debug("%d %d\n", ran[i].l, ran[i].r);

	int p1 = l, tp = l;
	for(int p2 = mid + 1; p2 <= r; p2 ++) {
		while(p1 <= mid and ran[p1].r < ran[p2].r)
			tmp[tp ++] = ran[p1 ++];
		tmp[tp ++] = ran[p2];
		for(int i = p1 - 1; i >= l and ran[i].r > ran[p2].l; i --) {
			// debug("%d %d %d %d\n",
					// ran[i].l, ran[i].r, ran[p2].l, ran[p2].r);
			++ tot;
			ans += crossdis(p, q, ran[i].id, ran[p2].id);
		}
	}
	while(p1 <= mid)
		tmp[tp ++] = ran[p1 ++];
	for(int i = l; i <= r; i ++)
		ran[i] = tmp[i];
}

int main() {
	int n = read;
	ld p = read * 1e-3, q = read * 1e-3;
	int m = read;

	for(int i = 1; i <= n; i ++) {
		lk[i] = read * 1e-3;
		lb[i] = read * 1e-3;
	}

	ld l = 0, r = 1e10;
	for(int i = 0; i < 120; i ++) {
		ld mid = (l + r) / 2;
		if(check(p, q, mid, n) >= m)
			r = mid;
		else
			l = mid;
	}

	int vp = getCross(p, q, l, n);
	std::fill(vis + 1, vis + n + 1, 0);

	int rp = 0;
	for(int i = 1; i <= vp; i ++) {
		int id = vec[i].id;
		if(vis[id])
			ran[vis[id]].r = i;
		else
			ran[vis[id] = ++ rp] = {i, 0, id};
	}

	cdq(p, q, 1, rp);
	ans += (m - tot) * r;
	double pans = double(ans);
	printf("%.9lf\n", pans);
}
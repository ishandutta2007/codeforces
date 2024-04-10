#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

const int lg = 19, mxn = 1 << lg;

int val[lg + 1][mxn];
int p0[lg + 1][mxn];
int p1[lg + 1][mxn];

map <pair <ll, ll>, int> las;
pair <ll, ll> vec[mxn];
int beg[mxn];

void init() {
	rep(i, mxn) {
		val[0][i] = las.find(vec[i]) == las.end() ? -1 : las[vec[i]];
		las[vec[i]] = i;
	}
	rep(b, lg) for (int i = 0; i < mxn; i += 1 << (b + 1)) {
		merge(  val[b] + i, val[b] + i + (1 << b),
				val[b] + i + (1 << b), val[b] + i + (1 << (b + 1)),
				val[b + 1] + i);
		int P0 = 0, P1 = 0;
		rep(j, 1 << (b + 1)) {
			while (P0 < (1 << b) && val[b][i + P0] < val[b + 1][i + j]) ++ P0;
			while (P1 < (1 << b) && val[b][i + (1 << b) + P1] < val[b + 1][i + j]) ++ P1;
			p0[b + 1][i + j] = P0;
			p1[b + 1][i + j] = P1;
		}
	}
}

int query(int l, int r, int bnd, int bi, int a, int b) {
	if (l <= a && b <= r) return bnd;
	if (r <= a || b <= l) return 0;
	int m = (a + b) >> 1;
	int bndl = bnd == b - a ? m - a : p0[bi][a + bnd];
	int bndr = bnd == b - a ? b - m : p1[bi][a + bnd];
	return  query(l, r, bndl, bi - 1, a, m) +
			query(l, r, bndr, bi - 1, m, b);
}

int query(int l, int r, int bnd) {
	return query(l, r, lower_bound(val[lg], val[lg] + mxn, bnd) - val[lg], lg, 0, mxn);
}

int main() {
	int n;
	scanf("%d", &n);
	rep(i, n) {
		int k;
		scanf("%d", &k);
		vector <pair <int, int> > pnts;
		rep(j, k) {
			int x, y;
			scanf("%d %d", &x, &y);
			pnts.pb(mp(x, y));
		}
		beg[i + 1] = beg[i] + k;
		rep(j, k) {
			ll dx = (ll)pnts[(j + 1) % k].first - pnts[j].first;
			ll dy = (ll)pnts[(j + 1) % k].second - pnts[j].second;
			ll g = gcd(abs(dx), abs(dy));
			dx /= g; dy /= g;
			vec[beg[i] + j] = mp(dx, dy);
		}
	}
	init();
	int q;
	scanf("%d", &q);
	while (q --) {
		int l, r;
		scanf("%d %d", &l, &r);
		-- l;
		printf("%d\n", query(beg[l], beg[r], beg[l]));
	}
	return 0;
}
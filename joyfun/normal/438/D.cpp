#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
int n, m;
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)

struct ND {
	int Max;
	ll s;
} nd[N<<2];

void pu(int x) {
	nd[x].Max = max(nd[lson(x)].Max, nd[rson(x)].Max);
	nd[x].s = nd[lson(x)].s + nd[rson(x)].s;
}

void build(int L, int R, int x = 1) {
	if (L == R) {
		scanf("%d", &nd[x].Max);
		nd[x].s = nd[x].Max;
		return;
	}
	int mid = (L + R)>>1;
	build(L, mid, lson(x));
	build(mid + 1, R, rson(x));
	pu(x);
}

void gao(int l, int r, int w, int L, int R, int x = 1) {
	if (nd[x].Max < w) return;
	if (L == R) {
		nd[x].Max %= w, nd[x].s %= w;
		return;
	}
	int mid = (L + R)>>1;
	if (l <= mid) gao(l, r, w, L, mid, lson(x));
	if (r > mid) gao(l, r, w, mid + 1, R, rson(x));
	pu(x);
}

void ins(int v, int w, int L, int R, int x = 1) {
	if (L == R) {
		nd[x].Max = nd[x].s = w;
		return;
	}
	int mid = (L + R)>>1;
	if (v <= mid) ins(v, w, L, mid, lson(x));
	else ins(v, w, mid + 1, R, rson(x));
	pu(x);
}

ll get(int l, int r, int L, int R, int x = 1) {
	if (L >= l && R <= r) return nd[x].s;
	ll ans = 0;
	int mid = (L + R)>>1;
	if (l <= mid) ans += get(l, r, L, mid, lson(x));
	if (r > mid) ans += get(l, r, mid + 1, R, rson(x));
	pu(x);
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	build(1, n);
	int tp, l, r, x;
	while (m--) {
		scanf("%d%d%d", &tp, &l, &r);
		if (tp == 1) printf("%lld\n", get(l, r, 1, n));
		else if (tp == 2) {
			scanf("%d", &x);
			gao(l, r, x, 1, n);
		}
		else ins(l, r, 1, n);
	}
	return 0;
}
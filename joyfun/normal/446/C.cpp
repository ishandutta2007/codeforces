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

const int MOD = 1000000009;
const int N = 300005;

void pp(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int n, m, s[N], F[N];

pii add(pii a, pii b) {
	return mp((a.fi + b.fi) % MOD, (a.se + b.se) % MOD);
}

#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)

int cal(int a, int b, int n) {
	return (1ll * a * F[n - 2] + 1ll * b * F[n - 1]) % MOD;
}

struct ND {
	pii lazy;
	int s, len;
	void gao(pii f) {
		lazy = add(lazy, f);
		s = ((1ll * s + cal(f.fi, f.se, len + 2) - cal(f.fi, f.se, 2)) % MOD + MOD) % MOD;
	}
} nd[N<<2];

void pu(int x) {
	nd[x].s = (nd[lson(x)].s + nd[rson(x)].s) % MOD;
}

void pd(int x) {
	nd[lson(x)].gao(nd[x].lazy);
	int len = nd[lson(x)].len;
	nd[rson(x)].gao(mp(cal(nd[x].lazy.fi, nd[x].lazy.se, len + 1), cal(nd[x].lazy.fi, nd[x].lazy.se, len + 2)));
	nd[x].lazy = mp(0, 0);
}

void build(int L, int R, int x = 1) {
	nd[x].len = R - L + 1; nd[x].s = 0;
	nd[x].lazy = mp(0, 0);
	if (L == R) return;
	int mid = (L + R)>>1;
	build(L, mid, lson(x));
	build(mid + 1, R, rson(x));
}

void ins(int l, int r, int L, int R, int x = 1) {
	if (L >= l && R <= r) {
		nd[x].gao(mp(F[L - l + 1], F[L - l + 2]));
		return;
	}
	int mid = (L + R)>>1;
	pd(x);
	if (l <= mid) ins(l, r, L, mid, lson(x));
	if (r > mid) ins(l, r, mid + 1, R, rson(x));
	pu(x);
}

int get(int l, int r, int L, int R, int x = 1) {
	if (L >= l && R <= r) return nd[x].s;
	int mid = (L + R)>>1;
	int ans = 0;
	pd(x);
	if (l <= mid) ans = (ans + get(l, r, L, mid, lson(x))) % MOD;
	if (r > mid) ans = (ans + get(l, r, mid + 1, R, rson(x))) % MOD;
	pu(x);
	return ans;
}



int main() {
	F[1] = 1, F[2] = 1;
	for (int i = 3; i < N; i++) F[i] = (F[i - 1] + F[i - 2]) % MOD;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		s[i] = (s[i - 1] + x) % MOD;
	}
	build(1, n);
	int tp, l, r;
	while (m--) {
		scanf("%d%d%d", &tp, &l, &r);
		if (tp == 1) ins(l, r, 1, n);
		else printf("%d\n", ((get(l, r, 1, n) + s[r] - s[l - 1]) % MOD + MOD) % MOD);
	}
	return 0;
}
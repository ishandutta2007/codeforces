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
int m, v[N];
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
struct Nd {
	int Max, lazy;
	void gao(int f) {
		lazy += f;
		Max += f;
	}
} nd[N * 4];

void pd(int x) {
	if (nd[x].lazy) {
		nd[lson(x)].gao(nd[x].lazy);
		nd[rson(x)].gao(nd[x].lazy);
		nd[x].lazy = 0;
	}
}

void pu(int x) {
	nd[x].Max = max(nd[lson(x)].Max, nd[rson(x)].Max);
}

void add(int l, int r, int w, int L = 1, int R = m, int x = 1) {
	if (l <= L && R <= r) {
		nd[x].gao(w);
		return;
	}
	int mid = (L + R)>>1;
	pd(x);
	if (l <= mid) add(l, r, w, L, mid, lson(x));
	if (r > mid) add(l, r, w, mid + 1, R, rson(x));
	pu(x);
}

int go(int L = 1, int R = m, int x = 1) {
	if (L == R) return L;
	int mid = (L + R)>>1;
	pd(x);
	int ans;
	if (nd[rson(x)].Max > 0) ans = go(mid + 1, R, rson(x));
	else ans = go(L, mid, lson(x));
	pu(x);
	return ans;
}

int main() {
	scanf("%d", &m);
	int p, t, x;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &p, &t);
		if (t == 0) add(1, p, -1);
		else {
			scanf("%d", &v[p]);
			add(1, p, 1);
		}
		if (nd[1].Max <= 0) printf("-1\n");
		else printf("%d\n", v[go()]);
	}
	return 0;
}
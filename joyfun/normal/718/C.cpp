#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

void pp(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

struct Mat {
	int v[2][2];
	Mat() {memset(v, 0, sizeof(v));}
	Mat operator * (const Mat& c) const {
		Mat ans;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					pp(ans.v[i][j], 1LL * v[i][k] * c.v[k][j] % MOD);
				}
			}
		}
		return ans;
	}
	Mat operator + (const Mat& c) const {
		Mat ans;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				pp(ans.v[i][j], v[i][j]);
				pp(ans.v[i][j], c.v[i][j]);
			}
		return ans;
	}

};

Mat pow_mod(Mat x, int k) {
	Mat ans; for (int i = 0; i < 2; i++) ans.v[i][i] = 1;
	while (k) {
		if (k&1) ans = ans * x;
		x = x * x;
		k >>= 1;
	}
	return ans;
}

#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)

Mat A;

struct Node {
	Mat sum, lazy;
	int l, r;
	void gao(Mat f) {
		lazy = lazy * f;
		sum = sum * f;
	}
} node[N * 4];

void pushdown(int x) {
	node[lson(x)].gao(node[x].lazy);
	node[rson(x)].gao(node[x].lazy);
	node[x].lazy = Mat();
	for (int i = 0; i < 2; i++) node[x].lazy.v[i][i] = 1;
}

void pushup(int x) {
	node[x].sum = (node[lson(x)].sum + node[rson(x)].sum);
}

int n, m;

void build(int l = 1, int r = n, int x = 1) {
	node[x].l = l; node[x].r = r;
	int mid = (l + r)>>1;
	node[x].lazy = Mat();
	for (int i = 0; i < 2; i++) node[x].lazy.v[i][i] = 1;
	if (l == r) {
		int xx;
		scanf("%d", &xx);
		node[x].sum = pow_mod(A, xx);
		return;
	}
	build(l, mid, lson(x));
	build(mid + 1, r, rson(x));
	pushup(x);
}

void add(int l, int r, Mat w, int x = 1) {
	if (node[x].l >= l && node[x].r <= r) {
		node[x].gao(w);
		return;
	}
	int mid = (node[x].l + node[x].r)>>1;
	pushdown(x);
	if (l <= mid) add(l, r, w, lson(x));
	if (r > mid) add(l, r, w, rson(x));
	pushup(x);
}

Mat query(int l, int r, int x = 1) {
	if (node[x].l >= l && node[x].r <= r)
		return node[x].sum;
	int mid = (node[x].l + node[x].r)>>1;
	pushdown(x);
	Mat ans;
	if (l <= mid) ans = ans + query(l, r, lson(x));
	if (r > mid) ans = ans + query(l, r, rson(x));
	pushup(x);
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	A.v[0][0] = A.v[0][1] = A.v[1][0] = 1;
	build(1, n);
	int tp, l, r, x;
	while (m--) {
		scanf("%d%d%d", &tp, &l, &r);
		if (tp == 1) {
			scanf("%d", &x);
			add(l, r, pow_mod(A, x));
		} else {
			Mat ans = query(l, r);
			printf("%d\n", ans.v[0][1]);
		}
	}
	return 0;
}
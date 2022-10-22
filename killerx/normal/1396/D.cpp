#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 11;
const int mod = 1e9 + 7;

int n, k, l;
int x[mxn], y[mxn], c[mxn];
int yid[mxn], xid[mxn], xre[mxn];
int lst[mxn], p[mxn], py[mxn], pre[mxn], nex[mxn];

bool compx(int a, int b) { return x[a] < x[b]; }
bool compy(int a, int b) { return y[a] < y[b]; }

struct SEG {
	int val[mxn << 1], sum[mxn << 1], coef[mxn << 1], tag[mxn << 1];

	void push(int x, int v) {
		tag[x] = val[x] = v;
		sum[x] = 1LL * v * coef[x] % mod;
	}

	void pushdown(int x) {
		if (tag[x] != -1) {
			push(x << 1, tag[x]);
			push(x << 1 | 1, tag[x]);
			tag[x] = -1;
		}
	}

	void pushup(int x) {
		val[x] = val[x << 1 | 1];
		sum[x] = (sum[x << 1] + sum[x << 1 | 1]) % mod;
	}

	void build(int *p, int *c, int n, int i = 1, int a = 0, int b = mxn) {
		tag[i] = -1;
		if (a + 1 == b) {
			if (a < n) { val[i] = p[a]; coef[i] = c[a]; }
			else { val[i] = 1e9; coef[i] = 0; }
			sum[i] = 1LL * val[i] * coef[i] % mod;
			return ;
		}
		int m = (a + b) >> 1;
		build(p, c, n, i << 1, a, m);
		build(p, c, n, i << 1 | 1, m, b);
		pushup(i);
		coef[i] = coef[i << 1] + coef[i << 1 | 1];
	}

	void upd(int l, int r, int v, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) return push(i, v);
		pushdown(i);
		int m = (a + b) >> 1;
		if (l < m) upd(l, r, v, i << 1, a, m);
		if (r > m) upd(l, r, v, i << 1 | 1, m, b);
		pushup(i);
	}

	int find(int v, int i = 1, int a = 0, int b = mxn) {
		if (val[i] < v) return b;
		if (a + 1 == b) return a;
		pushdown(i);
		int m = (a + b) >> 1;
		if (val[i << 1] >= v) return find(v, i << 1, a, m);
		else return find(v, i << 1 | 1, m, b);
	}

	int get(int x, int i = 1, int a = 0, int b = mxn) {
		if (a + 1 == b) return val[i];
		pushdown(i);
		int m = (a + b) >> 1;
		if (x < m) return get(x, i << 1, a, m);
		else return get(x, i << 1 | 1, m, b);
	}
} seg;

int main() {
	scanf("%d %d %d", &n, &k, &l);
	rep(i, n) scanf("%d %d %d", &x[i], &y[i], &c[i]), yid[i] = i, -- c[i];
	sort(yid, yid + n, compy);
	int ans = 0;
	rep(L, n) {
		int vL = y[yid[L]] - (L ? y[yid[L - 1]] : -1);
		for (int i = L; i < n; ++ i) xid[i - L] = yid[i];
		sort(xid, xid + n - L, compx);
		rep(i, n - L) xre[xid[i]] = i;
		set <int> lsts;
		memset(lst, -1, sizeof(lst));
		rep(i, n - L) {
			lsts.erase(lst[c[xid[i]]]);
			pre[i] = lst[c[xid[i]]]; nex[i] = n - L;
			if (lst[c[xid[i]]] != -1) nex[lst[c[xid[i]]]] = i;
			lsts.insert(lst[c[xid[i]]] = i);
			p[i] = lsts.size() == k ? x[xid[*lsts.begin()]] + 1 : 0;
			py[i] = (i + 1 == n - L ? l : x[xid[i + 1]]) - x[xid[i]];
		}
		seg.build(p, py, n - L);
		for (int R = n - 1; R >= L; -- R) {
			int vR = (R + 1 == n ? l : y[yid[R + 1]]) - y[yid[R]];
			(ans += 1LL * vL * vR % mod * seg.sum[1] % mod) %= mod;
			int nw = xre[yid[R]], pr = pre[nw], ne = nex[nw];
			int lb = max(nw, seg.find(pr != -1 ? x[xid[pr]] + 1 : 0));
			if (lb < ne) seg.upd(lb, ne, pr != -1 ? x[xid[pr]] + 1 : 0);
			pre[ne] = pr; nex[pr] = ne;
		}
	}
	printf("%d\n", ans);
	return 0;
}
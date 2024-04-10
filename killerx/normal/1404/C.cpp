#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 3e5 + 5;
int n, q, a[mxn], ql[mxn], qr[mxn], hd[mxn], nex[mxn], qid[mxn], tot, ans[mxn];

void add_qry(int x, int y) {
	nex[++ tot] = hd[x];
	hd[x] = tot;
	qid[tot] = y;
}

const int sz = 1 << 19;
int mx[sz << 1], tag[sz << 1];

void push(int x, int v) {
	mx[x] += v;
	tag[x] += v;
}

void pushup(int x) {
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]) + tag[x];
}

void upd(int l, int r, int v, int i = 1, int a = 0, int b = sz) {
	if (r <= a || b <= l) return ;
	if (l <= a && b <= r) return push(i, v);
	int m = (a + b) >> 1;
	upd(l, r, v, i << 1, a, m);
	upd(l, r, v, i << 1 | 1, m, b);
	pushup(i);
}

int get(int x, int i = 1, int a = 0, int b = sz) {
	if (a + 1 == b) return mx[i];
	int m = (a + b) >> 1;
	if (x < m) return get(x, i << 1, a, m) + tag[i];
	else return get(x, i << 1 | 1, m, b) + tag[i];
}

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d", &a[i]), -- a[i];
	rep(i, q) {
		scanf("%d %d", &ql[i], &qr[i]);
		qr[i] = n - qr[i] - 1;
		add_qry(qr[i], i);
	}
	rep(i, n) {
		if (i - a[i] >= 0) {
			int lb = 0, rb = i + 1;
			while (lb < rb) {
				int md = (lb + rb + 1) >> 1;
				if (get(md - 1) >= i - a[i]) lb = md;
				else rb = md - 1;
			}
			upd(0, lb, 1);
		}
		for (int e = hd[i]; e; e = nex[e]) {
			int qi = qid[e];
			ans[qi] = get(ql[qi]);
		}
	}
	rep(i, q) printf("%d\n", ans[i]);
	return 0;
}
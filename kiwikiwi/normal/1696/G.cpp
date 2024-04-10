#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using db = double;
const int N = 201000;

int n, q;
int a[N];

i64 x, y, v[10];
db dv[10], ans[3][3], tans[3][3];
bool valid[3][3];

struct node {
	db val[3][3];
	db mid;
} seg[N * 4];

void update(int id) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			seg[id].val[i][j] = -1e18;
			for (int k = 0; k < 3; k++)
				seg[id].val[i][j] = max(seg[id].val[i][j],
					seg[id * 2].val[i][k] + seg[id * 2 + 1].val[k][j]
					- dv[k] * seg[id].mid);
		}
}

void build(int id, int l, int r) {
	if (l == r) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				seg[id].val[i][j] = valid[i][j]
					? dv[i] * a[l] + dv[j] * a[l + 1] 
					: -1e18;
			}
		}
	} else {
		int mid = (l + r) / 2;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		seg[id].mid = a[mid + 1];
		update(id);
	}
}

void change(int id, int l, int r, int ql, int qr) {
	if (l == r) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				seg[id].val[i][j] = valid[i][j]
					? dv[i] * a[l] + dv[j] * a[l + 1] 
					: -1e18;
			}
		}
	} else {
		int mid = (l + r) / 2;
		if (qr <= mid) change(id * 2, l, mid, ql, qr);
		else if (ql > mid) change(id * 2 + 1, mid + 1, r, ql, qr);
		else change(id * 2, l, mid, ql, mid),
			change(id * 2 + 1, mid + 1, r, mid + 1, qr);
		seg[id].mid = a[mid + 1];
		update(id);
	}
} 

db pmid;
void query(int id, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				tans[i][j] = -1e18;
				for (int k = 0; k < 3; k++)
					tans[i][j] = max(tans[i][j], ans[i][k] + 
						seg[id].val[k][j] - dv[k] * pmid);
			}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				ans[i][j] = tans[i][j];
		pmid = a[r + 1];
		return;
	}
	int mid = (l + r) / 2;
	// [l, mid] , [mid + 1, r]
	if (qr <= mid) return query(id * 2, l, mid, ql, qr);
	else if (ql > mid) return query(id * 2 + 1, mid + 1, r, ql,qr);
	else {
		// qr > mid, ql <= mid
		// [ql, mid], [mid + 1, qr]
		return query(id * 2, l, mid, ql, mid),
			query(id * 2 + 1, mid + 1, r, mid + 1, qr);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	scanf("%lld%lld", &x, &y);
	if (y < x) swap(x, y);
	v[0] = 0; v[1] = y; v[2] = x + y;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			valid[i][j] = (x * v[i] + y * v[j] <= y * (x + y)) &&
				(y * v[i] + x * v[j] <= y * (x + y));
		}
	dv[0] = 0; dv[1] = 1. / (x + y); dv[2] = 1./ y;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n - 1);
	for (int i = 0; i < q; i++) {
		int ty;
		scanf("%d", &ty);
		if (ty == 1) {
			int x, d;
			scanf("%d%d", &x, &d);
			a[x] = d;
			change(1, 1, n - 1, max(x - 1, 1), min(x, n - 1));
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					ans[i][j] = (i == j) ? 0 : -1e18;
			pmid = 0;
			query(1, 1, n - 1, l, r - 1);
			db mx = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					mx = max(mx, ans[i][j]);
			printf("%.10f\n", mx);
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

struct QRY {
	int l, r, id;
	QRY() {};
	QRY(int a, int b, int c): l(a), r(b), id(c) {};
};

const int R = 625, maxn = 2e5 + 10, maxq = 2e5 + 10, maxv = 1e6 + 10;
int n, q, a[maxn], pl, pr, k[maxv];
long long qans[maxq], ans = 0;
QRY qry[maxq];

bool cmp(QRY a, QRY b) {
	if (a.l/R != b.l/R) return a.l < b.l;
	return a.r < b.r;
}

void add(int idx) {
	int b = a[idx];
	ans -= (long long)k[b]*k[b]*b;
	++k[b];
	ans += (long long)k[b]*k[b]*b;
}

void del(int idx) {
	int b = a[idx];
	ans -= (long long)k[b]*k[b]*b;
	--k[b];
	ans += (long long)k[b]*k[b]*b;
}

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < q; ++i) {
		int l, r;
//		cin >> l >> r;
		scanf("%d %d", &l, &r);
		--l;
		qry[i] = QRY (l, r, i);
	}
	sort(qry, qry + q, cmp);
	for (int i = qry[0].l; i < qry[0].r; ++i) ++k[a[i]];
	for (int i = 0; i < maxv; ++i) ans += (long long)k[i]*k[i]*i;
	qans[qry[0].id] = ans;
	pl = qry[0].l, pr = qry[0].r;
	for (int i = 1; i < q; ++i) {
		while (pl > qry[i].l) add(--pl);
		while (pr < qry[i].r) add(pr++);
		while (pl < qry[i].l) del(pl++);
		while (pr > qry[i].r) del(--pr);
		qans[qry[i].id] = ans;
	}
	for (int i = 0; i < q; ++i) {
//		cout << qans[i] << '\n';
		printf("%I64d\n", qans[i]);
	}
	return 0;
}
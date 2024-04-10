#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 4234567
#define M 1000000

int tag[maxN], ans[maxN];
int n, m, q, a[maxN], b[maxN];

void modify(int p1, int p2, int p3, int p4, int p5, int p6) {
	if (p5 < p2 || p4 > p3) return;
	if (p2 >= p4 && p3 <= p5) {
		tag[p1] += p6;
		ans[p1] += p6;
		return;
	}
	int m = (p2 + p3) / 2;
	modify(p1 * 2, p2, m, p4, p5, p6);
	modify(p1 * 2 + 1, m + 1, p3, p4, p5, p6);
	ans[p1] = max(ans[p1 * 2], ans[p1 * 2 + 1]) + tag[p1];
}
int query(int p1, int p2, int p3, int offset) {
	if (ans[p1] + offset <= 0) return -1;
	if (p2 == p3) return p2;
	int m = (p2 + p3) / 2;
	offset += tag[p1];
	if (ans[p1 * 2 + 1] + offset > 0)
		return query(p1 * 2 + 1, m + 1, p3, offset);
	return query(p1 * 2, p2, m, offset);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		modify(1, 1, M, 1, a[i], 1);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		modify(1, 1, M, 1, b[i], -1);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int u, v, w, x, c;
		scanf("%d%d%d", &u, &v, &w);
		if (u == 1) x = a[v], a[v] = w, c = 1;
		if (u == 2) x = b[v], b[v] = w, c = -1;
		modify(1, 1, M, 1, x, -c);
		modify(1, 1, M, 1, w, c);
		printf("%d\n", query(1, 1, M, 0));
	}
}
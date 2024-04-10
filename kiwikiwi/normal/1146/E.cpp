#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 1234567

const int M = 100002;
int v[maxN];
int n, m, a[maxN];
int mask[4][4] = {
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{1, 0, 3, 2},
	{0, 1, 2, 3}
};

void build(int p1, int p2, int p3) {
	v[p1] = 3;
	if (p2 == p3) return;
	int p4 = (p2 + p3) / 2;
	build(p1 << 1, p2, p4);
	build(p1 << 1 | 1, p4 + 1, p3);
}

void apply(int p1, int p2) {
	v[p1] = mask[p2][v[p1]];
}

void push(int p1) {
	apply(p1 << 1, v[p1]);
	apply(p1 << 1 | 1, v[p1]);
	v[p1] = 3;
}

void apply(int p1, int p2, int p3, int p4, int p5, int p6) {
	if (p5 < p2 || p4 > p3) return;
	if (p4 <= p2 && p3 <= p5) {
		apply(p1, p6);
		return;
	}
	push(p1);
	int p8 = (p2 + p3) / 2;
	apply(p1 << 1, p2, p8, p4, p5, p6);
	apply(p1 << 1 | 1, p8 + 1, p3, p4, p5, p6);
}

int query(int p1, int p2, int p3, int p4) {
	if (p2 == p3) {
		return v[p1];
	}
	push(p1);
	int p5 = (p2 + p3) / 2;
	if (p4 <= p5)
		return query(p1 << 1, p2, p5, p4);
	else
		return query(p1 << 1 | 1, p5 + 1, p3, p4);
}

int main() {
	scanf("%d%d", &n, &m);
	build(1, 0, 2 * M);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	char s[10];
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%s%d", s, &x);
		if (s[0] == '<') {
			--x;
			if (x < 0) {
				// 0 -> 1
				apply(1, 0, 2 * M, 0, x + M, 1);
				apply(1, 0, 2 * M, -x + M, 2 * M, 0);
			} else {
				apply(1, 0, 2 * M, 0, -x - 1 + M, 1);
				apply(1, 0, 2 * M, -x + M, x + M, 2);
				apply(1, 0, 2 * M, x + 1 + M, 2 * M, 0);
			}
		} else {
			++x;
			if (x > 0) {
				apply(1, 0, 2 * M, 0, -x + M, 0);
				apply(1, 0, 2 * M, x + M, 2 * M, 1);
			} else {
				apply(1, 0, 2 * M, 0, x - 1 + M, 0);
				apply(1, 0, 2 * M, x + M, -x + M, 2);
				apply(1, 0, 2 * M, -x + 1 + M, 2 * M, 1);

			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int c = query(1, 0, 2 * M, a[i] + M);
		if (c == 1 || c == 2) a[i] *= -1;
		printf("%d ", a[i]);
	}
	printf("\n");
}
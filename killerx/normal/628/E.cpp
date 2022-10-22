#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[3005][3005];
int sum[3005][3005];
int sumdiag[6005][3005];

int getsum(int X0, int Y0, int X1, int Y1) {
	return sum[X1][Y1] - (X0 ? sum[X0 - 1][Y1] : 0) - (Y0 ? sum[X1][Y0 - 1] : 0) + (X0 && Y0 ? sum[X0 - 1][Y0 - 1] : 0);
}

int getsumdiag(int X, int Y, int N) {
	int diagnum = X + Y;
	int L = X;
	int R = X + N;
	return sumdiag[diagnum][R] - (L ? sumdiag[diagnum][L - 1] : 0);
}

int find_left(int x, int y) {
	int lb = 0, rb = y;
	while (lb < rb) {
		int md = (lb + rb + 1) >> 1;
		if (getsum(x, y - md, x, y) == md + 1) lb = md;
		else rb = md - 1;
	}
	return lb;
}

int find_diag(int x, int y) {
	int lb = 0, rb = n - x - 1;
	while (lb < rb) {
		int md = (lb + rb + 1) >> 1;
		if (getsumdiag(x, y, md) == md + 1) lb = md;
		else rb = md - 1;
	}
	return lb;
}

int find_right(int x, int y) {
	int lb = 0, rb = m - y - 1;
	while (lb < rb) {
		int md = (lb + rb + 1) >> 1;
		if (getsum(x, y, x, y + md) == md + 1) lb = md;
		else rb = md - 1;
	}
	return lb;
}

struct T {
	int sum, vis;
	T *lson, *rson;
};

T *que[400000];
int Lb, Rb;

T *newT(int v, T *l, T *r) {
	T *x = que[Lb ++];
	if (Lb == 400000) Lb = 0;
	x -> sum = v, x -> lson = l, x -> rson = r;
	x -> vis = 0;
	return x;
}

void deleteT(T *x) {
	que[Rb ++] = x;
	if (Rb == 400000) Rb = 0;
}

T *clone(T *x) {
	return newT(x -> sum, x -> lson, x -> rson);
}

T *upd(T *i, int l, int r, int x, int v) {
	if (i == NULL) i = newT(0, NULL, NULL);
	else i = clone(i);
	if (l + 1 == r) {
		i -> sum += v;
		return i;
	}
	int m = (l + r) >> 1;
	if (x < m) i -> lson = upd(i -> lson, l, m, x, v);
	else i -> rson = upd(i -> rson, m, r, x, v);
	i -> sum = (i -> lson ? i -> lson -> sum : 0) + (i -> rson ? i -> rson -> sum : 0);
	return i;
}

int qry(T *i, int l, int r, int a, int b) {
	if (i == NULL) return 0;
	if (a <= l && r <= b) return i -> sum;
	if (b <= l || r <= a) return 0;
	int m = (l + r) >> 1;
	return qry(i -> lson, l, m, a, b) + qry(i -> rson, m, r, a, b);
}

vector <T*> segt;
vector <T*> vert;

void dfs(T *x) {
	if (!x || x -> vis) return;
	x -> vis = 1;
	vert.push_back(x);
	dfs(x -> lson);
	dfs(x -> rson);
}

void segt_free() {
	vert.clear();
	for (int i = 0; i < segt.size(); ++ i) dfs(segt[i]);
	segt.clear();
	for (int i = 0; i < vert.size(); ++ i) deleteT(vert[i]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i) scanf("%s", s[i]);
	// n = 3000, m = 3000;
	// for (int i = 0; i < n; ++ i) for (int j = 0; j < m; ++ j) s[i][j] = rand() & 1 ? 'z' : '.';
	for (int i = 0; i < 400000; ++ i) que[Rb ++] = new T(); Rb = 0;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			sum[i][j] = (i ? sum[i - 1][j] : 0) + (j ? sum[i][j - 1] : 0) - (i && j ? sum[i - 1][j - 1] : 0) + (s[i][j] == 'z');
			sumdiag[i + j][i] = (s[i][j] == 'z');
		}
	}
	for (int i = 0; i < n + m; ++ i) {
		for (int j = 0; j < n; ++ j) {
			sumdiag[i][j] += (j ? sumdiag[i][j - 1] : 0);
		}
	}
	long long ans = 0;
	for (int ij = 0; ij < n + m; ++ ij) {
		for (int i = 0; i < n; ++ i) {
			int j = ij - i; if (j < 0 || j >= m) continue;
			segt.push_back(upd(segt.empty() ? NULL : segt.back(), 0, m, j + find_right(i, j), 1));
		}
		for (int i = 0; i < n; ++ i) {
			int j = ij - i; if (j < 0 || j >= m) continue;
			if (s[i][j] == 'z') {
				int x = find_left(i, j);
				int y = find_diag(i, j);
				int l = min(x, y);
				int cur = qry(segt[i + l - max(0, i + j - m + 1)], 0, m, j, m);
				cur -= qry(i - max(0, i + j - m + 1) == 0 ? NULL : segt[i - max(0, i + j - m + 1) - 1], 0, m, j, m);
				ans += cur;
			}
		}
		segt_free();
	}
	printf("%lld\n", ans);
	return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	static short st[30], tp; 
	if (x < 0) putchar('-'), x = -x;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int N = 505, Q = 600006;
struct node {
	int x, y, id;
	node(){}
	node(int a, int b, int c) { x = a, y = b, id = c; }
};

int a[N][N], ans[Q], m, n, q;
vector<node> vec[N][N];
bitset<N> bt[N][N], rbt[N][N];
void solve(int l, int r) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	for (int t = m;t >= 1; --t) if (!a[mid][t]) {
		bt[mid][t].reset(), bt[mid][t].set(t);
		if (!a[mid][t + 1]) bt[mid][t] |= bt[mid][t + 1];
	}
	for (int i = mid - 1;i >= l; --i) {
		for (int t = m;t >= 1; --t) if (!a[i][t]) {
			bt[i][t].reset();
			if (!a[i][t + 1]) bt[i][t] |= bt[i][t + 1];
			if (!a[i + 1][t]) bt[i][t] |= bt[i + 1][t];
		}
	}
	for (int t = 1;t <= m; ++t) if (!a[mid][t]) {
		rbt[mid][t].reset(), rbt[mid][t].set(t);
		if (!a[mid][t - 1]) rbt[mid][t] |= rbt[mid][t - 1];
	}
	for (int i = mid + 1;i <= r; ++i) {
		for (int t = 1;t <= m; ++t) if (!a[i][t]) {
			rbt[i][t].reset();
			if (!a[i][t - 1]) rbt[i][t] |= rbt[i][t - 1];
			if (!a[i - 1][t]) rbt[i][t] |= rbt[i - 1][t];
		}
	}
	for (int i = l;i <= mid; ++i)
		for (int j = 1;j <= m; ++j) if (vec[i][j].size()) {
			for (int t = 0;t < (int)vec[i][j].size(); ++t) {
				node tmp = vec[i][j][t];
				if (tmp.x >= mid) {
					ans[tmp.id] = (bt[i][j] & rbt[tmp.x][tmp.y]).any();
					swap(vec[i][j][t], vec[i][j][(int)vec[i][j].size() - 1]), vec[i][j].pop_back(), --t;
				}
			}
		}
	solve(l, mid - 1), solve(mid + 1, r);
}

char s[N];
int main() {
	read(n), read(m);
	for (int i = 1;i <= n; ++i) {
		scanf ("%s", s + 1);
		for (int j = 1;j <= m; ++j) 
			a[i][j] = s[j] == '#';
	}
	for (int i = 1;i <= m; ++i) a[n + 1][i] = a[0][i] = 1;
	for (int i = 1;i <= n; ++i) a[i][m + 1] = a[i][0] = 1;
	read(q);
	for (int i = 1;i <= q; ++i) {
		int a, b, c, d;
		read(a), read(b), read(c), read(d);
		vec[a][b].emplace_back(c, d, i);
	}
	solve(1, n);
	for (int i = 1;i <= q; ++i) puts(ans[i] ? "Yes" : "No");
	return 0;
}
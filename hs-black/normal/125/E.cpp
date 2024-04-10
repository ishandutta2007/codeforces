#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N = 50500;
const int M = 105000;

int read(void) {
	int x = 0; bool f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return f ? -x : x;
}

struct node {
	int x, y, z, num;
	bool operator < (const node &i) const {
		if (z != i.z) return z < i.z;
		return x < i.x;
	}
}ed[M];

int n, m, k;
int val[M], x[M], y[M];

int f[N], cnt;
long long ans;

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

void kruskal(void) {
	ans = cnt = 0;
	sort(ed + 1, ed + m + 1);
	for (int i = 1;i <= n; i++) f[i] = i;
	for (int i = 1;i <= m; i++) {
		if (find(ed[i].x) == find(ed[i].y)) continue;
		int x = ed[i].x, y = ed[i].y;
		f[f[x]] = f[y], ans += ed[i].z;
		if (x == 1 || y == 1) cnt++;
	}
}

ll res;

void ext(void) {
	for (int i = 1;i <= m; i++) {
		ed[i] = (node) {x[i], y[i], val[i], i};
		if (x[i] == 1) ed[i].z = val[i] + res;
	}
	for (int i = 1;i <= n; i++) f[i] = i;
	sort(ed + 1, ed + m + 1);
	ans = 0, cnt = 0;
	for (int i = 1;i <= m; i++) {
		int x = ed[i].x, y = ed[i].y;
		if (find(x) == find(y)) continue;
		if (x == 1) {
			if (cnt == k) continue;
			cnt++;
		}
		f[f[x]] = y;
		printf ("%d ", ed[i].num);
	}
}

int main() {
	int ppp = 0;
	n = read(), m = read(), k = read();
	for (int i = 1;i <= m; i++) {
		x[i] = read(), y[i] = read();
		if (x[i] > y[i]) swap(x[i], y[i]);
		if (x[i] == 1) ppp++;
		ed[i].x = x[i], ed[i].y = y[i];
		val[i] = ed[i].z = read();
		ed[i].num = i;
	}
	if (ppp < k || (k == 0 && n != 1)) {
		cout << -1 << endl;
		return 0;
	}
	int l = -100000, r = -l;
	while (l <= r) {
		int mid = (l + r) >> 1;
		for (int i = 1;i <= m; i++) {
			ed[i] = (node) {x[i], y[i], val[i], i};
			if (x[i] == 1) ed[i].z = val[i] + mid;
		}
		kruskal();
		if (cnt >= k) l = mid + 1, res = mid;
		else r = mid - 1;
	}
	printf ("%d\n", n-1);
	ext();
	return 0;
}
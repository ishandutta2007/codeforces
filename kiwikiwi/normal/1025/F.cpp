#include <bits/stdc++.h>
using namespace std;

struct angle {
	long long x, y;
	int quad() const {
		return (y < 0 || (y == 0 && x < 0));
	}
};

const int N = 2010;
int n, cnt[N], ord[N], rk[N];
long long x[N], y[N];
int p[N][N];

angle ag[N];

struct event {
	angle a;
	int u, v;
	event() { }
	event(int s, int t) {
		u = s; v = p[s][t];
		a = (angle) {x[v] - x[u], y[v] - y[u]};
	}
};
bool operator < (const angle &a, const angle &b) {
	if (a.quad() != b.quad()) return a.quad() < b.quad();
	else return a.x * b.y - a.y * b.x > 0;
}
bool operator < (const event &a, const event &b) {
	return a.a < b.a;
}
event q[2121212];
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", x + i, y + i);
	}
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) if (j != i) {
				ag[j] = (angle) {x[j] - x[i], y[j] - y[i]};
				p[i][t] = j;
				t++;
			}
		sort(p[i], p[i] + t, [&](int a, int b) {
			return ag[a] < ag[b];
		});
	}
	for (int i = 0; i < n; i++) ord[i] = i;
	sort(ord, ord + n, [&](int a, int b) {
		return y[a] < y[b] || (y[a] == y[b] && x[a] < x[b]);
	});
	int t = 0;
	for (int i = 0; i < n; i++) rk[ord[i]] = i;
	for (int i = 0; i < n; i++) for (int j = 0; j < n - 1; j++)
			if (rk[i] < rk[p[i][j]]) q[t++] = event(i, j);
	sort(q, q + t);
	for (int i = 0; i < t; i++) {
		int u = q[i].u, v = q[i].v;
		swap(ord[rk[u]], ord[rk[v]]);
		ans += (long long)rk[u] * (rk[u] - 1) / 2 * (n - rk[v] - 1) * (n - rk[v] - 2) / 2;
		swap(rk[u], rk[v]);
	}
	printf("%lld\n", ans);
}
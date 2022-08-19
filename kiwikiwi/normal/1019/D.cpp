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
long long S, x[N], y[N];
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
	return b.a < a.a;
}
priority_queue<event> q;



int main() {
	scanf("%d%lld", &n, &S);
	S *= 2;
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
	for (int i = 0; i < n; i++) rk[ord[i]] = i;
	for (int i = 0; i < n; i++) q.push(event(i, 0)), cnt[i] = 1;
	while (!q.empty()) {
		int u = q.top().u, v = q.top().v;
		q.pop();
		//printf("%d %d %d %d\n",u,v,rk[u],rk[v]);
		//assert(rk[u] + 1 == rk[v]);
		swap(ord[rk[u]], ord[rk[v]]);
		swap(rk[u], rk[v]);
		if (cnt[u] != n - 1) q.push(event(u, cnt[u]++));
		int l = rk[u] + 1, r = n;
		auto eval = [&](int mid) {
			return (x[v] - x[u]) * (y[ord[mid]] - y[u]) - (x[ord[mid]] - x[u]) * (y[v] - y[u]);
		};
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			long long S2 = eval(mid);
			if (S2 > S) r = mid; else l = mid;
		}
		if (eval(l) == S) {
			puts("Yes");
			printf("%lld %lld\n%lld %lld\n%lld %lld\n", x[u], y[u], x[v], y[v], x[ord[l]], y[ord[l]]);
			return 0;
		}
	}
	puts("No");
}
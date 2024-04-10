#include <cstdio>
#include <vector>

using namespace std;

vector<int> g[1000001];
int a[1000001], c[1000001], s;
int r1, r2;

void f(int x) {
	for (auto t : g[x]) {
		f(t);
		a[x] += a[t];
		if (c[t]) {
			if (a[t] * 3 == s * 2 && c[t]) {
				r1 = t;
				r2 = c[t];
			}
			if (c[x]) {
				r1 = c[x];
				r2 = c[t];
			}
		}
		if (a[t] * 3 == s && c[x]) {
			r1 = c[x];
			r2 = t;
		}
		if (!c[x] && c[t]) c[x] = c[t];
		if (!c[x] && a[t] * 3 == s) c[x] = t;
	}
}

int main() {
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &j, &a[i]);
		g[j].push_back(i);
		s += a[i];
	}
	f(g[0][0]);
	if (r1) printf("%d %d\n", r1, r2);
	else puts("-1");
	return 0;
}
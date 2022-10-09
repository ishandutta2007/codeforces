#include <bits/stdc++.h>
using namespace std;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int a[200005];
int n;

struct edge {
	int x, y;
};

vector<edge> e[200005];
bool v[200005];

long long c[200005];

vector<int> ee[200005];

int q[200005], qs, qe;

int bfs(int x) {
	v[x] = 1;
	qs = 0;
	qe = 1;
	q[0] = x;
	while (qs < qe) {
		x = q[qs++];
		for (int y : ee[x])
			if (!v[y]) {
				v[y] = 1;
				q[qe++] = y;
			}
	}
	return qe;
}

int verts[200005], vv;

vector<int> jbg[200005];

int main() {

	// ipak sam ja

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", a+i);
		jbg[a[i]].push_back(i);
	}

	for (int i=1; i<n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[gcd(a[x], a[y])].push_back({x, y});
	}

	for (int t=1; t<=200000; t++) {
		for (int j=t; j<=200000; j+=t) {
			for (auto g : e[j]) {
				ee[g.x].push_back(g.y);
				ee[g.y].push_back(g.x);
			}

			for (int x : jbg[j]) {
				verts[vv++] = x;
			}
		}

		for (int i=0; i<vv; i++) {
			int x = verts[i];
			if (!v[x]) {
				int z = bfs(x);
				c[t] += z * 1ll * (z+1) / 2;
			}
		}

		for (int i=0; i<vv; i++) {
			int x = verts[i];
			v[x] = 0;
			ee[x].clear();
		}

		vv = 0;
	}
	
	for (int i=200000; i>=1; i--) {
		for (int j=2*i; j<=200000; j+=i) {
			c[i] -= c[j];
		}
	}
	
	for (int i=1; i<=200000; i++)
		if (c[i]) {
			printf("%d %lld\n", i, c[i]);
		}

}
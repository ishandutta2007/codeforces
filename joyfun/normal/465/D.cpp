#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

struct Point {
	int v[3];
	void read() {
		for (int i = 0; i < 3; i++)
			scanf("%d", &v[i]);
	}
	bool operator == (const Point& c) const {
		return (v[0] == c.v[0] && v[1] == c.v[1] && v[2] == c.v[2]);
	}
} p[10];

typedef long long ll;

ll dis(Point a, Point b) {
	ll dx = a.v[0] - b.v[0];
	ll dy = a.v[1] - b.v[1];
	ll dz = a.v[2] - b.v[2];
	return dx * dx + dy * dy + dz * dz;
}

ll d[10];

bool judge() {
	for (int i = 1; i < 8; i++)
		for (int j = 0; j < i; j++) {
			if (p[i] == p[j]) return false;
		}
	d[0] = 0;
	for (int i = 1; i < 8; i++)
		d[i] = dis(p[0], p[i]);
	sort(d, d + 8);
	ll a = d[1], b = d[4], c = d[7];
	if (a != d[2] || a != d[3] || d[2] != d[3]) return false;
	if (b != d[5] || b != d[6] || d[5] != d[6]) return false;
	if (2 * a != b) return false;
	if (a + b != c) return false;
	return true;
}

bool dfs(int u) {
	if (u == 8) {
		if (judge())
			return true;
		return false;
	}
	sort(p[u].v, p[u].v + 3);
	do {
		if (dfs(u + 1)) return true;
	} while (next_permutation(p[u].v, p[u].v + 3));
	return false;
}
int main() {
	for (int i = 0; i < 8; i++)
		p[i].read();
	if (!dfs(0)) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 0; i < 8; i++)
			printf("%d %d %d\n", p[i].v[0], p[i].v[1], p[i].v[2]);
	}
	return 0;
}
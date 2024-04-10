#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 567890;

int n, s, u, v, deg[maxN];

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		deg[u]++;
		deg[v]++;
	}
	int leaf = 0;
	for (int i = 1; i <= n; i++)
		leaf += deg[i] == 1;
	printf("%.10f\n", (double)s / leaf * 2);
}
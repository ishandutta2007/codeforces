// Hydro submission #6125feb8432a91aa43c1f45a@1629879992214
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m1, m2, f[N], f2[N], sum, ansu[N], ansv[N];

int find(int x) {
	return f[x] = f[x] == x ? x : find(f[x]);
}

int find2(int x) {
	return f2[x] = f2[x] == x ? x : find2(f2[x]);
}

int main() {
	scanf("%d%d%d", &n, &m1, &m2);
	for (int i = 1; i <= n; i++) f[i] = f2[i] = i;
	for (int i = 1; i <= m1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (find(u) != find(v)) f[find(u)] = find(v);
	}
	for (int i = 1; i <= m2; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (find2(u) != find2(v)) f2[find2(u)] = find2(v);
	}
	sum = n - 1 - max(m1, m2);
	printf("%d\n", sum);
	for (int i = 2; i <= n; i++) 
		if (find(i) != find(1) && find2(i) != find2(1)) {
			printf("%d %d\n", 1, i);
			sum--;
			f[find(i)] = find(1);
			f2[find2(i)] = find2(1);
		}
	for (int i = 2, j = 1; sum; i++) 
		if (find(i) != find(1)) {
			while (find2(j) == find2(1)) j++;
			printf("%d %d\n", i, j);
			sum--;
			f[find(i)] = find(1);
			f2[find2(j)] = find2(1);
		}
	return 0;
}
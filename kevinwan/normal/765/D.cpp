#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[100001],g[100001],h[100001];
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", f + i);
	for (i = 1; i <= n; i++)if (f[i] != f[f[i]]) { printf("-1"); getchar(); getchar(); return 0; }
	int it = 1;
	for (i = 1; i <= n; i++) {
		if (f[i] == i)h[it]=i,g[i] = it,it++;
	}
	printf("%d\n", it - 1);
	for (i = 1; i <= n; i++)printf("%d ", g[f[i]]);
	printf("\n");
	for (i = 1; i < it; i++)printf("%d ", h[i]);
	getchar(); getchar();
}
#include <bits/stdc++.h>
using namespace std;
bool f[10];
int a[10];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int i, x;
	for (i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &x);
		f[x] = 1;
	}
	for (i = 0; i < n; i++)if (f[a[i]])printf("%d ", a[i]);
	getchar(); getchar();
}
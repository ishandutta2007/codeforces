#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
	int n, k, ans = 0,i;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)scanf("%d", a + i);
	for (i = 0; i < n; i++) {
		if (a[i] <= k)ans++;
		else break;
	}
	for (int j = n - 1; j > i; j--) {
		if (a[j] <= k)ans++;
		else break;
	}
	printf("%d", ans);
	getchar(); getchar();
}
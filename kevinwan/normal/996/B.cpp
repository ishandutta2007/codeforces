#include <bits/stdc++.h>
using namespace std;
int a[100000];
int x;
int main() {
	int n,i,lo=0x3f3f3f3f;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", a + i);
		lo = min(lo, a[i]);
	}
	int cur = lo;
	while (1) {
		if (a[cur%n] - cur <= 0) {
			printf("%d", cur%n + 1);  return 0;
		}
		cur++;
	}
	getchar(); getchar();
}
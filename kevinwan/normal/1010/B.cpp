#include <bits/stdc++.h>
using namespace std;
int s[30], n, m, x;
int main() {
	scanf("%d%d", &m, &n);
	int i, j;
	for (i = 0; i < n; i++) {
		printf("1\n");
		fflush(stdout);
		scanf("%d", &x);
		if (x == 0)return 0;
		if (x == -1)s[i] = -1;
		else s[i] = 1;
	}
	int cur = 0;
	for (j = 0, i = 1 << 29; i; i >>= 1) {
		if (cur + i>m)continue;
		printf("%d\n", cur + i);
		fflush(stdout);
		scanf("%d", &x);
		x *= s[j%n];
		if (x == 0)return 0;
		if (x == 1)cur += i;
		j++;
	}
}
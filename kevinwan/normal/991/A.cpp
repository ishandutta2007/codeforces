#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ans = d - a - b + c;
	if (ans < 1) {
		printf("-1"); return 0;
	}
	if (c > min(a, b)) {
		printf("-1"); return 0;
	}
	printf("%d", d - a - b + c);
	getchar(); getchar();
}
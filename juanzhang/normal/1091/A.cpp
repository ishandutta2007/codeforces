#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int res = 0;
	for (int i = 1; i <= a; i++) {
		if (b >= i + 1 && c >= i + 2) {
			res = max(res, i * 3 + 3);
		}
	}
	printf("%d", res);
	return 0;
}
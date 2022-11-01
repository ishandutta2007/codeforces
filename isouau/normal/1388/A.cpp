#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n <= 30) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		if (n - 30 == 6 || n - 30 == 10 || n - 30 == 14) {
			printf("6 10 15 %d\n", n - 31);
		} else {
			printf("6 10 14 %d\n", n - 30);
		}
	}
	return 0;
}
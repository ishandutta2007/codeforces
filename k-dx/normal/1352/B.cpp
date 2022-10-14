#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);

		//par
		if (n - 2*(k-1) > 0 and (n - 2*(k-1)) % 2 == 0) {
			printf("YES\n");
			for (int i = 0; i < k-1; i++) {
				printf("2 ");
			}
			printf("%d\n", n - 2*(k-1));
			continue;
		}

		//npar
		if (n - (k-1) > 0 and (n - (k-1)) % 2 == 1) {
			printf("YES\n");
			for (int i = 0; i < k-1; i++) {
				printf("1 ");
			}
			printf("%d\n", n - (k-1));
			continue;
		}

		printf("NO\n");
	}

	return 0;
}
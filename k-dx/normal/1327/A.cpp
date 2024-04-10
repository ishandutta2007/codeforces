#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);

		int last = -1;
		for (int i = 1, j = 0; j < k-1; i+=2, j++) {
			n -= i;
			last = i;

			if (n < 0) break;
		}

		if (n > last and n&1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
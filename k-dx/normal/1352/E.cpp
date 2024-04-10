#include <bits/stdc++.h>
using namespace std;

bitset<64000001> x;
int t[8001];

int main () {
	int ti;
	scanf("%d", &ti);

	while (ti--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &t[i]);
		}

		for (int i = 0; i < n; i++) {
			int sum = t[i];
			for (int j = i + 1; j < n; j++) {
				sum += t[j];
				//printf("sum = %d\n", sum);

				x[sum] = 1;
			}
		}

		int w = 0;
		for (int i = 0; i < n; i++) {
			if (x[t[i]] == 1) {
				//printf("%d ", t[i]);
				w++;
			}
		}
		printf("%d\n", w);

		x.reset();
	}

	return 0;
}
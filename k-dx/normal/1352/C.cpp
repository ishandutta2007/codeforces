#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);

		long long int beg = 0, mid, end = LLONG_MAX;
		while (beg + 1 != end) {
			mid = (beg + end) / 2;
			long long int ktora = mid - mid/n;
			if (ktora >= k) {
				end = mid;
			}
			else {
				beg = mid;
			}
		}

		printf("%d\n", end);

	}

	return 0;
}
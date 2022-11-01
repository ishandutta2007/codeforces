#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int t, n, k, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		long long mx = 0;
		for (int i = 0; i < k; ++i) {
			int sum = 0;
			for (int j = i; j < n; j += k) sum = max(sum, a[j]);
			mx += sum;
		}
		printf("%lld\n", mx);
	}
	return 0;
}
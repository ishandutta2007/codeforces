#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long llong;

int arr[1000];
int main() {
	int n, m, c, x, s, e;
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n; ++i) arr[i] = 1e5;
	s = -1; e = n;
	while (m--) {
		scanf("%d", &x);
		int p;
		if (x <= c / 2) {
			p = upper_bound(arr, arr + (s + 1), x) - arr;
			arr[p] = x;
			s = max(p, s);
		}
		else {
			p = lower_bound(arr + e, arr + n, x) - arr - 1;
			arr[p] = x;
			e = min(p, e);
		}
		printf("%d\n", p + 1);
		fflush(stdout);
		if (s + 1 == e) return 0;
	}
	return 0;
}
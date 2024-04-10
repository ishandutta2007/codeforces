#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = (int)1e9 + 7;

const int N = (int)1e6 + 7;

long long a[ N ];
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	if (n == 1) {
		printf("1 1\n");
		printf("%lld\n", -a[1]);
		printf("1 1\n");
		printf("%d\n", 0);
		printf("1 1\n");
		printf("%d\n", 0);
		return 0;
	}
	printf("1 %d\n", n - 1);
	for (int i = 1; i < n; i++) {
		long long v = (a[i] % n + n) % n;
		printf("%lld%c", v * (n - 1), " \n"[i == n-1]);
		a[i] += v * (n - 1);
	}
	printf("%d %d\n", n, n);
	printf("%lld\n", -a[n]);
	a[n] = 0;
	printf("%d %d\n", 1, n);
	for (int i = 1; i <= n; i++) {
		printf("%lld%c", -a[i], " \n"[i == n]);
	}
	return 0;
}
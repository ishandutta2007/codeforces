#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
int n, a[mxn];

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	if (n == 1) {
		printf("1 1\n%d\n1 1\n0\n1 1\n0\n", -a[0]);
		return 0;
	}
	printf("1 %d\n", n);
	rep(i, n) printf("%lld%c", i + 1 == n ? 0 : -1LL * n * a[i], " \n"[i + 1 == n]);
	printf("1 %d\n", n - 1);
	rep(i, n - 1) printf("%lld%c", 1LL * (n - 1) * a[i], " \n"[i + 1 == n - 1]);
	printf("%d %d\n", n, n);
	printf("%d\n", -a[n - 1]);
	return 0;
}
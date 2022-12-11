#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;

int n, k, x, a[N], b, l[N], r[N];

int main() {
	scanf("%d%d%d", &n, &k, &x);
	for(int i = 1; i <= n; i ++)
		scanf("%d", a + i);
	b = x;
	for(int i = 1; i < k; i ++) b *= x;
	long long res = 0;
	for(int i = 1; i <= n; i ++) l[i] = l[i - 1] | a[i];
	for(int i = n; i >= 1; i --) r[i] = r[i + 1] | a[i];
	for(int i = 1; i <= n; i ++) {
		res = max(res, a[i] * 1ll * b | l[i - 1] | r[i + 1]);
	}
	printf("%I64d\n", res);
	return 0;
}
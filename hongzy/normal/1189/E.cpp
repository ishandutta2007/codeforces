#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

int n, p, k;
map<int, int> cnt;

int main() {
	scanf("%d%d%d", &n, &p, &k);
	long long ans = 0;
	for(int i = 1; i <= n; i ++) {
		int x; scanf("%d", &x);
		ans += cnt[(x * 1ll * x % p * x % p * x % p - k * 1ll * x % p + p) % p] ++;
	}
	printf("%I64d\n", ans);
	return 0;
}
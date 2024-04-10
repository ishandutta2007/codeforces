#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int a[N], n, ans, f[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		ans = max(ans, f[a[i]] = f[a[i] - 1] + 1); 
	}
	printf("%d\n", n - ans);
	return 0;
}
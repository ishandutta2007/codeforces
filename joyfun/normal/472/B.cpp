#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 2005;
int n, m, a[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = n; i >= 1; i -= m)
		ans += (a[i] - 1) * 2;
	printf("%d\n", ans);
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2000000;

int n, a, vis[N + 5], pre[N + 5];

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		vis[a] = 1;
	}
	int p = 0;
	for (int i = 1; i <= N; i++) {
		pre[i] = p;
		if (vis[i])
			p = i;
	}
	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) continue;
		for (int j = i + i; j <= N; j += i) {
			ans = max(ans, pre[j] % i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
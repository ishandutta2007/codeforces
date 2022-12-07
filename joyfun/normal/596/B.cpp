#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 200005;
int n, b[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	long long ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		ans += max(cnt - b[i], b[i] - cnt);
		cnt = b[i];
	}
	printf("%lld\n", ans);
	return 0;
}
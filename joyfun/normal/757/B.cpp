#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;

int n, cnt[N];

int main() {
	scanf("%d", &n);
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		cnt[a]++;
	}
	int ans = 1;
	for (int i = 2; i <= 100000; i++) {
		int tot = 0;
		for (int j = i; j <= 100000; j += i) {
			tot += cnt[j];
		}
		ans = max(ans, tot);
	}
	printf("%d\n", ans);
	return 0;
}
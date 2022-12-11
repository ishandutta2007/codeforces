#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1100;

int n, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	int sum = 0;
	for(int i = 1; i <= n; i ++) {
		sum += a[i];
	}
	int ans = 0, now = 0;
	for(int i = n; i >= 1; i --) {
		if(now > sum - now) break ;
		now += a[i];
		ans ++;
	}
	printf("%d\n", ans);
	return 0;
}
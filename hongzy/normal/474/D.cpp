#include <algorithm>
#include <cstdio>
using namespace std;

const int n = 1e5;
const int mo = 1e9 + 7;

int t, k, ans[n + 5], f[n + 5][2];

int main() {
	scanf("%d%d", &t, &k); ans[0] = f[0][1] = 1;
	for(int i = 1; i <= n; i ++) {
		f[i][1] = ans[i - 1];
		if(i >= k) {
			f[i][0] = ans[i - k];
		}
		ans[i] = (f[i][0] + f[i][1]) % mo;
//		if(i <= 4) {
//			printf("%d %d\n", f[i][0], f[i][1]);
//		}
	}
	for(int i = 1; i <= n; i ++) (ans[i] += ans[i - 1]) %= mo;
	while(t --) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", (ans[r] - ans[l - 1] + mo) % mo);
	}
	return 0;
}
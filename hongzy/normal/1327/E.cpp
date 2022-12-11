#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 998244353, N = 2e5 + 10;
int n, pw[N] = {1};
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) pw[i] = pw[i - 1] * 10ll % mod;
	for(int i = 1; i < n; i ++) {
		int x = pw[n - i] * 18ll % mod;
		if(i != n - 1) (x += (n - i - 1ll) * 81ll * pw[n - i - 1] % mod) %= mod;
		printf("%d ", x);
	}
	puts("10");
	return 0;
}
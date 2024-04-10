#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1010;

int n, a[N], b[N], sum, ma, st = 1, c[N];
long long ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d", a + i, b + i);
		sum += a[i]; ma = max(ma, b[i]);
		st = max(st, min(a[i], b[i]));
	}
	//h >= min(a[i], b[i])
	ans = 1ll * sum * ma;
	for(int h = st; h <= 1000; h ++) {
		int res = 0, l = 0, lim = n >> 1;
		for(int i = 1; i <= n; i ++) {
			if(a[i] <= h && b[i] <= h) {
				res += a[i];
				if(a[i] > b[i]) {
					c[++ l] = b[i] - a[i];
				}
			} else if(a[i] <= h) {
				res += b[i]; lim --;
			} else {
				res += a[i];
			}
		}
		if(lim < 0) continue ;
		sort(c + 1, c + l + 1);
		for(int i = 1; i <= l && i <= lim; i ++) res += c[i];
		ans = min(ans, 1ll * res * h); 
	}
	printf("%I64d\n", ans);
	return 0;
}
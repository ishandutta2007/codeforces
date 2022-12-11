#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int mo = 1e9 + 7;
int n, a[2010], cnt, fac[2020], fix, C[2020][2020];
int main() {
	scanf("%d", &n); fac[0] = 1;
	for(int i = 1; i <= n; i ++) {
		fac[i] = 1ll * fac[i - 1] * i % mo;
		scanf("%d", a + i);
		if(a[i] == i) {
			puts("0");
			return 0;
		}
		if(a[i] == -1) cnt ++;
	}
	for(int i = 0; i <= n; i ++)
		for(int j = 0; j <= i; j ++)
			C[i][j] = j == 0 || j == i ? 1 : (C[i - 1][j] + C[i - 1][j - 1]) % mo;
	fix = cnt;
	for(int i = 1; i <= n; i ++)
		if(~ a[i] && a[a[i]] == -1)
			fix --;
	int ans = fac[cnt];
	for(int i = 1; i <= fix; i ++) {
		int r = 1ll * C[fix][i] * fac[cnt - i] % mo;
		if(i & 1) (ans += mo - r) %= mo;
		else (ans += r) %= mo;
	}
	printf("%d", ans);
	return 0;
}
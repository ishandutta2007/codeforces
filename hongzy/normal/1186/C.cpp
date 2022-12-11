#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e6 + 10;

char a[N], b[N];
int n, m, fail, ans, dif[N];

int main() {
	scanf("%s\n%s", a + 1, b + 1);
	n = strlen(a + 1); m = strlen(b + 1);
	for(int i = 1; i < n; i ++) {
		dif[i] = a[i] != a[i + 1];
		dif[i] += dif[i - 1];
	}
	for(int i = 1; i <= m; i ++) {
		if(a[i] != b[i]) {
			fail ++;
		}
	}
	if(fail % 2 == 0) ans ++;
	for(int i = m + 1; i <= n; i ++) {
		fail += dif[i - 1] - dif[i - m - 1];
		if(fail & 1) ;
		else ans ++;
	}
	printf("%d\n", ans);
	return 0;
}
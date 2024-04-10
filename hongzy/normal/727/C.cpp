#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 5010;

int ask(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
int s[N], a[N], b[N], ans[N], n, sum;

int main() {
	scanf("%d", &n);
	int m = n & 1 ? n : n - 1;
	for(int i = 2; i <= m; i ++) s[i] = ask(i - 1, i);
	s[1] = ask(1, m);
	for(int i = 1; i <= m; i ++) sum += s[i];
	sum >>= 1;
	for(int i = 2; i <= m; i += 2) sum -= s[i];
	ans[m] = sum;
	for(int i = m; i >= 2; i --)
		ans[i - 1] = s[i] - ans[i];
	if(!(n & 1)) {
		sum = ask(1, n);
		ans[n] = sum - ans[1];
	}
	printf("!");
	for(int i = 1; i <= n; i ++) {
		printf(" %d", ans[i]);
	}
	fflush(stdout);
	return 0;
}
/*
a b c d
a + b = 2
a + c = 2
a + d = 2
3a + b + c
*/
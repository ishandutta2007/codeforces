#include <stdio.h>
#include <string.h>

int n;
char str[55];
__int64 mi[55];

void init() {
	mi[0] = 1;
	for (int i = 1; i <= 50; i++)
		mi[i] = mi[i - 1] * 2;
}

int main() {
	init();
	scanf("%d%s", &n, str);
	__int64 ans = 0;
	for (int i = 0; i < n; i++)
		if (str[i] == 'B')
			ans += mi[i];
	printf("%I64d\n", ans);
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, x, sum;

int main() {
	int num;
	scanf("%d%d", &n, &x);
	while (n--) {
		scanf("%d", &num);
		sum += num;
	}
	printf("%d\n", abs(sum) / x + (abs(sum) % x != 0));
	return 0;
}
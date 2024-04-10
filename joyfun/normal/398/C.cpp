#include <stdio.h>
#include <string.h>

int n, i;
int main() {
	scanf("%d", &n);
	if (n == 5)
		printf("1 2 3\n1 3 3\n2 4 2\n4 5 1\n3 4\n3 5\n");
    else {
		for (i = 1; i <= n/2; i++) printf("%d %d 1\n", i, i+n/2);
		for (i = n/2 + 1; i <= n - 1; i++) printf("%d %d %d\n", i, i + 1, 2 * (i - n/2) - 1);
		for (i = 1; i <= n/2 - 1; i++) printf("%d %d\n", i, i +1);
		printf("1 3\n");
	}
	return 0;
}
#include <stdio.h>
#include <string.h>

int n, k, i, j;
char ch[105];

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", ch);
	if (n - k < k) {
	for (i = k; i < n; i++)
		printf("RIGHT\n");
	for (i = n - 1; i > 0; i--) {
		printf("PRINT %c\n", ch[i]);
		printf("LEFT\n");
	}
	printf("PRINT %c\n", ch[0]);
	}
	else {
	for (i = 1; i < k; i++)
		printf("LEFT\n");
	for (i = 0; i < n - 1; i++) {
		printf("PRINT %c\n", ch[i]);
		printf("RIGHT\n");
	}
	printf("PRINT %c\n", ch[n - 1]);
	}
	return 0;
}
#include <cstdio>

int x;

int main() {
	scanf("%d", &x);
	if (x == 1) printf("3\n");
	else if (x == 2) printf("5\n");
	else printf("%d\n", 7 + x - 3 + ((x - 3) / 3));
	return 0;
}
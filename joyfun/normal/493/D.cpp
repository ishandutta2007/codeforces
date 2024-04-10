#include <cstdio>
#include <cstring>

int n;

int main() {
	scanf("%d", &n);
	if (n % 2) printf("black\n");
	else {
		printf("white\n");
		printf("1 2\n");
	}
	return 0;
}
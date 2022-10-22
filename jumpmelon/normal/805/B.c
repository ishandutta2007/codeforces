#include <stdio.h>

int main() { 
	int n, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		putchar('a' + ((i>>1)&1));
	}
	return 0;
}
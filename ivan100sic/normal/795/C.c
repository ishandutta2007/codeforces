#include <stdio.h>

int n, i;
int a[100005];

int main() {
	scanf("%d", &n);

	if (n % 2 == 0) {
		for (i=0; i<n/2; i++) {
			printf("1");
		}
	} else {
		printf("7");
		for (i=0; i<n/2-1; i++) {
			printf("1");
		}
	}

}
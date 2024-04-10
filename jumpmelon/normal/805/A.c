#include <stdio.h>

int main() { 
	int l, r;
	scanf("%d%d", &l, &r);
	if(l==r) {
		printf("%d\n", l);
	} else {
		printf("%d\n", 2);
	}
	return 0;
}
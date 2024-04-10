#include <cstdio>

char a[128], b[128];

int main() {
	int i;
	scanf("%s%s", a, b);
	for (i = 0; a[i]; i++) putchar(a[i] == b[i] ? '0' : '1');
}
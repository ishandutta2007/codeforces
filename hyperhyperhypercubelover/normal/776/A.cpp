#include <cstdio>
#include <cstring>

char a[16], b[16], c[16], d[16];

int main() {
	int n;
	scanf("%s%s%d", a, b, &n);
	printf("%s %s\n", a, b);
	while (n--) {
		scanf("%s%s", c, d);
		if (strcmp(a, c)) strcpy(b, d);
		else strcpy(a, d);
		printf("%s %s\n", a, b);
	}
}
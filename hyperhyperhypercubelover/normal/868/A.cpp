#include <cstdio>

char a[4], b[101][4];

int main() {
	int i, j, n;
	scanf("%s%d", a, &n);
	for (i = 0; i < n; i++) scanf("%s", b[i]);
	for (i = 0; i < n; i++) if (b[i][0] == a[0] && b[i][1] == a[1]) {
		puts("YES");
		return 0;
	}
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (b[i][0] == a[1] && b[j][1] == a[0]) {
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}
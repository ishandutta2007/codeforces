#include <cstdio>

char a[51];

int main() {
	int i, j, n, m;
	scanf("%d%d%s", &n, &m, a);
	while (m--) for (i = n; --i > 0;) if (a[i] == 'G' && a[i - 1] == 'B') {
		a[i] = 'B';
		a[i - 1] = 'G';
		i--;
	}
	puts(a);
}
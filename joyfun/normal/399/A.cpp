#include <stdio.h>
#include <string.h>

int n, p, k, vis[105];
int i;

int main() {
	scanf("%d%d%d", &n, &p, &k);
	for (i = p - k; i <= p + k; i++) {
		if (i >= 1 && i <= n)
			vis[i] = 1;
	}
	for (i = 1; vis[i] == 0; i++);
	if (i == 1) {
		if (i == p) printf("(%d)", i);
		else printf("%d", i);
	}
	else {
		if (i == p) printf("<< (%d)", i);
		else printf("<< %d", i);
	}
	i++;
	for (; vis[i]; i++) {
		if (i == p) printf(" (%d)", i);
		else printf(" %d", i);
	}
	if (i != n + 1) printf(" >>\n");
	else printf("\n");
	return 0;
}
#include <stdio.h>
#include <string.h>

int a[3], b[3], n;

int main() {
	int i;
	for (i = 0; i < 3; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 3; i++)
		scanf("%d", &b[i]);
	scanf("%d", &n);
	int aa = a[0] + a[1] + a[2];
	int bb = b[0] + b[1] + b[2];
	if (n >= (aa / 5 + (aa % 5 != 0) + bb / 10 + (bb % 10 != 0)))
		printf("YES\n");
	else printf("NO\n");
	return 0;
}
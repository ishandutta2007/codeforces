#include <bits/stdc++.h>
using namespace std;
bool hot[4][100];
int main() {
	int n, k,i,j;
	scanf("%d%d", &n, &k);
	printf("YES\n");
	if (k % 2)hot[1][n / 2] = 1;
	k /= 2;
	for (i = 1; i < n / 2; i++, k--) {
		if (k == 0)break;
		hot[1][i] = hot[1][n - i - 1] = 1;
	}
	for (i = 1; i < n / 2; i++, k--) {
		if (k == 0)break;
		hot[2][i] = hot[2][n - i - 1] = 1;
	}
	if (k == 1)hot[1][n / 2] = hot[2][n / 2] = 1;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < n; j++) { if (hot[i][j])printf("#"); else printf("."); }
		printf("\n");
	}
	getchar(); getchar();
}
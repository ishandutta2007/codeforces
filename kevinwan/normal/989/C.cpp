#include <bits/stdc++.h>
using namespace std;
char ans[50][50];
int main() {
	int a, b, c, d,i,j;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("50 50\n");
	if (a == 1)d++;
	for (i = 0; i < 4&&a>1; i++) {
		for (j = 0; j < 25&&a>1; j++) {
			a--;
			ans[2 * i][2 * j + 1] = 3;
			ans[2 * i+1][2 * j ] = 3;
			ans[2 * i+1][2 * j + 1] = 3;
		}
	}
	a--;
	d--;
	for (i = 10; i < 20; i += 2) {
		for (j = 0; j < 50; j += 2) {
			if (b == 0)continue;
			b--;
			ans[i][j] = 1;
		}
	}
	for (i = 20; i < 30; i += 2) {
		for (j = 0; j < 50; j += 2) {
			if (c == 0)continue;
			c--;
			ans[i][j] = 2;
		}
	}
	for (i = 30; i < 40; i += 2) {
		for (j = 0; j < 50; j += 2) {
			if (d == 0)continue;
			d--;
			ans[i][j] = 3;
		}
	}
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			printf("%c", 'A' + ans[i][j]);
		}
		printf("\n");
	}
	getchar(); getchar();
}
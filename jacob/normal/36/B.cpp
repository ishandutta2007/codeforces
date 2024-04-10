#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
using namespace std;
int n, k;
char ma[4][4];

bool isBlack(int level, int x, int y) {
	if (level == 0)
		return false;
	int xn = x / n;
	int yn = y / n;
	if (isBlack(level - 1, xn, yn))
		return true;
	return (ma[x % n][y % n] == '*');
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", ma[i]);
	}
	int sz = 1;
	for (int i = 0; i < k; i++) {
		sz *= n;
	}
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			printf("%c", (isBlack(k, i, j) ? '*' : '.'));
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
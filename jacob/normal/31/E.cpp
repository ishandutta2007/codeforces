#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <memory.h>
using namespace std;

int digits[40];
int n;

typedef long long LL;
LL pow10[19];


LL ma[37][19];
bool from[37][19];

void doPrint(int x, int y) {
	if (x == 0)
		return;
	doPrint(x - 1, (from[x][y]) ? (y - 1) : y);
	printf("%c", (from[x][y]) ? 'H': 'M');
}

int main(void) {
	scanf("%d", &n);
	char str[40];
	scanf("%s", str);
	for (int i = 0; i < 2*n; i++) {
		digits[i] = str[i] - '0';
	}
	pow10[0] = 1;
	for (int i = 0; i < 18; i++) {
		pow10[i+1] = pow10[i] * 10;
	}
	memset(ma, -1, sizeof(ma));
	ma[0][0] = 0;
	for (int i = 1; i <= 2*n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i - j > n)
				continue;
			LL firstRes = -1, secondRes = -1;
			if (j != 0 && ma[i-1][j-1] >= 0) {
				firstRes = ma[i-1][j-1] + pow10[n - j - 1] * digits[i-1];
			}
			if (ma[i-1][j] >= 0) {
				secondRes = ma[i-1][j] + pow10[n - (i - j) - 1] * digits[i-1];
			}
			if (firstRes > secondRes) {
				ma[i][j] = firstRes;
				from[i][j] = true;
			} else {
				ma[i][j] = secondRes;
				from[i][j] = false;
			}
		}
	}
	doPrint(n*2, n);
	return 0;
}
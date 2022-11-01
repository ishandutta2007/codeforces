#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
using namespace std;

int main(void) {
	int a, b, mod;
	scanf("%d%d%d", &a, &b, &mod);
	int m = 0;
	int d = 1000000000 % mod;
	for (int i = 1; i <= a; i++) {
		m += d;
		if (m >= mod) m -= mod;
		if (m == 0) break;
		int req = (mod - m);
		if (req > b) {
			printf("1 %09d\n", i);
			return 0;
		}
	}
	printf("2\n");
	return 0;
}
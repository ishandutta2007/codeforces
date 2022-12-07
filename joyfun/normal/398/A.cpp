#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
__int64 a, b;

__int64 cal(int num) {
	__int64 ans = 0;
	ans += num - 1 + (a - (num - 1)) * (a - (num - 1));
	__int64 k = b / (num + 1) + 1;
	__int64 kk = k * (num + 1) - b;
	ans -= (kk * (k - 1) * (k - 1) + (num + 1 - kk) * k * k);
	return ans;
}

void print(int x) {
	int k = b / x + 1;
	int kk = k * x - b;
	int kkk = x - kk;
	int sb = x - 2;
	int sbb = 1;
	while (kk) {
		for (int i = 0; i < k - 1; i++) {
			printf("x");
		}
		kk--;
		if (sb != 0) {
			printf("o");
			sb--;
		}
		else if (sbb != 0) {
			for (int i = 0; i < a - (x - 2); i++)
				printf("o");
			sbb--;
		}
	}
	while (kkk) {
		for (int i = 0; i < k; i++) {
			printf("x");
		}
		kkk--;
		if (sb != 0) {
			printf("o");
			sb--;
		}
		else if (sbb != 0) {
			for (int i = 0; i < a - (x - 2); i++)
				printf("o");
			sbb--;
		}
	}
	printf("\n");
}
int main() {
	__int64 ans = -10000000000000000;
	int ansv;
	scanf("%I64d%I64d", &a, &b);
	if (b == 0) {
		printf("%I64d\n", a * a);
		for (int i = 0; i < a; i++)
			printf("o");
		printf("\n");
		return 0;
	}
	if (a == 0) {
		printf("%I64d\n", -b * b);
		for (int i = 0; i < b; i++)
			printf("x");
		printf("\n");
		return 0;
	}
	for (int i = 1; i <= a; i++) {
		__int64 t = cal(i);
		if (t > ans) {
			ans = t;
			ansv = i + 1;
		}
	}
	printf("%I64d\n", ans);
	print(ansv);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int n;

int main() {
	scanf("%d", &n);
	printf("%d\n", (2 * n + 1) / 3);
	if (n % 3 == 2) {
		for (int i = 0; i <= n / 3; i++)
			printf("%d %d\n", i + 1, 2 * i + 1);
		for (int i = 0; i < n / 3 ; i++)
			printf("%d %d\n", n / 3 + i + 2, 2 * i + 2);
	} else if (n % 3 == 0) {
		printf("1 1\n");
		for (int i = 0; i < n / 3; i++)
			printf("%d %d\n", i + 2, 2 * i + 2);
		for (int i = 0; i < n / 3 - 1; i++)
			printf("%d %d\n", n / 3 + i + 2, 2 * i + 3);
	} else if (n % 3 == 1)  {
		printf("1 1\n");
		if (n == 1) return 0;
		printf("2 2\n");
		for (int i = 0; i < n / 3; i++)
			printf("%d %d\n", i + 3, 2 * i + 3);
		for (int i = 0; i < n / 3 - 1; i++)
			printf("%d %d\n", n / 3 + i + 3, 2 * i + 4);
	}
}
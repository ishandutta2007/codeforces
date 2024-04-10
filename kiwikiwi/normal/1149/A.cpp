#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n, x, c1, c2;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 1) c1++;
		else c2++;
	}
	if (c1 == 0 || c2 == 0) {
		for (int i = 0; i < c1; i++)
			printf("1 ");
		for (int i = 0; i < c2; i++)
			printf("2 ");
		puts("");
		return 0;
	}
	printf("2 ");
	c2--;
	printf("1 ");
	c1--;
	for (int i = 0; i < c2; i++)
		printf("2 ");
	for (int i = 0; i < c1; i++)
		printf("1 ");
	puts("");
}
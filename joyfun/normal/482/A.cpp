#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	int bo = 0;
	for (int i = 1; i <= 1 + k; i++) {
		if (i % 2) {
			if (bo) printf(" ");
			else bo = 1;
			printf("%d", (i + 1) / 2);
		} else {
			if (bo) printf(" ");
			else bo = 1;
			printf("%d", k + 1 - (i - 1) / 2);
		}
	}
	for (int i = k + 2; i <= n; i++) {
		if (bo) printf(" ");
		else bo = 1;
		printf("%d", i);
	}
	printf("\n");
	return 0;
}
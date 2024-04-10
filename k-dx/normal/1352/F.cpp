#include <bits/stdc++.h>
using namespace std;

int main () {
	int ti;
	scanf("%d", &ti);

	while (ti--) {
		int n0, n1, n2;
		scanf("%d %d %d", &n0, &n1, &n2);

		int pop = -1;
		//11
		if (pop == -1 and n2 > 0) {
			printf("1");
			pop = 1;
		}

		while (n2 > 0) {
			printf("1");
			pop = 1;
			n2--;
		}

		//00
		if (n0 > 0) {
			printf("0");
			if (pop != -1) n1--;
			pop = 0;
		}

		while (n0 > 0) {
			printf("0");
			pop = 0;
			n0--;
		}

		//10 | 01
		if (pop == -1 and n1 > 0) {
			printf("0");
			pop = 0;
		}

		while (n1 > 0) {
			if (pop == 0) {
				printf("1");
				pop = 1;
			}
			else {
				printf("0");
				pop = 0;
			}
			n1--;
		}

		printf("\n");

	}

	return 0;
}
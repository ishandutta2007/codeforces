#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		if (n <= 2) {
			printf("0\n");
			continue;
		}

		printf("%d\n", (n+1)/2-1);
		
	}
	return 0;
}
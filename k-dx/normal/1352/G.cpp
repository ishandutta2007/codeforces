#include <bits/stdc++.h>
using namespace std;

int main () {
	int ti;
	scanf("%d", &ti);

	while (ti--) {
		int n;
		scanf("%d", &n);

		if (n <= 3) {
			printf("-1\n");
			continue;
		}

		vector<int> left, right;
		bool leftx = false;
		for (int i = 5; i <= n; i++) {
			if (leftx) {
				left.push_back(i);
			}
			else {
				right.push_back(i);
			}
			leftx = !leftx;
		}

		for (int i = left.size()-1; i >= 0; i--)
			printf("%d ", left[i]);

		printf("3 1 4 2 ");

		for (int e : right)
			printf("%d ", e);

		printf("\n");

	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	scanf("%d", &t);

	while (t--) {
		int x;
		scanf("%d", &x);

		string s = to_string(x);

		int z = 1;
		vector<int> odp;
		while (x != 0) {
			if (x % 10 != 0) {
				odp.push_back((int)(x % 10) * z);
			}
			x /= 10;
			z*=10;
		}


		printf("%d\n", odp.size());
		for (int e : odp)
			printf("%d ", e);
		printf("\n");

	}

	return 0;
}
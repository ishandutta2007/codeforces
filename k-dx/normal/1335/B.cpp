#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);

		string x = "";
		for (int i = 0; i < b; i++) {
			x += (char)(i + 'a');
		}

		for (int i = x.size(); i < a; i++) {
			x += 'a';
		}

		for (int i = 0; i < n; i++) {
			printf("%c", x[i % x.size()]);
		}
		printf("\n");

	}
	return 0;
}
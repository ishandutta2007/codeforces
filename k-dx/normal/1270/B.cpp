#include <bits/stdc++.h>
using namespace std;

int t, n;

int main () {
	scanf("%d", &t);

	for (int ti = 0; ti < t; ti++) {
		scanf("%d", &n);
		
		int last, next;
		bool ok = false;

		scanf("%d", &last);
		for (int i = 1; i < n; i++) {
			scanf("%d", &next);

			if (abs(last - next) >= 2 and ok == false) {
				printf("YES\n%d %d\n", i, i+1);
				ok = true;
			}

			last = next;
		}

		if (ok == false) printf("NO\n");
	}

	return 0;
}
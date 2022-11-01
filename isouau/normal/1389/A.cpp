#include <bits/stdc++.h>
using namespace std;

int T, l, r;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &l, &r);
		if (l * 2 <= r) printf("%d %d\n", l, l * 2);
		else printf("-1 -1\n");
	}
	return 0;
}
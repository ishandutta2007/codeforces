#include <bits/stdc++.h>
using namespace std;

int t, n;

int main () {
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		int k1, k2;
		scanf("%d %d %d", &n, &k1, &k2);
		int p1 = 0, p2 = 0;
		for (int i = 0; i < k1; i++) {
			int x;
			scanf("%d", &x);
			p1 = max(p1, x);
		}
		for (int i = 0; i < k2; i++) {
			int x;
			scanf("%d", &x);
			p2 = max(p2, x);
		}
		
		if (p1 > p2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
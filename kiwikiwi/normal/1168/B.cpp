#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define maxN 323456
char s[maxN];
i64 ans;

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int l = 0; l < n; l++) {

		for (int r = l + 2; r < n; r++) {
			bool found = 0;
			for (int m = r - 1; 2 * m - r >= l; m--) {
				if (s[r] == s[m] && s[m] == s[2 * m - r]) {
					found = 1;
					break;
				}
			}
			if (found) {
				ans += n - r;
				break;
			}
		}
	}
	printf("%lld\n", ans);
}
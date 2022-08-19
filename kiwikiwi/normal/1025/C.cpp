#include <bits/stdc++.h>
using namespace std;

const int N = 234567;
int n, c[N];
char s[N];
int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		c[i] = (s[i] != s[(i + 1) % n]);
	}
	if (*min_element(c, c + n) == 1) {
		printf("%d\n", n);
		return 0;
	}
	int s = 0, ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (c[i % n] == 0) s = 0;
		else {
			s += c[i % n];
			ans = max(ans, s);
		}
	}
	printf("%d\n", ans + 1);
}
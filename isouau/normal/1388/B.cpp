#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int cnt = (n + 3) / 4;
		for (int i = 1; i <= n - cnt; i++) putchar('9');
		for (int i = 1; i <= cnt; i++) putchar('8');
		putchar('\n');
	}
	return 0;
}
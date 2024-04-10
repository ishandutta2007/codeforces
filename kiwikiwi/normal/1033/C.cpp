#include <bits/stdc++.h>
using namespace std;

const int maxN = 123456;
int n, p[maxN], pos[maxN], dp[maxN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	for (int i = n; i >= 1; i--) {
		int x = pos[i];
		bool win = 0;
		for (int j = (x - 1) % i + 1; j <= n; j += i) {
			if (p[j] > i && dp[j] == 0) {
				win = 1;
				break;
			}
		}
		dp[x] = win;
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i]) putchar('A');
		else putchar('B');
	}
	puts("");
}
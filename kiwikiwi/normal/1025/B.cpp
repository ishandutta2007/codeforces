#include <bits/stdc++.h>
using namespace std;

int n, a[234567], b[234567];
bool check2(int p) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] % p == 0 || b[i] % p == 0) {
			cnt++;
		} else return 0;
	return 1;
}
void check(int x) {
	for (int p = 2; p * p <= x; p++) if (x % p == 0) {
			while (x % p == 0) {
				x /= p;
			}
			if (check2(p)) {
				printf("%d\n", p);
				exit(0);
			}
		}
	if (x != 1) {
		if (check2(x)) {
			printf("%d\n", x);
			exit(0);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	check(a[1]);
	check(b[1]);
	puts("-1");
}
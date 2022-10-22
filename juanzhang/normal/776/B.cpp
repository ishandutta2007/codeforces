#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool flag[maxn];
int n, ans[maxn];

int main() {
	scanf("%d", &n);
	flag[0] = flag[1] = 1;
	for (int i = 2; i * i <= n + 1; i++) {
		if (!flag[i]) {
			for (int j = i << 1; j <= n + 1; j += i) {
				flag[j] = 1;
			}
		}
	}
	puts(n < 3 ? "1" : "2");
	for (int i = 2; i <= n + 1; i++) {
		printf("%d ", flag[i] + 1);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, P = 998244353;
int n, len, a[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	int x = a[1];
	for (; x; x /= 10) len++;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = a[i], v = 1;
		for (; x; x /= 10) {
			int s = x % 10;
			ans = (ans + 1ll * s * v) % P;
			v = 10ll * v % P;
			ans = (ans + 1ll * s * v) % P;
			v = 10ll * v % P;
		}
	}
	printf("%d", 1ll * n * ans % P);
  return 0;
}
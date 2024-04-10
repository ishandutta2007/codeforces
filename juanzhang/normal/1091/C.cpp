#include <bits/stdc++.h>
using namespace std;

#prag\
ma GCC optimize(3)
typedef long long ll;
const int maxn = 1e5 + 10;
int n, tot; ll a[maxn];

void divide(int x) {
	if (n % x == 0) a[++tot] = n / x + 1ll * (n / x - 1) * (n / x) * x / 2;
}

int main() {
	scanf("%d", &n), a[++tot] = 1; 
	for (int i = 2, t = sqrt(n); i <= t; i++) {
		if (n % i == 0) divide(i), divide(n / i);
	}
	sort(a + 1, a + tot + 1);
	tot = unique(a + 1, a + tot + 1) - a - 1;
	for (int i = 1; i <= tot; i++) {
		printf("%I64d ", a[i]);
	}
	printf("%I64d", 1ll * n * (n + 1) / 2);
	return 0;
}
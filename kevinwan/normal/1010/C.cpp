#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	while (b)a %= b, a ^= b ^= a ^= b;
	return a + b;
}
int main() {
	int n, k,a,x,i;
	scanf("%d%d", &n, &k);
	a = k;
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		a = gcd(a, x);
	}
	printf("%d\n", k / a);
	for (i = 0; i < k; i += a)printf("%d ", i);
	getchar(); getchar();
}
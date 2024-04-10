#include <cstring>
#include <cstdio>

int ans, n, m;

void gcd(int a, int b, int t) {
	if(a == 1) {
		if(ans > t + b - 1) ans = t + b - 1;
	}
	if(b == 1) {
		if(ans > t + a - 1) ans = t + a - 1;
	}
	if(a == 0 || b == 0 || a == 1 || b == 1) return ;
	if(a < b) m = a, a = b, b = m;
	gcd(a % b, b, t + (a / b));
}

int main() {
	scanf("%d", &n);
	if(n == 1) return puts("0"), 0;
	ans = n;
	for(int i=n-1; i; i--) gcd(n, i, 0);
	printf("%d\n", ans);
	return 0;
}
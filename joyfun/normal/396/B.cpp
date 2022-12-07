#include <stdio.h>
#include <string.h>

const int MAXN = 100005;
int t;
__int64 n, l, r, prime[MAXN], vis[MAXN], pn = 0;

void init() {
	for (int i = 2; i <= 100000; i++) {
		if (vis[i]) continue;
		prime[pn++] = i;
		for (int j = i; j <= 100000; j += i)
			vis[j] = 1;
	}
}

bool judge(int x) {
	for (int i = 0; i < pn; i++) {
		if (x % prime[i] == 0 && x != prime[i])
			return false;
	}
	return true;
}

__int64 find_l(__int64 x) {
	while (1) {
		if (judge(x))
			return x;
		x--;
	}
}

__int64 find_r(__int64 x) {
	x++;
	while (1) {
		if (judge(x))
			return x;
		x++;
	}
}

__int64 gcd(__int64 a, __int64 b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
void print(__int64 l, __int64 r) {
	__int64 zi = (l - 2) * r + (n - l + 1) * 2, mu = l * r * 2;
	printf("%I64d/%I64d\n", zi / gcd(zi, mu), mu / gcd(zi, mu));
}

int main() {
	init();
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		l = find_l(n); r = find_r(n);
		print(l, r);
	}
	return 0;
}
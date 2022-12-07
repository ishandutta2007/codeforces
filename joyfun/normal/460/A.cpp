#include <cstdio>
#include <cstring>
#include <cstdlib>

int n, m;

int main() {
	int ans = 0;
	scanf("%d%d", &n, &m);
	while (n >= m) {
		ans += n - n % m;
		int num = n / m;
		n = n % m + num;
 	}
 	printf("%d\n", ans + n);
 	return 0;
}
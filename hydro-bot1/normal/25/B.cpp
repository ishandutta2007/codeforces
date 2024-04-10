// Hydro submission #62cd07524125dc528b1ce105@1657603922770
#include <cstdio>
int n, flag, a[107];
int main() {
	scanf("%d", &n);
	if(n & 1)	flag = 1;
	for(int i = 1; i <= n; ++i)
		scanf("%1d", &a[i]);
	for(int i = 1; i <= n; ++i) {
		printf("%d", a[i]);
		if(flag) {
			if(!(i & 1) && (i != n - 1))
				putchar('-');
		} else
			if(!(i & 1) && (i != n))
				putchar('-');
	}
	return 0;
}
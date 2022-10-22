#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	rep(i, n) {
		int a;
		scanf("%d", &a);
		sum += a;
	}
	if (sum % n == 0) puts("0");
	else puts("1");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}
#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (std::abs(a - b) % 2 != 0) printf("-1\n");
	else if (a == 0 && b == 0) printf("0\n");
	else if (a == b) printf("1\n");
	else if (a + b == 0) printf("1\n");
	else printf("2\n");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}
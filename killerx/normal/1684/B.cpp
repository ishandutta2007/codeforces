#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d %d %d\n", a + b + c, b + c, c);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}
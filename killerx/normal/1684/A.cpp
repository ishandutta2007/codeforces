#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	char s[20];
	scanf("%s", s);
	int n = (int) strlen(s);
	if (n == 2) printf("%c\n", s[1]);
	else {
		int mn = 10;
		rep(i, n) mn = std::min(mn, s[i] - '0');
		printf("%d\n", mn);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}
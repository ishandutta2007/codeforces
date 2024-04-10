#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 100005;
char s[maxn << 1];

int main() {
	int n = input() >> 1;
	scanf("%s", s + 1);

	int a = 0, b = 0, c = 0;
	for(int i = 1; i <= n; i ++)
		if(s[i] == '?')
			a ++;
		else
			c -= s[i] - '0';

	for(int i = n * 2; i > n; i --)
		if(s[i] == '?')
			b ++;
		else
			c += s[i] - '0';

	if(c * 2 == 9 * a - 9 * b)
		puts("Bicarp");
	else
		puts("Monocarp");
}
#if 0
2019.09.04
#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 200005;
char s[maxn];

int main() {
	int n = input();
	scanf("%s", s + 1);

	int tot = 0;
	bool move = false;

	for(int i = 1; i <= n; i ++)
		if(s[i] == '(')
			tot ++;
		else {
			if(not tot) {
				if(move) {
					puts("No");
					return 0;
				}
				move = true;
			} else
				tot --;
		}

	tot -= move;

	if(tot)
		puts("No");
	else
		puts("Yes");
}
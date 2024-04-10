#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 3030;
char s[maxn];

int main() {
	int T = read;
	while(T --) {
		int n = read;
		scanf("%s", s + 1);

		while(n and !(s[n] & 1))
			-- n;

		if(!n) {
			puts("-1");
			continue;
		}

		int o = 0;
		for(int i = 1; i <= n; i ++)
			o ^= s[i] & 1;

		if(!o) {
			s[n + 1] = 0;
			puts(s + 1);
			continue;
		}

		int del = 0;
		for(int i = 1; i < n; i ++)
			if(s[i] & 1)
				del = i;

		if(!del) {
			puts("-1");
			continue;
		}
		
		for(int i = 1; i <= n; i ++)
			if(s[i] != '0' and i != del)
				putchar(s[i]);
		puts("");
	}
}
#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 200005;
char s[maxn];
int tot[maxn][26];

int main() {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));
	for(int i = 1; i <= n; i ++) {
		for(int k = 0; k < 26; k ++)
			tot[i][k] = tot[i - 1][k];
		++ tot[i][s[i] - 'a'];
	}

	int q = read;
	while(q --) {
		int l = read, r = read;
		if(s[l] != s[r] or l == r) {
			puts("Yes");
			continue;
		}

		int now[26], typ = 0;
		for(int k = 0; k < 26; k ++) {
			now[k] = tot[r][k] - tot[l - 1][k];
			if(now[k]) ++ typ;
		}

		if(typ == 1) {
			puts("No");
			continue;
		}

		if(typ >= 3) {
			puts("Yes");
			continue;
		}

		puts("No");
	}
}
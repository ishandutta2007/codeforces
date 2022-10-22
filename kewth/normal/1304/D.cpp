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

const int maxn = 200005;
char s[maxn];
int a[maxn];

int main() {
	int t = read;
	while(t --) {
		int n = read;
		scanf("%s", s + 1);

		for(int l = 1, r, now = n; l <= n; l = r + 1) {
			r = l;
			while(s[r] == '<')
				++ r;
			for(int j = r; j >= l; j --)
				a[j] = now --;
		}

		for(int i = 1; i <= n; i ++)
			printf("%d ", a[i]);
		puts("");

		for(int l = 1, r, now = 0; l <= n; l = r + 1) {
			r = l;
			while(s[r] == '>')
				++ r;
			for(int j = r; j >= l; j --)
				a[j] = ++ now;
		}

		for(int i = 1; i <= n; i ++)
			printf("%d ", a[i]);
		puts("");
	}
}
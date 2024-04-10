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

int main() {
	int q = read;
	while(q --) {
		int a = read, b = read, c = read, ans = 0;
		if(a) -- a, ++ ans;
		if(b) -- b, ++ ans;
		if(c) -- c, ++ ans;

		if(a < b) std::swap(a, b);
		if(b < c) std::swap(b, c);
		if(a < b) std::swap(a, b);

		if(a and b) -- a, -- b, ++ ans;
		if(a and c) -- a, -- c, ++ ans;
		if(b and c) -- b, -- c, ++ ans;
		if(a and b and c) -- a, -- b, -- c, ++ ans;
		printf("%d\n", ans);
	}
}
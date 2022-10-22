#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 200005;
char s[maxn], t[maxn];

int main() {
	int n = read, k = read;
	scanf("%s", s + 1);
	printf("%d\n", n);

	for(int i = 1; i <= n; i ++)
		t[i] = i <= k ? s[i] : t[i - k];

	bool fail = 0;
	for(int i = 1; i <= n; i ++) {
		if(t[i] > s[i]) return puts(t + 1), 0;
		if(t[i] < s[i]) {
			fail = 1;
			break;
		}
	}

	if(!fail) return puts(t + 1), 0;

	++ t[k];
	for(int i = k; t[i] > '9'; i --) {
		t[i] = '0';
		++ t[i - 1];
	}

	for(int i = k + 1; i <= n; i ++)
		t[i] = t[i - k];
	puts(t + 1);
}
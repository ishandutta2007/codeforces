#if 0
2020.01.04
#endif
#include <cstdio>
#include <algorithm>
#include <string>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::string str;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator str () { char s[20]; return scanf("%s", s), str(s); }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 100;
str a[maxn], b[maxn];

int main() {
	int n = read, m = read;
	for(int i = 0; i < n; i ++)
		a[i] = str(read);
	for(int i = 0; i < m; i ++)
		b[i] = str(read);
	int q = read;
	while(q --) {
		int x = (read - 1);
		printf("%s\n", (a[x % n] + b[x % m]).c_str());
	}
}
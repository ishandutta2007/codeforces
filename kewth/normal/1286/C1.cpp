#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

const int maxn = 105, maxk = 26;
char s_cache[maxn];
struct str {
	int tot[maxk];
	int len() {
		int res = 0;
		for(int i = 0; i < maxk; i ++)
			res += tot[i];
		return res;
	}
	str() {
		for(int i = 0; i < maxk; i ++)
			tot[i] = 0;
	}
};
bool operator < (str a, str b) {
	for(int i = 0; i < maxk; i ++)
		if(a.tot[i] != b.tot[i])
			return a.tot[i] < b.tot[i];
	return 0;
}
str operator - (str a, str b) {
	for(int i = 0; i < maxk; i ++)
		a.tot[i] -= b.tot[i];
	return a;
}

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator str () {
		scanf("%s", s_cache);
		int len = int(strlen(s_cache));
		str x;
		for(int i = 0; i < len; i ++)
			++ x.tot[s_cache[i] - 'a'];
		return x;
	}
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

std::multiset<str> v[maxn];
char ans[maxn];

int main() {
	int n = read;
	printf("? %d %d\n", 1, n);
	fflush(stdout);

	for(int l = 1; l <= n; l ++) {
		for(int r = l; r <= n; r ++) {
			str now = read;
			v[now.len()].insert(now);
		}
	}

	if(n > 1) {
		printf("? %d %d\n", 2, n);
		fflush(stdout);
		for(int l = 2; l <= n; l ++) {
			for(int r = l; r <= n; r ++) {
				str now = read;
				int le = now.len();
				v[le].erase(v[le].find(now));
			}
		}
	}

	v[0].insert(str());
	for(int i = 1; i <= n; i ++) {
		str now = *v[i].begin() - *v[i - 1].begin();
		for(int k = 0; k < maxk; k ++)
			if(now.tot[k])
				ans[i] = char('a' + k);
	}

	printf("! %s\n", ans + 1);
	fflush(stdout);
}
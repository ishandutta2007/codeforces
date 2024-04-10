#if 0
2020.01.08

 [1, n]  [1, n - 1]  n 
 n 


 [1, n]  l 
 l 
 1, 2, 3 ... l ... l ... 3, 2, 1 
 l  l - 1  [l, n - l + 1] 
 [l, n - l + 1]  [1, mid] 
 [mid + 1, n - l + 1] 

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
str operator + (str a, str b) {
	for(int i = 0; i < maxk; i ++)
		a.tot[i] += b.tot[i];
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
str A[maxn], B[maxn];
char ans[maxn];

int main() {
	int n = read;
	int mid = (n + 1) >> 1;
	printf("? %d %d\n", 1, mid);
	fflush(stdout);

	for(int l = 1; l <= mid; l ++) {
		for(int r = l; r <= mid; r ++) {
			str now = read;
			v[now.len()].insert(now);
		}
	}

	if(mid > 1) {
		printf("? %d %d\n", 1, mid - 1);
		fflush(stdout);
		for(int l = 1; l < mid; l ++) {
			for(int r = l; r < mid; r ++) {
				str now = read;
				int le = now.len();
				v[le].erase(v[le].find(now));
			}
		}
	}

	for(int i = 1; i <= mid; i ++)
		A[i] = *v[i].begin();

	for(int i = 1; i <= mid; i ++) {
		for(int k = 0; k < maxk; k ++)
			if(A[i].tot[k] > A[i - 1].tot[k])
				ans[mid - i + 1] = char('a' + k);
	}

	if(n > 1) {
		printf("? %d %d\n", 1, n);
		fflush(stdout);

		for(int l = 1; l <= n; l ++)
			for(int r = l; r <= n; r ++) {
				str now = read;
				int le = now.len();
				B[le] = B[le] + now;
			}

		for(int i = n - mid; i; i --)
			B[i] = B[i] - B[i - 1];

		for(int i = 1; i <= n - mid; i ++)
			B[i] = B[i] - A[mid - i + 1];

/* 		for(int i = 1; i <= n - mid; i ++) { */
/* 			debug("B[%d]:", i); */
/* 			for(int k = 0; k < maxk; k ++) */
/* 				for(int j = 0; j < B[i].tot[k]; j ++) */
/* 					debug("%c", 'a' + k); */
/* 			debug("\n"); */
/* 		} */

		B[n - mid + 1] = B[0];

		for(int i = 1; i <= n - mid; i ++) {
			for(int k = 0; k < maxk; k ++)
				if(B[n - mid - i + 1].tot[k] > B[n - mid - i + 2].tot[k])
					ans[mid + i] = char('a' + k);
		}
	}

	printf("! %s\n", ans + 1);
	fflush(stdout);
}
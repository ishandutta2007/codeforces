#if 0
date +%Y.%m.%d


 a  b 
 0  0 
 2  x, y  k 


 x != y  1 
 x = y  x, y 
 k  a  b 
 x, y 
 2 

 x = y 
 2 


 0  0 
 p[0]  p[n + 1] 

 O(n) 

 n  100 
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

const int maxn = 105;
int p[maxn], tot[2];
int q[2][maxn];

int solve(int n) {
	int las = 0;
	int res = 0;
	for(int i = 1; i <= n + 1; i ++)
		if(p[i]) {
			if(p[i] == p[las])
				++ q[p[i] - 2][i - las - 1];
			else
				++ res;
			las = i;
		}

	for(int i = 0; i < 2; i ++) {
		int max = tot[i];
		for(int x = 0; x <= max; x ++) {
			while(q[i][x] and x <= max) {
				max -= x;
				-- q[i][x];
			}
		}
	}

	for(int i = 0; i <= n; i ++) {
		res += 2 * (q[0][i] + q[1][i]);
		q[0][i] = q[1][i] = 0;
	}

	return res;
}

int main() {
	int n = read;
	if(n == 1) return puts("0"), 0;

	tot[0] = n >> 1;
	tot[1] = (n + 1) >> 1;

	for(int i = 1; i <= n; i ++) {
		int x = read;
		if(x) {
			p[i] = 2 + (x & 1);
			-- tot[p[i] - 2];
		}
	}

	int ans = 1000000000;
	for(int i = 2; i <= 3; i ++)
		for(int j = 2; j <= 3; j ++) {
			p[0] = i;
			p[n + 1] = j;
			ans = std::min(ans, solve(n));
		}

	printf("%d\n", ans);
}
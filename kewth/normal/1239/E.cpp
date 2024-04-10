#if 0
2020.05.22

  
   i 
 A(i)  A(i) - A(i - 1)  A(i) - A(i - 1)
 A  A(1)  A(n) 
   DP  f[i][j][x]  i  j 
 x 
 i  f[i - 1][n - 1]  x 
f  bitset  O(n^3 a) 
        
          
        
            
           
        
          
   CopyRight :)
      
#endif
#include <cstdio>
#include <algorithm>
#include <bitset>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef size_t si;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 27, maxw = 1250005;
int a[maxn << 1];
std::bitset<maxw> f[maxn << 1][maxn];
bool mark[maxn << 1];

int main () {
	int n = read, N = n << 1;
	for (int i = 1; i <= N; i ++) read(a[i]);
	std::sort(a + 1, a + N + 1);

	int sum = 0, ans = 1000000000, pos = 0, k = 0;
	for (int i = 2; i <= N; i ++) sum += a[i];

	f[N + 1][0].set(0);
	for (int i = N; i > 2; i --) {
		f[i][0].set(0);
		for (int j = 1; j < n and j <= N - i + 1; j ++)
			f[i][j] = f[i + 1][j] | (f[i + 1][j - 1] << si(a[i]));
		for (int p = 0; p < maxw; p ++)
			if (f[i][n - 1].test(si(p))) {
				int q = sum - p - a[i - 1];
				int now = std::max(p, q) + a[i - 1] + a[1];
				if (now < ans) {
					ans = now;
					pos = i - 1;
					k = p;
				}
			}
	}

	/* debug("%d\n", ans); */

	mark[pos] = 1;
	for (int i = pos + 1, j = n - 1; i <= N; i ++) {
		/* assert(f[i][j].test(si(k))); */
		if (j and k >= a[i] and f[i + 1][j - 1].test(si(k - a[i]))) {
			mark[i] = 1;
			-- j;
			k -= a[i];
		}
	}

	for (int i = 1; i <= N; i ++)
		if (mark[i])
			printf("%d ", a[i]);
	puts("");
	for (int i = N; i; i --)
		if (!mark[i])
			printf("%d ", a[i]);
	puts("");
}
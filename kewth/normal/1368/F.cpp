/*
 * Author: Kewth

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Type "!!sh" in Vim.

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 1005;
bool mark[maxn], key[maxn];
int a[maxn];
int ar[maxn], ap;

int main () {
	int n = read;
	if (n <= 3) return puts("0"), 0;
	int K = -1, x = 0;
	for (int k = 1; k * 2 <= n; k ++) {
		int y = n - k - (n - 1) / k;
		if (y > x) K = k, x = y;
	}
	int min = (n - K) / K, p = n - (min + 1) * K;
	for (int i = 1, l = 0; i <= K; i ++) {
		++ l;
		for (int d = i <= p ? min + 1 : min; d; d --) key[++ l] = 1;
	}
	for (int k = 0; k < 10000; k ++) {
		ap = 0;
		for (int i = 1; i <= n; i ++)
			if (mark[i] != key[i])
				ar[++ ap] = i;
		printf("%d", ap);
		for (int i = 1; i <= ap; i ++)
			printf(" %d", ar[i]), mark[ar[i]] = 1;
		puts("");
		fflush(stdout);
		int s = read;
		for (int i = 0; i < ap; i ++) mark[s + i > n ? s + i - n : s + i] = 0;
		int tot = 0;
		for (int i = 1; i <= n; i ++) tot += mark[i];
		/* debug(" >>"); for (int i = 1; i <= n; i ++) debug("%d", mark[i]); debug(" %d\n", tot); */
	}
	puts("0");
}
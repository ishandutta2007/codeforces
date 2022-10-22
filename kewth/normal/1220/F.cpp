#if 0
date +%Y.%m.%d

   n 
  

 [l, r]  l - 1 
  

        
          
        
            
           
        
          
   CopyRight :)
      
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 400005;
int a[maxn];
int tol[maxn], tor[maxn];
int stack[maxn], sp;
int seg[maxn << 2], tag[maxn << 2];
#define ls (now << 1)
#define rs (now << 1 | 1)

void add (int now, int L, int R, int l, int r, int x) {
	if (r < L or l > R) return;
	if (l <= L and R <= r) return seg[now] += x, tag[now] += x, void();
	int M = (L + R) >> 1;
	add(ls, L, M, l, r, x);
	add(rs, M + 1, R, l, r, x);
	seg[now] = std::max(seg[ls], seg[rs]) + tag[now];
}

int query (int now, int L, int R, int p) {
	if (p == 0) return 0;
	if (L == R) return seg[now];
	int M = (L + R) >> 1;
	if (p <= M) return query(ls, L, M, p) + tag[now];
	else return query(rs, M + 1, R, p) + tag[now];
}

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++)
		a[i + n] = a[i] = read;
	int N = n * 2;

	for (int i = 1; i <= N; i ++) {
		while (sp and a[stack[sp]] > a[i])
			-- sp;
		tol[i] = stack[sp];
		stack[++ sp] = i;
	}
	sp = 0;
	for (int i = N; i; i --) {
		while (sp and a[stack[sp]] > a[i])
			-- sp;
		tor[i] = stack[sp];
		stack[++ sp] = i;
	}

	int ans = 100000000, shift = 0;
	for (int r = 1; r < N; r ++) {
		int l = r - n + 1;
		if (l > 1) {
			/* debug("shit %d -> %d\n", l - 1, tor[l - 1]); */
			add(1, 1, N, l - 1, l - 1, -query(1, 1, N, tor[l - 1]) - 1);
			add(1, 1, N, l, tor[l - 1] - 1, -1);
		}
		add(1, 1, N, tol[r] + 1, r - 1, 1);
		add(1, 1, N, r, r, query(1, 1, N, tol[r]) + 1);
		if (l >= 1 and seg[1] < ans) {
			ans = seg[1];
			shift = l - 1;
		}
		/* debug("%d - %d : %d\n", l, r, seg[1]); */
		/* for (int i = 1; i <= N; i ++) */
		/* 	debug(" %d", query(1, 1, N, i)); */
		/* debug("\n"); */
	}

	printf("%d %d\n", ans, shift);
}
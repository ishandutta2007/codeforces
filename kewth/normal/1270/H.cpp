/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
    2020.06.11

 * Solution:
    



     x 
 x  x  >= x 
 1  0  1  0 
     x  f(x)  1  0  f(x) 
 f(x) >= 1 x  f(x) = 1  x 
 x  f(x) = INF  f 
 f  O(1) 

 * Digression:
    

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 500005;
int a[maxn], b[maxn << 2];
int min[maxn << 3], tot[maxn << 3], tag[maxn << 3];
#define ls (now << 1)
#define rs (now << 1 | 1)

inline void modi (int now, int x) { min[now] += x; tag[now] += x; }

void push (int now) {
	if (tag[now]) {
		modi(ls, tag[now]);
		modi(rs, tag[now]);
		tag[now] = 0;
	}
}

void update (int now) {
	min[now] = std::min(min[ls], min[rs]);
	tot[now] = 0;
	if (min[ls] == min[now]) tot[now] += tot[ls];
	if (min[rs] == min[now]) tot[now] += tot[rs];
}

void modify (int now, int L, int R, int l, int r, int x) {
	if (r < L or l > R) return;
	if (l <= L and R <= r) return modi(now, x);
	push(now);
	int M = (L + R) >> 1;
	modify(ls, L, M, l, r, x);
	modify(rs, M + 1, R, l, r, x);
	update(now);
}

void build (int now, int L, int R) {
	if (L == R) {
		min[now] = !b[L];
		tot[now] = 1;
		return;
	}
	int M = (L + R) >> 1;
	build(ls, L, M);
	build(rs, M + 1, R);
	update(now);
}

int main () {
	int n = read, q = read;
	int L = 1, R = 1000001;
	a[0] = R - 1;
	a[n + 1] = L - 1;
	for (int i = 1; i <= n; i ++)
		++ b[a[i] = read];
	build(1, L, R);

	modify(1, L, R, a[1] + 1, R, 1);
	for (int i = 1; i <= n; i ++)
		if (a[i] > a[i + 1])
			modify(1, L, R, a[i + 1] + 1, a[i], 1);

	while (q --) {
		int p = read, x = read;
		if (a[p - 1] > a[p])
			modify(1, L, R, a[p] + 1, a[p - 1], -1);
		if (a[p] > a[p + 1])
			modify(1, L, R, a[p + 1] + 1, a[p], -1);
		if (-- b[a[p]] == 0)
			modify(1, L, R, a[p], a[p], 1);
		a[p] = x;
		if (++ b[a[p]] == 1)
			modify(1, L, R, a[p], a[p], -1);
		if (a[p - 1] > a[p])
			modify(1, L, R, a[p] + 1, a[p - 1], 1);
		if (a[p] > a[p + 1])
			modify(1, L, R, a[p + 1] + 1, a[p], 1);
		printf("%d\n", tot[1]);
	}
}
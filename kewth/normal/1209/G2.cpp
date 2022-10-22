/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  2020.06.16

 * Solution:
 * 

     w  S[w] l = min(S[w]), r = max(S[w]) 
 [l, r] 
 n 

     {a} a[i] = 1 
 i  i + 1  w  {a} 
 {a}  {a} 
 {a} 

    
 {b}  w  x in S[w]  b[x] = |S[w]| 
 {b}  w  b 
b[min(S[w])] = |S[w]| 

     {a}  {b} 
 {a}  0  {b} 

 O(1) 

 * Digression:
  

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 200005;
std::set<int> pos[maxn];
int min[maxn << 2], tot[maxn << 2], tag[maxn << 2];
int ans[maxn << 2], lv[maxn << 2], rv[maxn << 2], nv[maxn << 2];
#define ls (now << 1)
#define rs (now << 1 | 1)

void modi (int now, int x) {
	min[now] += x;
	tag[now] += x;
}

void push (int now) {
	if (tag[now]) {
		modi(ls, tag[now]);
		modi(rs, tag[now]);
		tag[now] = 0;
	}
}

void update (int now) {
	min[now] = std::min(min[ls], min[rs]);
	nv[now] = std::max(nv[ls], nv[rs]);
	if (min[ls] == min[rs]) {
		tot[now] = tot[ls] + tot[rs];
		ans[now] = ans[ls] + ans[rs] - rv[ls] - lv[rs] + std::max(rv[ls], lv[rs]);
		lv[now] = lv[ls];
		rv[now] = rv[rs];
	}
	if (min[ls] < min[rs]) {
		tot[now] = tot[ls];
		ans[now] = ans[ls] - rv[ls] + std::max(rv[ls], nv[rs]);
		lv[now] = lv[ls];
		rv[now] = std::max(rv[ls], nv[rs]);
	}
	if (min[ls] > min[rs]) {
		tot[now] = tot[rs];
		ans[now] = ans[rs] - lv[rs] + std::max(lv[rs], nv[ls]);
		lv[now] = std::max(lv[rs], nv[ls]);
		rv[now] = rv[rs];
	}
}

void modify (int now, int L, int R, int l, int r, int x) {
	if (r < L or l > R) return;
	if (l <= L and R <= r) return modi(now, x);
	int M = (L + R) >> 1;
	push(now);
	modify(ls, L, M, l, r, x);
	modify(rs, M + 1, R, l, r, x);
	update(now);
}

void modify2 (int now, int L, int R, int p, int x) {
	if (L == R) {
		ans[now] = lv[now] = nv[now] = x;
		return;
	}
	int M = (L + R) >> 1;
	push(now);
	if (p <= M) modify2(ls, L, M, p, x);
	else modify2(rs, M + 1, R, p, x);
	update(now);
}

void print (int now, int L, int R) {
	debug("%d - %d : l=%d r=%d n=%d a=%d\n",
			L, R, lv[now], rv[now], nv[now], ans[now]);
	if (L == R) return;
	int M = (L + R) >> 1;
	print(ls, L, M);
	print(rs, M + 1, R);
}

void build (int now, int L, int R) {
	tot[now] = R - L + 1;
	if (L == R) return;
	int M = (L + R) >> 1;
	build(ls, L, M);
	build(rs, M + 1, R);
}

int a[maxn];
void update (int w, int n, int x) {
	if (pos[w].empty()) return;
	int l = *pos[w].begin(), r = *pos[w].rbegin();
	if (l < r)
		modify(1, 1, n, l, r - 1, x);
	if (x == -1)
		modify2(1, 1, n, l, 0);
	if (x == 1)
		modify2(1, 1, n, l, int(pos[w].size()));
}

int main () {
	int n = read, q = read;
	for (int i = 1; i <= n; i ++)
		pos[a[i] = read].insert(i);
	build(1, 1, n);
	for (int w = 1; w <= 200000; w ++)
		update(w, n, 1);
	printf("%d\n", n - ans[1]);
	while (q --) {
		int p = read, w = read;
		update(a[p], n, -1);
		update(w, n, -1);
		pos[a[p]].erase(p);
		pos[w].insert(p);
		update(a[p], n, 1);
		update(w, n, 1);
		a[p] = w;
		printf("%d\n", n - ans[1]);
	}
	/* print(1, 1, n); */
}
/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  2020.06.04

 * Solution:
     x  O  x  x 
 O 

     P  P 
 P 
 n  m 

     [l, r] 
 [l + 2PI, r + 2PI]  2n 
 n 

     m 
 f[0][i]  i 
 f[k][i]  m  n 


 * Digression:
  

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005;
struct Shit {
	double l, r;
	int i;
} shit[maxn << 1];
int px[maxn], py[maxn];
double pd[maxn], pa[maxn];
double pi = acos(-1);
bool mark[maxn];
int f[20][maxn];

bool operator < (Shit a, Shit b) { return a.l < b.l; }

bool check (int n, int m, double r) {
	for (int i = 1; i <= n; i ++) {
		double dt = acos(r / pd[i]);
		shit[i] = {pa[i] - dt, pa[i] + dt, i};
	}
	for (int i = 1; i <= n; i ++)
		shit[n + i] = {shit[i].l + pi * 2, shit[i].r + pi * 2, shit[i].i};
	std::sort(shit + 1, shit + n * 2 + 1);

	std::fill(mark, mark + n + 1, 0);
	double max = 1e100;
	for (int i = n * 2; i; i --)
		if (shit[i].r > max)
			mark[shit[i].i] = 1;
		else
			max = shit[i].r;

	int p = 0;
	for (int i = 1; i <= n; i ++)
		if (!mark[i]) {
			double dt = acos(r / pd[i]);
			shit[++ p] = {pa[i] - dt, pa[i] + dt, i};
		}
	for (int i = 1; i <= p; i ++)
		shit[p + i] = {shit[i].l + pi * 2, shit[i].r + pi * 2, shit[i].i};
	std::sort(shit + 1, shit + p * 2 + 1);

	for (int i = 1, j = 1; i <= p * 2; i ++) {
		while (j <= p * 2 and shit[j].l <= shit[i].r)
			++ j;
		f[0][i] = j;
	}

	for (int k = 0; k < 20; k ++)
		f[k][p * 2 + 1] = p * 2 + 1;
	for (int k = 1; k < 20; k ++)
		for (int i = 1; i <= p * 2; i ++)
			f[k][i] = f[k - 1][f[k - 1][i]];

	for (int i = 1; i <= p; i ++) {
		int j = i;
		for (int k = 0; k < 20; k ++)
			if (m >> k & 1)
				j = f[k][j];
		if (j >= i + p)
			return 1;
	}
	return 0;
}

int main () {
	int n = read, m = read;
	double l = 0, r = 1e100;
	for (int i = 1; i <= n; i ++) {
		read(px[i], py[i]);
		pd[i] = sqrt(1ll * px[i] * px[i] + 1ll * py[i] * py[i]);
		r = std::min(r, pd[i]);
		pa[i] = atan2(py[i], px[i]);
	}

	for (int k = 0; k < 64; k ++) {
		double mid = (l + r) / 2;
		if (check(n, m, mid))
			l = mid;
		else
			r = mid;
	}

	printf("%.8lf\n", l);
}
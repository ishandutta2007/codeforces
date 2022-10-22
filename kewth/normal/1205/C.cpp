/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  2020.06.16

 * Solution:
   2

 a[1][2] = 0  n^2 - 3
 3 

   i  a[i][i] = 1  a[i + 2][i + 2] = 0  3x3
 n = 3  n = 3 


   3x3 

    1 a b
	c d e
	f g 0

   b != d  a != c  (1, e)  e  d != f
 e != g  (c, 0)  c 

    1 x z
	x z y
	z y 0

   (1, y)  (x, 0)  1 
y  x  1xzy  xzy0 

    (x != z || y != 1) && (x != 0 || y != z)

   z  x  y 

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

const int maxn = 55;
int a[maxn][maxn];

int query (int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	return read;
}

bool check (int n) {
	for (int i = 3; i <= n; i ++)
		if (a[i][i] == 0 and a[i - 2][i - 2] == 1) {
			auto A = [i] (int x, int y) {
				return a[i - 3 + x][i - 3 + y];
			};
			auto q = [i] (int x1, int y1, int x2, int y2) {
				return query(i - 3 + x1, i - 3 + y1,
						i - 3 + x2, i - 3 + y2);
			};
			if (A(1, 2) != A(2, 1) or A(1, 3) != A(2, 2))
				return (A(1, 1) ^ q(1, 1, 2, 3) ^ 1) == A(2, 3);
			if (A(2, 2) != A(3, 1) or A(2, 3) != A(3, 2))
				return (A(3, 3) ^ q(2, 1, 3, 3) ^ 1) == A(2, 1);
			int x = q(1, 1, 2, 3), y = q(2, 1, 3, 3);
			if (x) return A(1, 1) == A(2, 3);
			if (y) return A(2, 1) == A(3, 3);
			if (A(2, 2) == 0) return A(1, 2) == 1;
			else return A(2, 3) == 0;
		}
	return 1; // impossible
}

int main () {
	int n = read;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		a[i][j] = -1;

	a[1][1] = 1;
	a[n][n] = 0;

	a[1][2] = 0; // a guess
	a[2][3] = a[1][2] ^ query(1, 2, 2, 3) ^ 1;
	a[2][1] = a[2][3] ^ query(2, 1, 2, 3) ^ 1;

	for (int j = 3; j <= n; j ++)
		a[1][j] = a[1][j - 2] ^ query(1, j - 2, 1, j) ^ 1;
	for (int i = 3; i <= n; i ++)
		a[i][1] = a[i - 2][1] ^ query(i - 2, 1, i, 1) ^ 1;
	for (int i = 2; i <= n; i ++)
		for (int j = 2; j <= n; j ++)
			if (a[i][j] == -1)
			a[i][j] = a[i - 1][j - 1] ^ query(i - 1, j - 1, i, j) ^ 1;

	if (!check(n))
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if ((i & 1) != (j & 1))
					a[i][j] ^= 1;

	puts("!");
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			putchar('0' + a[i][j]);
		puts("");
	}
	fflush(stdout);
}
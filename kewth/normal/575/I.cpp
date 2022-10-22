#if 0
date +%Y.%m.%d

(cf575i)

 x + y = A  y - x = A 
 x + y <= A  y - x <= A 


#endif
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct _{
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 5005, maxq = 100005;
int bit[maxn << 1][maxn];

int n;
void modify(int p, int l, int r, int x) {
	if(p < 0 or l < 0 or r < 0)
		exit(1);
	for(int i = p; i; i -= i & -i) {
		for(int j = r; j; j -= j & -j)
			bit[i][j] += x;
		for(int j = l - 1; j; j -= j & -j)
			bit[i][j] -= x;
	}
}

int query(int p, int ip) {
	if(p <= 0 or ip <= 0)
		exit(1);
	int res = 0;
	for(int i = p; i <= (n << 1); i += i & -i)
		for(int j = ip; j <= n; j += j & -j)
			res += bit[i][j];
	return res;
}

int qo[maxq], qx[maxq], qy[maxq], qd[maxq], ql[maxq];
int ans[maxq];

int main() {
#define O qo[i]
#define X qx[i]
#define Y qy[i]
#define D qd[i]
#define L ql[i]

	read(n);
	int q = read;
	for(int i = 1; i <= q; i ++) {
		read(O);
		if(O == 1) D = read; 
		read(X);
		read(Y);
		if(O == 1) L = read; 
	}

	for(int i = 1; i <= q; i ++)
		if(O == 1) {
			if(D == 1) modify(Y - 1, X, X + L, -1);
			if(D == 2) modify(Y, X, X + L, 1);
			if(D == 3) modify(Y - 1, X - L, X, -1);
			if(D == 4) modify(Y, X - L, X, 1);
		} else
			ans[i] += query(Y, X);

	memset(bit, 0, sizeof bit);
	for(int i = 1; i <= q; i ++)
		if(O == 1) {
			if(D == 1) modify(X + Y + L, X, X + L, 1);
			if(D == 4) modify(X + Y - L - 1, X - L, X, -1);
		} else
			ans[i] += query(X + Y, X);

	memset(bit, 0, sizeof bit);
	for(int i = 1; i <= q; i ++)
		if(O == 1) {
			if(D == 2) modify(Y - L + n - X - 1, X, X + L, -1);
			if(D == 3) modify(Y + L + n - X, X - L, X, 1);
		} else
			ans[i] += query(Y + n - X, X);

	for(int i = 1; i <= q; i ++)
		if(O == 2)
			printf("%d\n", ans[i]);
}
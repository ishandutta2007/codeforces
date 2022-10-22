#if 0
2020.01.05

 5  5-set 
1)  5-set 
2)  5-set 
3) l 5-set 
 5-set  x5, x4, x3  x4 + 2 x3 

 x4, x3 

 X = x5 + x4 + x3 = C(n, 5)  Y = 5 x5 + 4 x4 + 3 x3 
 ans = 5X - Y  Y 
 Y  5-set 
 E  5-set  E 
 3-set  E  E  k 
 C(k, 3) 
 x  x 
 O(n^2logn) 

dnmd  atan2  double  long double 

#endif
#include <cstdio>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 2505;
int x[maxn], y[maxn];
struct Vec {
	int x, y;
	Vec r() { return Vec({-x, -y}); }
};
Vec v[maxn << 1];

ll cross(Vec a, Vec b) {
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

inline ll C(ll n, int m) {
	ll res = 1;
	for(int i = 0; i < m; i ++) (res *= n - i) /= i + 1;
	return res;
}

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		read(x[i], y[i]);

	ll X = C(n, 5), Y = 0;
	for(int i = 1; i <= n; i ++) {
		int vp = 0;
		for(int j = 1; j <= n; j ++)
			if(j != i)
				v[++ vp] = Vec({x[j] - x[i], y[j] - y[i]});
		std::sort(v + 1, v + vp + 1, [](Vec a, Vec b) {
					int ain = a.y < 0 or (a.x > 0 and a.y == 0);
					int bin = b.y < 0 or (b.x > 0 and b.y == 0);
					if(ain != bin) return ain < bin;
					return cross(a, b) > 0;
				});

		for(int j = 1; j <= vp; j ++)
			v[vp + j] = v[j];

		int las = 1;
		for(int j = vp + 1; j <= (vp << 1); j ++) {
			while(las + vp <= j or cross(v[j], v[las]) > 0) ++ las;
			Y += C(j - las, 3);
		}
	}

	printf("%lld\n", X * 5 - Y);
}
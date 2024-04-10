#if 0
date


 (x, y, z)  (a, b, c, d) 
a = x + y + z
b = x + y - z
c = x - y + z
d = - x + y + z


 x  p  x 
 P  x 
 P 
 P 
 P  p 
 a = b + c + d  a  b, c, d 
 b, c, d  p 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 100005;
const ll lim = 3000000000000000000;
ll pos[4][maxn];

ll L[4], R[4];
ll get[4];
bool check(ll r, int n) {
	// debug("check %lld\n", r);
	for(int k = 0; k < 4; k ++) {
		L[k] = - lim * 2;
		R[k] = lim * 2;
		for(int i = 1; i <= n; i ++) {
			L[k] = std::max(L[k], pos[k][i] - r);
			R[k] = std::min(R[k], pos[k][i] + r);
		}
	}

	for(int o = 0; o < 2; o ++) {
		ll Lo[4], Ro[4];
		for(int k = 0; k < 4; k ++) {
			Lo[k] = (L[k] & 1) == o ? L[k] : L[k] + 1;
			Ro[k] = (R[k] & 1) == o ? R[k] : R[k] - 1;
			if(Lo[k] > Ro[k]) goto FAIL;
			get[k] = Lo[k];
		}
#define sum (get[1] + get[2] + get[3])
		if(sum > Ro[0]) goto FAIL;
		// XXX: ??????  1  3  WA ???????
		// for(int k = 3; k; k --)
		for(int k = 1; k <= 3; k ++)
			if(sum < Lo[0]) {
				if(sum - get[k] + Ro[k] <= Lo[0])
					get[k] = Ro[k];
				else
					get[k] = Lo[0] + get[k] - sum;
			}
		if(sum < Lo[0]) goto FAIL;
#undef sum
		// debug("get %lld %lld %lld\n", get[1], get[2], get[3]);
		return 1;
FAIL:;
	}

	return 0;
}

int main() {
	int T = read;
	while(T --) {
		int n = read;
		for(int i = 1; i <= n; i ++) {
			ll x = read, y = read, z = read;
			pos[0][i] = x + y + z;
			pos[1][i] = x + y - z;
			pos[2][i] = x - y + z;
			// pos[3][i] = x - y - z;
			pos[3][i] = - x + y + z;
		}

		ll l = 0, r = lim;
		while(l < r) {
			ll mid = (l + r) >> 1;
			if(check(mid, n))
				r = mid;
			else
				l = mid + 1;
		}

		check(l, n);

		ll x, y, z;
		printf("%lld %lld %lld\n",
				x = (get[1] + get[2]) >> 1,
				y = (get[1] + get[3]) >> 1,
				z = (get[2] + get[3]) >> 1);

#if 0
		debug("%lld\n", l);
		for(int k = 0; k < 4; k ++)
			debug("%lld ~ %lld\n", L[k], R[k]);
		debug("%lld %lld %lld %lld\n",
				x + y + z,
				x + y - z,
				x - y + z,
				- x + y + z);
		debug("%lld %lld %lld %lld\n",
				x + y + z, get[1], get[2], get[3]);
#endif
	}
}
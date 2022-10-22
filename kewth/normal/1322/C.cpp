#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef unsigned long long ull;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 500005;
#if 0
struct Hash_Set {
	ull a, b;
	void set() {
		int X = (1 << 8) - 1;
		a = b = 0;
		for(int k = 0; k < 64; k += 8)
			a ^= ull(rand() & X) << k;
		for(int k = 0; k < 64; k += 8)
			b ^= ull(rand() & X) << k;
	}
	void merge(Hash_Set x) {
		a ^= x.a;
		b ^= x.b;
	}
	Hash_Set(): a(0), b(0) { }
};
bool operator < (Hash_Set x, Hash_Set y) {
	return x.a == y.a ? x.b < y.b : x.a < y.a;
}
#else
struct Hash_Set {
	ull a;
	void set() {
		int X = (1 << 8) - 1;
		a = 0;
		for(int k = 0; k < 64; k += 8)
			a ^= ull(rand() & X) << k;
	}
	void merge(Hash_Set x) {
		a ^= x.a;
	}
	Hash_Set(): a(0) { }
};
bool operator < (Hash_Set x, Hash_Set y) {
	return x.a < y.a;
}
#endif

Hash_Set h[maxn], s[maxn];
ll c[maxn];
bool shit[maxn];
std::map<Hash_Set, ll> sum;

ll gcd(ll a, ll b) {
	if(!b) return a;
	return gcd(b, a % b);
}

int main() {
	srand(19491001);

	int T = read;
	while(T --) {
		int n = read, m = read;
		for(int i = 1; i <= n; i ++) {
			h[i].set();
			s[i] = Hash_Set();
			c[i] = read;
			shit[i] = 0;
		}

		while(m --) {
			int x = read, y = read;
			shit[y] = 1;
			s[y].merge(h[x]);
		}

		sum.clear();
		for(int i = 1; i <= n; i ++)
			if(shit[i])
				sum[s[i]] += c[i];

		ll ans = 0;
		for(auto p : sum)
			ans = gcd(ans, p.second);
		printf("%lld\n", ans);
	}
}
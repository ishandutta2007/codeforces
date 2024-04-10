#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 200005;
char s[maxn];
int pre[maxn];

int A, B, C;
struct Hash {
	ll a, b, c;
	Hash(ll x = 0): a(x), b(x), c(x) { }
};

Hash operator * (Hash x, Hash y) {
	(x.a *= y.a) %= A;
	(x.b *= y.b) %= B;
	(x.c *= y.c) %= C;
	return x;
}

Hash operator + (Hash x, Hash y) {
	(x.a += y.a) %= A;
	(x.b += y.b) %= B;
	(x.c += y.c) %= C;
	return x;
}

Hash operator - (Hash x, Hash y) {
	(x.a += A - y.a) %= A;
	(x.b += B - y.b) %= B;
	(x.c += C - y.c) %= C;
	return x;
}

bool operator == (Hash x, Hash y) {
	return x.a == y.a and x.b == y.b and x.c == y.c;
}

Hash ph1[maxn], ph2[maxn], po[maxn], base = 233;

int main() {
	srand(19491001);
	A = 1 + rand(), B = 1 + rand(), C = 1 + rand();

	int n = read;
	scanf("%s", s + 1);

	for(int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + (s[i] == '0');

	for(int i = 1; i <= n; i ++)
		if(s[i] == '0') {
			ph1[i] = ph1[i - 1] * base + (1 + (i & 1));
			ph2[i] = ph2[i - 1] * base + (1 + !(i & 1));
		} else {
			ph1[i] = ph1[i - 1];
			ph2[i] = ph2[i - 1];
		}

	// for(int i = 1; i <= n; i ++)
		// debug("%lld %lld\n", ph1[i].a, ph2[i].a);

	po[0] = 1;
	for(int i = 1; i <= n; i ++)
		po[i] = po[i - 1] * base;

	int q = read;
	while(q --) {
		int l1 = read, l2 = read, k = read;
		int r1 = l1 + k - 1, r2 = l2 + k - 1;
		Hash a = l1 & 1 ?
			ph1[r1] - ph1[l1 - 1] * po[pre[r1] - pre[l1 - 1]] :
			ph2[r1] - ph2[l1 - 1] * po[pre[r1] - pre[l1 - 1]];
		Hash b = l2 & 1 ?
			ph1[r2] - ph1[l2 - 1] * po[pre[r2] - pre[l2 - 1]] :
			ph2[r2] - ph2[l2 - 1] * po[pre[r2] - pre[l2 - 1]];
		// debug("%d %d %d %d\n", l1, r1, l2, r2);
		// debug("%lld %lld\n", a.a, b.a);
		if(a == b)
			puts("Yes");
		else
			puts("No");
	}
}
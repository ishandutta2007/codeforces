#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;

	lint gcd(lint x, lint y) { return y ? gcd(y, x%y) : x; }
	lint mod(lint a, lint b) { return ((a%b) + b) % b; }

	// returns g = gcd(a, b); finds x, y such that g = ax + by
	lint ext_gcd(lint a, lint b, lint &x, lint &y) {
		lint xx = y = 0;
		lint yy = x = 1;
		while (b) {
			lint q = a / b;
			lint t = b; b = a%b; a = t;
			t = xx; xx = x - q*xx; x = t;
			t = yy; yy = y - q*yy; y = t;
		}
		return a;
	}

	// computes b such that ab = 1 (mod n), returns -1 on failure
	lint mod_inverse(lint a, lint n) {
		lint x, y;
		lint g = ext_gcd(a, n, x, y);
		if (g > 1) return -1;
		return mod(x, n);
	}

	// Chinese remainder theorem: find z such that
	// z % m1 = r1, z % m2 = r2.  Here, z is unique modulo M = lcm(m1, m2).
	// Return (z, M).  On failure, M = -1.
	pair<lint, lint> CRT(lint m1, lint r1, lint m2, lint r2) {
		lint s, t;
		lint g = ext_gcd(m1, m2, s, t);
		if (r1%g != r2%g) return make_pair(0, -1);
		s = mod(s * r2, m2);
		t = mod(t * r1, m1);
		return make_pair(mod(s*(m1/g) + t*(m2/g), m1*(m2/g)), m1*(m2/g));
	}
int n;
lint a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	printf("1 1\n%lld\n", -a[1]);
	a[1] = 0;
	if(n == 1){
		puts("1 1\n0\n1 1\n0");
		return 0;
	}
	printf("2 %d\n", n);
	for(int i=2; i<=n; i++){
		lint qq = CRT(n - 1, 0, n, mod(-a[i], n)).first;
		printf("%lld ", qq);
		a[i] += qq;
	}
	printf("\n1 %d\n", n);
	for(int i=1; i<=n; i++) printf("%lld ", -a[i]);
}
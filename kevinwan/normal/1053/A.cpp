#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(ll a, ll b) {
	while (b)a %= b, a ^= b ^= a ^= b;
	return a;
}
int main() {
	ll n, m, k;
	scanf("%lld%lld%lld", &n, &m, &k);
	ll on = n, om = m,g;
	g = gcd(n, k), n /= g, k /= g;
	g = gcd(m, k), m /= g, k /= g;
	if (k > 2) { printf("NO"); return 0; }
	if (k == 1) {
		if (n * 2 <= on)n *= 2;
		else if (m * 2 <= om)m *= 2;
		else { printf("NO"); return 0; }
	}
	printf("YES\n0 0\n%lld 0\n0 %lld", n, m);
	getchar(); getchar();
}
// Code by Denverjin.
#include <bits/stdc++.h>
using namespace std;

using ld = double;
using ll = long long;
using ull = unsigned long long;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

int main() {
	ll n = read(), b = read();
	vector <ll> p, e;
	int o = b;
	for (ll i = 2; i * i <= b; ++ i) {
		if (b % i == 0) {
			p.push_back(i);
			e.push_back(0);
			while (b % i == 0) {
				++ e.back();
				b /= i;
			}
		}
	}
	if (b > 1) {
		p.push_back(b);
		e.push_back(1);
	}
	ll ans = LINF;
	for (int i = 0; i < (int) p.size(); ++ i) {
		ll B = 1;
		ll cnt = 0;
		while (B <= n / p[i]) {
			B *= p[i];
			cnt += n / B;
		}
		ans = min(ans, cnt / e[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
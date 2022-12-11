#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int P = 998244353;
ll d, a, b, n;
map<ll, int> mp;
ll y[500], cnt;
ll tmp[50], jie[500], inv[500];

inline ll C(ll n, ll m) {
	return jie[n] * inv[n-m] % P * inv[m] % P;
}

int main() {
	read(d), read(n); if (d % 2 == 0) y[++cnt] = 2;
	while (d % 2 == 0) d /= 2;
	for (ll i = 3;i * i <= d; i += 2) {
		if (d % i) continue;
		y[++cnt] = i;
		while (d % i == 0) d /= i;
	}
	if (d != 1) y[++cnt] = d;
	jie[0] = 1; for (int i = 1;i <= 100; i++) jie[i] = jie[i-1] * i % P;
	inv[0] = inv[1] = 1;
	for (int i = 2;i <= 100; i++) inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2;i <= 100; i++) inv[i] = inv[i-1] * inv[i] % P;
	while (n--) {
		read(a), read(b);
		ll aa = 0, bb = 0, s1 = 1;
		for (int i = 1;i <= cnt; i++) {
			int ta = 0, tb = 0;
			while (a % y[i] == 0) a /= y[i], ta++;
			while (b % y[i] == 0) b /= y[i], tb++;
			int tt = max(ta, tb); 
			aa += tt - ta, bb += tt - tb;
			s1 = (s1 * C(aa, tt - ta) % P * C(bb, tt - tb)) % P;
		}
		printf ("%lld\n", s1 % P);
	}
	return 0;
}
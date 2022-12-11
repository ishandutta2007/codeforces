#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
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
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int P = 998244353;
ll fpw(ll x, ll mi) {
	x %= P; mi %= (P - 1);
	if (x == 0) return 0;
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P; mi >>= 1;
	} return res;
}

ll L, R, n, m;
int main() {
	read(n), read(m), read(L), read(R);
	ll ou = (R >> 1) - ((L - 1) >> 1);
	ll ji = R - L + 1 - ou;
	if (n * m & 1) return printf ("%lld\n", fpw(R - L + 1, n * m)), 0;
	ll ans = fpw(ji + ou, n * m);
	if (ji > ou) ans += fpw(ji - ou, n * m);
	else ans += fpw(ou - ji, n * m);
	(ans *= (P + 1) / 2) %= P;
	ans = (ans + P) % P;
	cout << ans << endl;
	return 0;
}
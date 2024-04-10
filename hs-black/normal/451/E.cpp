#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define to(x) (1 << (x))
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

const int N = 22;
ll n, s, f[N];

const int P = 1e9+7;
ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P;
		mi >>= 1;
	}
	return res;
}

ll C(ll n, ll m) {
	ll inv = 1, a = 1;
	for (ll i = 0; i < m; i++) {
		a = a * ((n - i) % P) % P;
		inv = inv * (i + 1) % P;
	}
	return a * fpw(inv, P - 2) % P;
}

int main() {
	read(n), read(s);
	for (int i = 1;i <= n; i++) read(f[i]);
	
	if (n == 1) {
		if (s <= f[1]) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	
	int all = to(n) - 1;
	ll ans = 0;
	for (int i = 0;i <= all; i++) {
		ll res = n + s - 1, siz = 0;
		for (int j = 1;j <= n; j++) 
			if (to(j-1) & i) res -= f[j], siz++;
		res -= siz; if (res < n - 1) continue;
		ll t = C(res, n - 1);
		if (siz & 1) ans += P - t;
		else ans += t;
		if (ans >= P) ans -= P;
	}
	
	cout << ans % P << endl;
	return 0;
}
/*

C(n + m - 1, n - 1)

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
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

const int N = 500050;
ll jie[N], inv[N];
void prework(void) {
	const int Maxn = 300000;
	jie[0] = jie[1] = inv[0] = inv[1] = 1;
	for (int i = 2;i <= Maxn; i++) 
		jie[i] = jie[i-1] * i % P, 
		inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2;i <= Maxn; i++) inv[i] = inv[i-1] * inv[i] % P;
}


ll strling(ll n, ll m) {
	if (m > n) return 0;
	ll ans = 0;
	for (int i = 0;i <= m; i++) {
		if ((m - i) & 1) ans -= fpw(i, n) * inv[i] % P * inv[m-i] % P;
		else ans += fpw(i, n) * inv[i] % P * inv[m-i] % P;
		ans %= P;
	}
	return (ans + P) % P;
}

ll sum;
int main() {
	prework();
	int n, k; read(n), read(k);
	for (int i = 1;i <= n; i++) {
		ll x; read(x); sum += x;
	}
	sum %= P;
	sum = sum * (strling(n, k) + (n - 1) * strling(n - 1, k) % P) % P;
	cout << sum << endl;
	return 0;
}
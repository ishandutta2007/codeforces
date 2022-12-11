#pragma GCC optimize(3)
#pragma GCC optimize("inline")

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

const int N = 205000;
ll n, m;
ll a[N], t[N];
ll cnt[N];

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % m;
		mi >>= 1;
		x = x * x % m;
	}
	return res;
}

inline ll jue(ll x) {
	return x > 0 ? x : -x;
}

int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) read(a[i]);
	if (n > m) {
		cout << 0 << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n; i++) {
		for (int j = 0;j < m; j++) 
			t[(a[i] - j) % m] += cnt[j];
		cnt[a[i] % m]++;
	}
	ll ans = 1;
	for (int i = 0;i < m; i++) (ans *= fpw(i, t[i])) %= m;
	cout << ans << endl;
	return 0;
}
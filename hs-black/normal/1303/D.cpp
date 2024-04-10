#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
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

map<ll, int> Mp;

const int N = 200050;
ll T, n, m;
ll cnt[66];

int main() {
	for (ll i = 0;i <= 40; i++) Mp[1ll<<i] = i;
	read(T);
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		read(m), read(n);
		for (int i = 1;i <= n; i++) {
			ll x; read(x); cnt[Mp[x]]++;
		}
		ll a = 0, b = 0, ans = 0;
		for (ll i = 0;i <= 60; i++) {
			b += (m >> i) & 1;
			a += cnt[i];
			if (b && a) a--, b--;
			if (b && a) a--, b--;
			if (b) ans++;
			a >>= 1;
			if (b) b = 1;
		}
		if (b) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}
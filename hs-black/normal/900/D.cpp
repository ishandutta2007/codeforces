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

const int P = 1e9+7;

ll x, y; 

int mu(ll x) {
	if (x == 1) return 1;
	int cnt = 0;
	for (ll i = 2;i * i <= x; i++) {
		int res = 0;
		while (x % i == 0) res++, x /= i;
		if (res > 1) return 0;
		cnt += res;
	}
	if (x != 1) cnt++;
	return cnt & 1 ? -1 : 1;
}


ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P;
		mi >>= 1;
	}
	return res;
}


int main() {
	read(x), read(y);
	if (y % x != 0) {
		cout << 0 << endl;
		return 0;
	}
	
	ll ans = 0; y /= x;
	for (ll i = 1;i * i <= y; i++) {
		if (y % i) continue;
		ans += fpw(2, i - 1) * mu(y / i);
		if (i * i != y) ans += fpw(2, y / i - 1) * mu(i);
		ans %= P;
	}
	
	cout << (ans % P + P) % P << endl;
	return 0;
}
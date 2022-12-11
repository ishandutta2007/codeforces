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

const int N = 400;
int prime[N];
ll S[N], e[N], b[N];

void insert(ll x) {
	for (ll i = 35;i >= 0; i--) 
		if ((x >> i) & 1) {
			if (!b[i]) return b[i] = x, void();
			x ^= b[i];
		}
}

const int P = 1e9+7;

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P; mi >>= 1;
	} return res;
}

int main() {
	int cnt = 0;
	for (int i = 2;i <= 100; i++) {
		if (!e[i]) {
			prime[++cnt] = e[i] = i;
			S[i] = (1ll << (cnt - 1));
		}
		for (int j = 1;j <= cnt; j++) {
			e[prime[j] * i] = prime[j];
			S[prime[j] * i] = S[i] ^ S[prime[j]];
			if (prime[j] == e[i] || prime[j] * i > 100) break;
		}
		
	}
	int n; read(n);
	for (int i = 1, a;i <= n; i++) 
		read(a), insert(S[a]);
	cnt = 36;
	for (int i = 35;i >= 0; i--) cnt -= (b[i] == 0);
	cout << fpw(2, n - cnt) - 1 << endl;
	return 0;
}
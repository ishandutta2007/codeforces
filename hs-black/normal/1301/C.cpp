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

const int N = 100000;

inline ll get(ll k) {
	return k * (k + 1) / 2;
}

int main() {
	int T; read(T);
	while (T--) {
		ll n, m; read(n), read(m);
		ll b = n - m, k = b / (m + 1);
		ll p1 = b % (m + 1), p2 = m + 1 - p1;
		write(get(n) - get(k + 1) * p1 - get(k) * p2), putchar('\n');
	}
	return 0;
}
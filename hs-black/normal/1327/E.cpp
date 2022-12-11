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
const int N = 1e6+5;
int n;
ll mi[N];
int main() {
	read(n); mi[0] = 1;
	for (int i = 1;i <= n; i++) mi[i] = mi[i-1] * 10 % P;
	for (int i = 1;i <= n; i++) {
		ll ans = 9 * mi[n - i] * 2 % P;
		if (i == n) { printf ("10\n"); continue; }
		ans += (n - i - 1) * 81 % P * mi[n-i-1] % P;
		ans %= P; printf ("%lld ", ans);
	}
}
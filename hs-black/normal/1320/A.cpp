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

const int N = 405000;
int base = 400000;
ll dp[N], c[N*2], b[N], n;

inline void Mx(ll &x, ll y) {
	if (x < y) x = y;
}

int main() {
	read(n); ll ans = 0;
	for (int i = 1;i <= n; i++) read(b[i]);
	for (int i = 1;i <= n; i++) {
		dp[i] = c[i-b[i]+base] + b[i];
		Mx(c[i-b[i]+base], dp[i]);
		Mx(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
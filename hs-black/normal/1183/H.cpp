#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 100000000000000
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

const int N = 205;
ll f[N][N], k;
int pre[N], n;
char s[N];
int main() {
	read(n), read(k);
	scanf ("%s", s + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			f[i][j] = f[i-1][j] + f[i-1][j-1];
			if (pre[s[i]]) f[i][j] -= f[pre[s[i]]-1][j-1];
			if (f[i][j] >= INF) f[i][j] = INF;
		}
		pre[s[i]] = i;
	}
	ll ans = 0;
	for (int i = n; i >= 0; --i) {
		ll cost = min(k, f[n][i]);
		ans += cost * (n - i);
		k -= cost;
	}
	if (k) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
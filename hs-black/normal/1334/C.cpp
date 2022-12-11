#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
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
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 1000050;
ll a[N], b[N], sum[N], T, n;
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i = 1;i <= n; i++)
			read(a[i]), read(b[i]),
			a[i+n] = a[i], b[i+n] = b[i];
		for (int i = 1;i <= 2 * n; i++)
			sum[i] = sum[i-1] + max(a[i] - b[i-1], 0ll);
		ll ans = a[1] + sum[n] - sum[1];
		for (int i = 1;i <= n; i++)
			ans = min(a[i] + sum[i+n-1] - sum[i], ans);
		printf ("%lld\n", ans);
	}
	return 0;
}
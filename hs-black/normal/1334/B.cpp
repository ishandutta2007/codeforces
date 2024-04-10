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

const int N = 100050;
ll T, n, x, a[N];
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(x);
		for (int i = 1;i <= n; i++) read(a[i]);
		sort(a + 1, a + n + 1);
		ll sum = 0, ans = 0;
		for (int i = n;i >= 1; i--) {
			sum += a[i];
			if (sum < x * (n - i + 1)) break;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
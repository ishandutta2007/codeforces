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

int n, m;
int main() {
	int T; read(T);
	while (T--) {
	read(n); int pa = 0, pb = 0, fl = 0;
	for (int i = 1;i <= n; i++) {
		int a, b; read(a), read(b);
		if (fl) continue;
		a -= pa, b -= pb;
		if (b > a || a < 0 || b < 0) fl = 1, puts("NO");
		pa += a, pb += b;
	}
	if (!fl) puts("YES");
	}
	return 0;
}
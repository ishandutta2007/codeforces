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

int main() {
	int T; read(T);
	while (T--) {
		int n, d; read(n), read(d);
		int ans = 0; read(ans);
		for (int i = 2;i <= n; i++) {
			int x; read(x);
			if (x * (i - 1) >= d) {
				ans += d / (i - 1);
				d = 0;
			}
			else ans += x, d -= x * (i - 1);
		}
		cout << ans << endl;
	}
	return 0;
}
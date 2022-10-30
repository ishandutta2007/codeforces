// Hydro submission #6260f220255d14008c23858c@1650520608482
#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}

int n, a[110], b[110];

signed main() {
	for (int T = read(); T --;) {
		n = read();
		for (int i = 1; i <= n; i++) {
			a[i] = read();
		}
		for (int i = 1; i <= n; i++) {
			b[i] = read();
		}
		int res = 0;
		for (int i = n - 1; i >= 1; i --) {
			res += min(abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]), abs(a[i] - b[i + 1]) + abs(b[i] - a[i + 1]));
		}
		printf("%lld\n", res);
	}
	return 0;
}
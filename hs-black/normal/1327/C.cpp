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

int n, m, k;
int main() {
	read(n), read(m), read(k);
	for (int i = 1;i <= k; i++) {
		int x, y; read(x), read(y);
	}
	for (int i = 1;i <= k; i++) {
		int x, y; read(x), read(y);
	}
	printf ("%d\n", n + m - 3 + n * m);
	for (int i = 1;i < m; i++) putchar('L');
	for (int i = 1;i < n; i++) putchar('U');
	for (int i = 1;i <= m; i++) {
		for (int j = 1;j < n; j++) putchar(i & 1 ? 'D' : 'U');
		if (i != m) putchar('R');
	}
	return 0;
}
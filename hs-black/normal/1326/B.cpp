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

const int N = 2e6+5;
ll b[N], mx;

int main() {
	int n; read(n);
	for (int i = 1;i <= n; i++) read(b[i]);
	for (int i = 1;i <= n; i++) {
		printf ("%lld ", b[i] + mx);
		mx = max(mx, b[i] + mx);
	}
	return 0;
}
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
const int N = 2005000;
ll n, m, p;
ll a[N], b[N];
int main() {
	read(n), read(m), read(p);
	for (int i = 0;i < n; i++) read(a[i]);
	for (int i = 0;i < m; i++) read(b[i]);
	int i = n - 1, j = m - 1;
	for (;i >= 0; i--) if (a[i] % p) break;
	for (;j >= 0; j--) if (b[j] % p) break;
	cout << i + j << endl;
	return 0;
}
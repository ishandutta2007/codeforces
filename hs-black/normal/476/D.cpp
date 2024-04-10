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
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

int n, k;

int main() {
	read(n), read(k);
	cout << (6 * n - 1) * k << endl;
	for (int i = 1;i <= n; i++) {
		int x = 6 * i - 5;
		printf ("%d %d %d %d\n", x * k, (x + 1) * k, (x + 2) * k, (x + 4) * k);
	}
	return 0;
}
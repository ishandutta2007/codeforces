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

const int N = 20000;
int a[N], n, T;

int main() {
	read(T);
	while (T--) {
		read(n);
		int odd = 0, eve = 0;
		for (int i = 1;i <= n; i++) {
			read(a[i]);
			if (a[i] & 1) odd = 1;
			else eve = 1;
		}
		if (!odd) {
			printf ("NO\n");
			continue;
		}
		if (eve || (n & 1)) {
			printf ("YES\n");
			continue;
		}
		printf ("NO\n");
	}
	return 0;
}
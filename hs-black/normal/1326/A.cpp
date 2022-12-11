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

int main() {
	int T; read(T);
	while (T--) {
		int n; read(n);
		if (n == 1) {
			puts("-1");
			continue;
		}
		if ((n - 1) % 9 == 0) putchar('5');
		else putchar('2');
		for (int i = 1;i < n - 1; i++) putchar('2');
		putchar('9'), putchar('\n');
	}
	return 0;
}
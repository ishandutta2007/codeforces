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

int T, sum, x, n;
int main() {
	read(T);
	while (T--) {
		read(n); int cnt = sum = 0;
		for (int i = 1;i <= n; i++) {
			read(x); sum += x;
			if (x == 0) cnt++;
		}
		if (sum + cnt == 0) cnt++;
		printf ("%d\n", cnt);
	}
	return 0;
}
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

int T, n;
ll sum;

int main() {
	read(T);
	while (T--) {
		read(n); sum = 0;
		while (n >= 10) sum += (n / 10) * 10, n = (n / 10) + (n % 10);
		write(sum + n), putchar('\n');
	}
	return 0;
}
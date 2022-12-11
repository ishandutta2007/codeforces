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


char s[5000];
int T, n;
int main() {
	read(T);
	while (T--) {
		read(n); scanf ("%s", s + 1);
		int fl = 0, t, p;
		for (t = n;t >= 1; t--) if ((s[t] ^ '0') & 1) break;
		if (t <= 1) {
			write(-1), putchar('\n');
			continue;
		}
		for (p = t - 1;p >= 1; p--) {
			if ((s[p] ^ '0') & 1) {
				fl = 1;
				for (int k = p;k <= t; k++) putchar(s[k]);
				putchar('\n'); break;
			}
		}
		if (!fl) {
			write(-1), putchar('\n');
			continue;
		}
	}
	return 0;
}
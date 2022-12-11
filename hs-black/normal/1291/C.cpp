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

const int N = 50005;
int T, n, m, k;
int a[N];
int main() {
	read(T);
	while (T--) {
		read(n), read(m), read(k); k = min(m - 1, k);
		for (int i = 1;i <= n; i++) read(a[i]);
		int ans = 0, oth = m - 1 - k;
		for (int i = 0;i <= k; i++) {
			int tmp = 0x7fffffff;
			for (int j = 0;j <= oth; j++) 
				tmp = min(tmp, max(a[i+j+1], a[n-(k-i)-(oth-j)]));
			ans = max(ans, tmp);
		}
		write(ans), putchar('\n');
	}
	return 0;
}
/*

4
4 1 3
1 2 2 1
6 4 2
2 9 2 3 8 5
4 4 1
2 13 60 4
2 2 0
1 2


*/
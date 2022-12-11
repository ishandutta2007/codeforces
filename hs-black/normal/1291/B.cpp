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

const int N = 400005;
int a[N], k[N], T, n;

int main() {
	read(T);
	while (T--) {
		read(n); k[0] = 1;
		for (int i = 1;i <= n; i++) {
			read(a[i]); 
			if (a[i] >= (i-1) && k[i-1]) k[i] = 1;
			else k[i] = 0;
		}
		int fl = 0;
		for (int i = n;i >= 1; i--) {
			if (a[i] < (n - i)) break;
			if (k[i]) {
				printf ("Yes\n");
				fl = 1; break;
			}
		}
		if (!fl) printf ("No\n");
	}
	return 0;
}
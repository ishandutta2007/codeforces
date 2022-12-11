#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
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

const int N = 2000500;
int a[N], n;

int st[N], top;
double w[N];
int main() {
	read(n);
	for (register int i = 1;i <= n; i++) read(a[i]);
	w[0] = 1e9, st[0] = n + 1;
	for (register int i = n;i >= 1; i--) {
		int len = 1; double tmp = a[i];
		while (1) {
			if (tmp < w[top] * len) break;
			int nxt = st[top]; double res = w[top];
			top--;
			tmp += res * (nxt - i + 1 - len);
			len = nxt - i + 1;
		}
		tmp /= len;
		st[++top] = i + len - 1, w[top] = tmp;
	}
	int k = st[top];
	for (register int i = 1;i <= n; i++) {
		if (k < i) k = st[--top];
		printf ("%.10lf\n", w[top]);
	}
	return 0;
}
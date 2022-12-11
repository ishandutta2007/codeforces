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

const int N = 200500;
ll n, a, b, k;

ll h[N];

int main() {
	read(n), read(a), read(b), read(k);
	ll sum = a + b;
	for (int i = 1;i <= n; i++) {
		read(h[i]), h[i] %= sum;
		if (h[i] == 0) h[i] += sum;
		h[i] = (h[i] + a - 1) / a - 1;
	}
	sort(h + 1, h + n + 1);
	ll cnt = 0;
	for (int i = 1;i <= n; i++) {
		cnt += h[i];
		if (cnt > k) {
			printf ("%d\n", i - 1);
			break;
		}
	}
	if (cnt <= k) printf ("%lld\n", n);
	return 0;
}
/*

7 2 99 55
1 2 3 4 5 6 7


*/
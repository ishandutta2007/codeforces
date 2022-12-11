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

const int N = 10500;
ll m, n;
ll a[N];
int main() {
	read(n), read(m);
	ll p;
	for (int i = 1;i <= n; i++) {
		if (!m) {
			p = i; break;
		}
		ll k = (i - 1) / 2;
		if (m >= k) m -= k, a[i] = i;
		else {
			a[i] = (i - 1) + (i - m * 2);
			m = 0; p = i + 1; break;
		}
	}
	if (m) {
		cout << -1 << endl;
		return 0;
	}
	
	a[p] = 1919811; ll k = (a[p-1] == p - 1 ? p : p - 1);
	for (int i = p + 1;i <= n; i++) a[i] = a[i-1] + k;
	for (int i = 1;i <= n; i++) 
		printf ("%lld ", a[i]);
	return 0;
	
}
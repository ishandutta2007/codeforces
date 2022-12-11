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

const int N = 1000500;

ll a[N], n;
int cnt[N]; 
int main() {
	read(n);
	for (int i = 1;i <= n; i++) {
		read(a[i]);
		for (ll j = 0;j <= 31; j++) 
			if ((1ll << j) & a[i]) cnt[j]++;
	}
	ll mx = 0, pos = 1;
	for (int i = 1;i <= n; i++) {
		ll tmp = 0;
		for (int j = 0;j <= 31; j++) {
			if (((1ll << j) & a[i]) && cnt[j] == 1)
				tmp += 1ll << j;
		}
		if (tmp > mx) mx = tmp, pos = i;
	}
	swap(a[pos], a[1]);
	for (int i = 1;i <= n; i++) printf ("%d ", (int)a[i]);
	return 0;
}
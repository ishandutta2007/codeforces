#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y, 0); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

ll l, r, m, T;
int main() {
	for (read(T); T; T--) {
		read(l), read(r), read(m);
		for (ll i = l;i <= r; i++) {
			ll t = m % i;
			if (m >= i && t <= r - l) { 
				printf ("%lld %lld %lld\n", i, l + t, l);
				break;
			}
			if (i - t <= r - l) {
				printf ("%lld %lld %lld\n", i, l, l + i - t);
				break;
			}
		}
	}
	return 0;
}
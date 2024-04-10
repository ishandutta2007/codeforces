
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

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
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

ll T, m, d, w;
inline ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
inline ll calc(ll x) { return x * (x - 1) / 2; }
int main() {
	for (read(T); T; T--) {
		read(m), read(d), read(w);
		w /= gcd(d - 1, w);
		Mn(m, d);
		ll t1 = m / w, t2 = t1 + 1;
		ll cnt2 = m % w, cnt1 = w - cnt2;
		write(cnt1 * calc(t1) + cnt2 * calc(t2));
	}
	return 0;
}
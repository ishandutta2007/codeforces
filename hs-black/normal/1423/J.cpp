
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

const int P = 1e9 + 7;
ll T, n;
int main() {
	for (read(T); T; T--) {
		read(n); if (n & 1) n--;
		if (n <= 4) {
			if (n == 0) write(1);
			if (n == 2) write(2);
			if (n == 4) write(4);
			continue; 
		}
		ll t = (n - 2) / 2;
		ll tt = (t / 2) % P + 1;
		ll ans = tt * (tt + 1) % P;
		if (t & 1) ans += tt + 1;
		write(ans % P);
	}
	return 0;
}

/*

7
10000000000000000
10000000000000000
10000000000000000
41561651651651
1816816516561651
516515665165
61615616

*/
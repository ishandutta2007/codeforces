
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
ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

const int N = 2005;
ll k, pa, pb;
ll f[N][N];
int main() {
	read(k), read(pa), read(pb);
	ll t = fpw(pa + pb, P - 2);
	pa = pa * t % P, pb = pb * t % P;
	f[1][0] = 1; ll ans = 0;
	for (int i = 1;i <= k; i++) {
		for (int j = 0;j < k; j++) {
			f[i+1][j] = (f[i+1][j] + f[i][j] * pa) % P;
			if (j + i < k) f[i][j+i] = (f[i][j+i] + f[i][j] * pb) % P;
			else ans = (ans + (j + i) * f[i][j] % P * pb) % P;
		}
	}
	t = fpw(pb, P - 2);
	for (int i = 0;i < k; i++) 
		ans = (ans + f[k+1][i] * (k + i + t)) % P;
	write(ans);
	return 0;
}
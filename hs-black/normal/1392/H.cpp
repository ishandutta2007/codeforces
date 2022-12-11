
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

const int P = 998244353;
const int N = 2050000;
ll inv[N], m, n;
int main() {
	read(n), read(m); int lim = max(n, m + 1);
	inv[0] = inv[1] = 1;
	ll H = 1;
	for (int i = 2;i <= lim; i++) {
		inv[i] = (P - P / i) * inv[P % i] % P;
		if (i <= n) H = (H + inv[i]) % P;
	}
	H = (m * H + 1) % P;
	write((n * inv[m+1] + 1) % P * H % P);
	return 0;
}

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

#include <bitset>
const int N = 55;
ll a[N], n, k;
bool Dp(ll ans) {
	bitset<55> f[55];
	f[0][0] = 1;
	for (int i = 1;i <= n; i++) 
		for (int j = 0;j < i; j++) 
			if (((a[i] - a[j]) & ans) == ans) 
				f[i] |= f[j] << 1;
	return f[n][k];
}

int main() {
	read(n), read(k);
	for (int i = 1;i <= n; i++) read(a[i]), a[i] += a[i-1];
	ll ans = 0;
	for (int i = 60;i >= 0; i--) 
		if (Dp(ans | (1ll << i)))
			ans |= 1ll << i;
	write(ans);
	return 0;
}
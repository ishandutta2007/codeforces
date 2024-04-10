
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

const int N = 305000;
int cnt[N], lim, n;

const int P = 998244353;
ll C(int n, int m) {
	ll res = 1;
	for (int i = n;i >= n - m + 1; i--)
		res = res * i % P;
	return res;
}

ll f[N];
bool calc(int t) {
	for (int i = lim;i >= 1; i--) {
		f[i] = C(cnt[i], t);
		for (int t = i + i;t <= lim; t += i)
			f[i] -= f[t];
		f[i] = (f[i] % P + P) % P;
	}
	return f[1] > 0;
}

int main() {
	read(n);
	for (int i = 1, x;i <= n; i++) 
		read(x), cnt[x]++, Mx(lim, x);
	for (int i = 1;i <= lim; i++)
		for (int j = i + i;j <= lim; j += i) 
			cnt[i] += cnt[j];
	for (int i = 1;i <= 7; i++)
		if (calc(i)) return write(i), 0;
	return write(-1), 0;
}
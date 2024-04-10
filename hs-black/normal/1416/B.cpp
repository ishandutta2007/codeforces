
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

const int N = 200050;
ll a[N], n, T;
ll aa[N], ax[N], ay[N], cnt;
int main() {
	for (read(T); T; T--) {
		ll sum; read(n); a[0] = cnt = sum = 0;
		for (int i = 1;i <= n; i++) read(a[i]), sum += a[i];
		if (sum % n != 0) { write(-1); continue; }
		sum /= n;
		for (int i = 2;i <= n; i++) {
			if (a[i] % i == 0) ax[++cnt] = i, ay[cnt] = 1, aa[cnt] = a[i] / i, a[1] += a[i];
			else {
				ll t = a[i] / i; t = (t + 1) * i - a[i];
				ax[++cnt] = 1, ay[cnt] = i, aa[cnt] = t;
				ax[++cnt] = i, ay[cnt] = 1, aa[cnt] = a[i] / i + 1;
			}
		}
		for (int i = 2;i <= n; i++) 
			ax[++cnt] = 1, ay[cnt] = i, aa[cnt] = sum;
		write(cnt);
		for (int i = 1;i <= cnt; i++) write(ax[i], ' '), write(ay[i], ' '), write(aa[i]);
	}
	return 0;
}
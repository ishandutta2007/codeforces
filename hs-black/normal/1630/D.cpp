/*

 
| _ _|
 ` _x 
  /  |
 /  c ?
| |||
| (c_c_)_)


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

const int N = 2050000;
int a[N], mn[N], fl[N];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
	int n, T, m, G;
	for (read(T); T; T--) {
		read(n), read(m), G = 0;
		ll ans = 0;
		for (int i = 1;i <= n; ++i) read(a[i]), ans += abs(a[i]);
		for (int i = 1, b;i <= m; ++i) read(b), G = gcd(b, G);
		ll sum1 = ans, sum2 = ans;
		for (int i = 1;i <= G; ++i) {
			mn[i] = 1145141919, fl[i] = 0;
			int x = i;
			while (x <= n) {
				mn[i] = min(mn[i], abs(a[x]));
				fl[i] ^= a[x] < 0;
				x += G;
			}
			if (fl[i]) sum1 -= 2 * mn[i];
			else sum2 -= 2 * mn[i];
		}
		write(max(sum1, sum2));
	}
	return 0;
}

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
int n, x, pos, sb, sm;
int main() {
	read(n), read(x), read(pos);
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (mid <= pos) l = mid + 1, sm++;
		else r = mid, sb++;
	}
	int t1 = n - x, t2 = x - 1;
	ll ans = 1;
	for (int i = 1;i <= sb; i++) ans = ans * (t1 - i + 1) % P;
	for (int i = 1;i < sm; i++) ans = ans * (t2 - i + 1) % P;
	for (int i = n - sm - sb;i >= 1; i--) ans = ans * i % P;
	write(ans);
	return 0;
}

/*

1000 80 6

*/
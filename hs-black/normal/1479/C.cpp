/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

const int N = 20050;
int L, R, x[N], y[N], z[N], m;

inline void add(int a, int b, int c) {
	x[++m] = a, y[m] = b, z[m] = c;
}

int main() {
	read(L), read(R);
	int t = 23, nw = 1;
	puts("YES");
	add(22, 23, L);
	for (int i = 21;i >= 2; --i) {
		int tt = nw; nw <<= 1;
		for (int j = i + 1;j <= 22; ++j)
			add(i, j, tt), tt >>= 1;
		add(i, 23, L);
	}
	add(1, t, L);
	int k = R - L, tt = 1;
	for (int j = 0;j <= 22; ++j)
		if (k >> j & 1) add(1, 22 - j, tt), tt += 1 << j;
	write(23, ' '), write(m);
	for (int i = 1;i <= m; ++i)
		write(x[i], ' '), write(y[i], ' '), write(z[i]);
	return 0;
}
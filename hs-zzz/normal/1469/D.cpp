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

#include <cmath>
const int N = 300500;
int x[N], y[N], cnt, n, T;
int main() {
	for (read(T); T; T--) {
		read(n), cnt = 0;
		int nw = n;
		for (int i = n - 1;i > 2; i--) {
			if (1ll * i * i <= nw) {
				x[++cnt] = n, y[cnt] = i;
				if (nw % i == 0) nw /= i;
				else nw = nw / i + 1;
			}
			x[++cnt] = i, y[cnt] = n;
		}
		while (nw > 1) x[++cnt] = n, y[cnt] = 2, nw = (nw + 1) >> 1;
		write(cnt);
		for (int i = 1;i <= cnt; i++)
			write(x[i], ' '), write(y[i]);
	}
	return 0;
}

/*

1 2 1 1 1 1 1 1 3

*/
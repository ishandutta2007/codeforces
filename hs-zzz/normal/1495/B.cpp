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

const int N = 200050;
int p[N], ok[N], L[N], R[N], val[N], n, st[N], tp;
int main() {
	read(n);
	for (int i = 1;i <= n; ++i) read(p[i]);
	p[0] = p[n + 1] = n + 1;
	int ans = 0;
	for (int i = 0;i <= n + 1; ++i) if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
		st[++tp] = i;
		int x = i;
		while (p[x] > p[x - 1]) ++L[i], --x;
		x = i;
		while (p[x] > p[x + 1]) ++R[i], ++x;
		val[i] = max(L[i], R[i]);
		ok[i] = 1;
		if (R[i] <= L[i] - (~L[i] & 1)) ok[i] = 0;
		if (L[i] <= R[i] - (~R[i] & 1)) ok[i] = 0;
		L[i] = R[i] = val[i];
	}
	L[0]--, R[0]--, L[n + 1]--, R[n + 1]--;
	for (int i = 1;i <= n; ++i) Mx(L[i], L[i - 1]);
	for (int i = n;i >= 1; --i) Mx(R[i], R[i + 1]);
	int nw = 1;
	for (int i = 1;i <= n; ++i) if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
		++nw;
		int tmx = max(L[st[nw - 1]], R[st[nw + 1]]);
		if (tmx >= val[i]) continue;
		ans += ok[i];
	}
	write(ans);
	return 0;
}

/*

4
1 2 4 3

*/
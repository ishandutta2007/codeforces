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

const int N = 205;
int n;
double p[N], P[N];
int main() {
	read(n);
	for (int i = 1, x;i <= n; i++) 
		read(x), p[i] = x / 100.0;
	double pos = 1;
	for (int i = 1;i <= n; i++) 
		P[i] = 1 - p[i], pos = pos * p[i];
	double ans = n + 1 - pos;
	auto calc = [&](int t) {
		return pos / (1 - P[t]) * (1 - P[t] * (1 - p[t]));
	};
	for (int i = 1;i <= 300000; i++) {
		int t = 1;
		for (int j = 2;j <= n; j++) if (calc(j) > calc(t)) t = j;
		pos = calc(t), ans += 1 - pos, P[t] *= 1 - p[t];
	}
	printf ("%.8lf\n", ans);
	return 0;
}
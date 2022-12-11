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


const int P = 1e9 + 7;
const int N = 500500;
int T, cnt[100], n;
ll x[N];
int main() {
	for (read(T); T; T--) {
		read(n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1;i <= n; i++) {
			read(x[i]);
			for (int j = 60;j >= 0; j--) 
				if (x[i] >> j & 1) cnt[j]++;
		}
		ll ans = 0;
		for (int i = 1;i <= n; i++) {
			ll val = 0;
			for (int j = 60;j >= 0; j--) {
				ll t = (1ll << j) % P;
				if (x[i] >> j & 1) val = (val + t * n) % P;
				else val = (val + cnt[j] * t) % P;
			}
			for (int j = 60; j >= 0; j--) {
				ll t = (1ll << j) % P;
				if (x[i] >> j & 1) ans = (ans + t * val % P * cnt[j]) % P;
			}
		}
		write(ans);
	}
	return 0;
}
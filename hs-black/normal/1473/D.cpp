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

const int N = 2050000;
int mmn[N], mn[N], mx[N], mmx[N], s1[N], s2[N];
int T, m, n; char s[N];
int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		scanf ("%s", s + 1);
		mn[0] = mx[0] = 0, mmn[n + 1] = mmx[n + 1] = 0;
		int t = 0; s2[n + 1] = 0;
		for (int i = 1;i <= n; ++i) {
			s[i] == '+' ? t += 1 : t -= 1;
			mn[i] = min(mn[i - 1], t), mx[i] = max(mx[i - 1], t);
			s1[i] = t;
		}
		for (int i = n;i >= 1; --i) {
			t = s[i] == '+' ? 1 : -1;
			mmn[i] = mmn[i + 1] + t, mmx[i] = mmx[i + 1] + t;
			Mn(mmn[i], 0), Mx(mmx[i], 0), s2[i] = s2[i + 1] + t;
		}
		for (int i = 1, l ,r;i <= m; ++i) {
			read(l), read(r);
			int L = min(mn[l - 1], s1[l - 1] + mmn[r + 1]);
			int R = max(mx[l - 1], s1[l - 1] + mmx[r + 1]);
			write(R - L + 1);
		}
	}
	return 0;
}
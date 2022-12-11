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
int vis[N], cnt, m, n;
int siz[N], f[N], sp[N], st[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]); 
}
ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}
int main() {
	read(n), read(m);
	for (int i = 1;i <= m; i++) siz[f[i] = i] = 1;
	for (int i = 1, k, x, y;i <= n; i++) {
		read(k);
		if (k == 1) {
			read(x);
			if (sp[find(x)]) continue;
			vis[x] = 1, st[++cnt] = i;
			sp[find(x)]++;
		}
		else {
			read(x), read(y);
			if ((sp[find(x)] && sp[find(y)]) || find(x) == find(y)) continue;
			st[++cnt] = i;
			siz[find(y)] += siz[find(x)], sp[find(y)] += sp[find(x)], f[find(x)] = find(y);
		}
	}
	ll ans1 = 1;
	for (int i = 1;i <= m; i++) if (find(i) == i) {
		if (sp[i]) ans1 = ans1 * fpw(2, siz[i]) % P;
		else ans1 = ans1 * fpw(2, siz[i] - 1) % P;
	}
	write(ans1 % P, ' '), write(cnt);
	for (int i = 1;i <= cnt; i++) write(st[i], ' ');
	return 0;
}
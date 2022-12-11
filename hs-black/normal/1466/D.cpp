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

const int N = 200500;
int T, n, val[N], deg[N], id[N];
bool cmp(int x, int y) {
	return val[x] > val[y];
}
int main() {
	for (read(T); T; T--) {
		read(n); ll ans = 0;
		memset(deg, 0, n * 4 + 20);
		for (int i = 1;i <= n; i++) read(val[id[i] = i]), ans += val[i];
		for (int i = 1, x, y;i < n; i++) 
			read(x), read(y), deg[x]++, deg[y]++;
		sort(id + 1, id + n + 1, cmp);
		int nw = 1;
		for (int i = 1;i < n; i++) {
			write(ans, ' ');
			while (deg[id[nw]] <= 1 && nw <= n) nw++;
			ans += val[id[nw]], deg[id[nw]]--;
		}
		puts("");
	}
	return 0;
}
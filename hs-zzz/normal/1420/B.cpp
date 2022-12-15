
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

int cnt[342], T, n;
int main() {
	for (read(T); T; T--) {
		memset(cnt, 0, sizeof(cnt));
		read(n); ll ans = 0;
		for (int i = 1, x;i <= n; i++) {
			int t; read(x);
			for (int j = 0;j <= 52; j++)
				if ((1ll << j) > x) { t = j - 1; break; }
			cnt[t]++, ans += cnt[t] - 1;
		}
		write(ans);
	}
	return 0;
}
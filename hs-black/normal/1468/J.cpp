
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

const int N = 3050000;
struct node {
	int x, y, s;
	bool operator < (const node &i) const {
		return s < i.s;
	}
}ed[N];

int f[N], T;
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int m, n, k;
int main() {
	for (read(T); T; --T) {
		read(n), read(m), read(k);
		for (int i = 1; i <= m; ++i) 
			read(ed[i].x), read(ed[i].y), read(ed[i].s);
		sort(ed + 1, ed + m + 1);
		for (int i = 1;i <= n; i++) f[i] = i;
		ll cnt = n - 1, sum = 0, res = 1e15;
		for (int i = 1;i <= m; ++i) {
			int x = find(ed[i].x), y = find(ed[i].y);
			if (x != y) {
				--cnt, f[x] = y, sum += max(0, ed[i].s - k);
				if (!cnt && ed[i].s >= k) { Mn(res, sum); break; } 
			}
			if (!cnt) {
				if (ed[i].s <= k) Mn(res, (ll)k - ed[i].s);
				else Mn(res, sum + ed[i].s - k);
			}
		}
		write(res);
	}
	return 0;
}
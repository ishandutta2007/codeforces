
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

const int lim = 63;
int cnt[10], to[10], siz[100];
bool check(void) {
	for (int i = 1;i <= lim; i++) 
		if (siz[i] < 0) return 0;
	return 1;
}

const int N = 200050;
int vis[N], a[N], m, n;
char s[N];
int main() {
	scanf ("%s", s + 1), read(m), n = strlen(s + 1);
	for (int i = 1;i <= n; i++) {
		int c = s[i] - 'a'; cnt[c]++;
		for (int j = 1;j <= lim; j++)
			if (j >> c & 1) siz[j]--;
	}
	for (int i = 1, p;i <= m; i++) {
		read(p), scanf ("%s", s);
		int t = strlen(s);
		for (int i = 0;i < t; i++) 
			vis[p] |= 1 << (s[i] - 'a');
	}
	for (int i = 1;i <= n; i++) {
		if (!vis[i]) vis[i] = 63;
		for (int t = 0;t <= lim; t++)
			if (vis[i] & t) siz[t]++;
	}
	if (!check()) return puts("Impossible"), 0;
	for (int i = 1;i <= n; i++) {
		for (int t = 0;t <= lim; t++)
			if (vis[i] & t) siz[t]--;
		for (int j = 0;j < 6; j++) {
			if (!cnt[j] || !(vis[i] >> j & 1)) continue;
			for (int t = 1;t <= lim; t++) 
				if (t >> j & 1) siz[t]++;
			cnt[j]--;
			if (check()) { a[i] = j; break; } 
			for (int t = 1;t <= lim; t++) 
				if (t >> j & 1) siz[t]--;
			cnt[j]++;
		}
	}
	for (int i = 1;i <= n; i++) putchar('a' + a[i]);
	return 0;
}
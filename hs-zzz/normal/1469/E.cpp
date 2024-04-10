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

#define ull unsigned ll
const int N = 2000500;
const int P = 19260817;
const int bs = 13331;
int T, n, k;
char s[N];
ll h1[N], b1[N];
ull h2[N], b2[N];
#include <set>
set<pair<ll, ull> > s1;
inline ll g1(int l, int r) {
	return (h1[r] + (P - h1[l-1]) * b1[r - l + 1]) % P;
}
inline ull g2(int l, int r) {
	return h2[r] - h2[l-1] * b2[r - l + 1];
}

int st[N], fl;
void dfs(int las, ll hh1, ull hh2) {
	if (fl) return;
	if (!las) {
		if (s1.find(MP(hh1, hh2)) == s1.end()) fl = 1;
		return;
	}
	if (!fl) st[las] = 0, dfs(las - 1, (hh1 * bs + '0') % P, hh2 * bs + '0');
	if (!fl) st[las] = 1, dfs(las - 1, (hh1 * bs + '1') % P, hh2 * bs + '1');
}

int main() {
	b1[0] = b2[0] = 1;
	for (int i = 1;i <= 1000000; i++)
		b1[i] = b1[i-1] * bs % P, b2[i] = b2[i-1] * bs;
	for (read(T); T; T--) {
		read(n), read(k), fl = 0;
		scanf ("%s", s + 1);
		for (int i = 1;i <= n; i++) 
			h1[i] = (h1[i-1] * bs + (s[i] ^ 1)) % P, h2[i] = h2[i-1] * bs + (s[i] ^ 1);
		s1.clear();
		for (int i = k;i <= n; i++)
			s1.insert(MP(g1(i - k + 1, i), g2(i - k + 1, i)));
		dfs(k, 0, 0);
		if (!fl) puts("NO");
		else {
			puts("YES");
			for (int i = k;i >= 1; i--) putchar('0' | st[i]);
			puts("");
		}
	}
	return 0;
}
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

const int N = 250000;
#define lb lower_bound
#include <set>
set<int> st[2];
int f(int t) { return *st[t].begin(); }
int T[N], n;
char s[N];
int main() {
	scanf ("%s", s + 1), n = strlen(s + 1);
	for (int i = 1;i <= n; ++i) st[s[i]=='L'].insert(i);
	st[0].insert(n + 1), st[1].insert(n + 1);
	int t0 = st[0].size(), t1 = st[1].size();
	if (t0 < t1 || (t0 == t1 && f(0) > f(1))) swap(st[0], st[1]);
	int nw = 0, ans = 0, nxt = f(0);
	for (int i = 1;i <= n; ++i, nw ^= 1) {
		if (nxt > n || (*st[!nw].lb(nxt) > n && f(nw) != nxt && f(nw) < f(!nw))) 
			++ans, nxt = f(nw);
		st[nw].erase(T[i] = nxt);
		nxt = *st[!nw].lb(nxt);
	}
	write(ans);
	for (int i = 1;i <= n; ++i) write(T[i], ' ');
	return 0;
}
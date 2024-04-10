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

const int N = 20500;
int n;
vector<int> ans;
int x[N], y[N];
int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(x[i]), read(y[i]);
	while (1) {
		ans.clear();
		for (int i = 1;i <= n; i++) 
			if ((x[i] + y[i] + 4000000) & 1) ans.emplace_back(i);
		if (ans.size() && (int)ans.size() < n) break;
		int p = (x[1] + y[1]) & 1;
		for (int i = 1;i <= n; i++) {
			int t1 = x[i] - p, t2 = y[i];
			x[i] = (t1 + t2) / 2, y[i] = (t1 - t2) / 2;
		}
	}
	write(ans.size());
	for (auto t: ans) write(t, ' ');
	return 0;
}
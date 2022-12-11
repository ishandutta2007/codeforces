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
#define MP node
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

#include <set>
#include <cmath>
const int N = 2050000;
int l[N], p[N], used[N], n, t, nw, sum, q;

const double eps = 1e-10;
struct node {
	double first; int second;
	bool operator < (const node &i) const {
		return abs(i.fi - fi) > eps ? fi < i.fi : se < i.se;
	}
	node () {}
	node (double f, int s) { fi = f, se = s; }
};

multiset<node> mul, las;
inline double calc(int x, int pas) {
	return 1.0 * p[x] * (1.0 * (pas + 1) / (pas + l[x] + 1) - 1.0 * pas / (pas + l[x]));
}

inline void mz(void) { write(mul.size()); }
inline void dele(int x, int pas) {
	if (pas < l[x]) mul.erase(MP(calc(x, pas), x));
	if (pas) las.erase(MP(calc(x, pas - 1), x));
}

inline void inse(int x, int pas) {
	if (pas < l[x]) mul.insert(MP(calc(x, pas), x));
	if (pas) las.insert(MP(calc(x, pas - 1), x));
}

double ans;
inline void addin(int x) { 
	dele(x, used[x]), ans += calc(x, used[x]), ++used[x], inse(x, used[x]);
}

inline void erase(int x) {
	dele(x, used[x]), --used[x], ans -= calc(x, used[x]), inse(x, used[x]);
}

inline double jzp(int x, int c) { return 1.0 * p[x] * c / (c + l[x]); }

int main() {
//	freopen ("hs.in","r",stdin);
//	freopen ("hs.out","w",stdout);
	read(n), read(t), read(q);
	for (int i = 1;i <= n; i++) read(p[i]);
	for (int i = 1;i <= n; i++) read(l[i]), sum += l[i];
	for (int i = 1;i <= n; i++) mul.insert(MP(calc(i, 0), i));
	while (nw < t && nw < sum) {
		auto hd = mul.end(); --hd; addin((*hd).se); ++nw;
	}
	
	for (; q; q--) {
//		if (q % 20000 == 0) write(q);
		int op, x; read(op), read(x);
//		write(mul.size());
		dele(x, used[x]), ans -= jzp(x, used[x]);
		op == 1 ? (++l[x], ++sum) : (--l[x], --sum);
		if (used[x] > l[x]) used[x]--, nw--;
		inse(x, used[x]), ans += jzp(x, used[x]);
//		printf ("%.7lf\n", (--mul.end())->fi);
//		printf ("%.7lf\n", (las.begin())->fi);
//		mz();
		while (nw < t && nw < sum) addin((--mul.end())->se), ++nw;
		while (las.size() && mul.size() && (las.begin())->fi + eps < (--mul.end())->fi) 
			erase((las.begin())->se), addin((--mul.end())->se);
		printf ("%.7lf\n", ans);
	}
	return 0;
}
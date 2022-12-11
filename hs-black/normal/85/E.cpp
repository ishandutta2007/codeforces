
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

#define Pa pair<int, int>
const int N = 100005;
vector<Pa> v[N];
int x[N], y[N], f[N], n;
inline int jue(int x) { return x > 0 ? x : -x; }
inline int manh(int i, int j) { return jue(x[i] - x[j]) + jue(y[i] - y[j]); }
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
const int P = 1e9 + 7;
int main() {
	read(n);
	for (int i = 1;i <= 2 * n; i++) f[i] = i;
	for (int i = 1;i <= n; i++) {
		read(x[i]), read(y[i]); 
		for (int j = 1;j < i; j++) 
			v[manh(i, j)].push_back(MP(i, j));
	}
	ll ans = 0;
	for (int i = 10000;i >= 0; i--) {
		for (auto t: v[i]) {
			int x = find(t.fi), y = find(t.se);
			int tx = find(t.fi + n), ty = find(t.se + n);
			if (tx == ty || x == y) { ans = i; break; }
			f[x] = ty, f[y] = tx;
		}
		if (ans) break;
	}
	write(ans);
	for (int i = 1;i <= n; i++) f[i] = i;
	for (int i = ans + 1;i <= 10000; i++) 
		for (auto t: v[i]) {
			int x = find(t.fi), y = find(t.se);
			f[x] = y;
		}
	ans = 1;
	for (int i = 1;i <= n; i++) 
		if (f[i] == i) ans = ans * 2 % P;
	write(ans);
	return 0;
}
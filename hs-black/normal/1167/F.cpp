
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

const int N = 2000005;
const int P = 1e9 + 7;
int id[N], a[N], n;
bool cmp(int x, int y) { return a[x] < a[y]; }

struct Binary {
	int d[N];
	inline void add(int &x, int y) { x += y, x >= P && (x -= P); }
	inline void Add(int x, int c) {
		for (; x <= n; x += x & -x) add(d[x], c);
	}
	inline void Add(int l, int r, int c) {
		if (l > r) return;
		Add(l, c), Add(r + 1, P - c);
	}
	inline int query(int x) {
		int res = 0;
		for (; x; x -= x & -x) add(res, d[x]);
		return res;
	}
}A, B;

int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(a[id[i] = i]);
	sort(id + 1, id + n + 1, cmp);
	ll ans = 0, res = 0;
	for (int i = 1;i <= n; i++) {
		int x = id[i];
		res = ((x + (ll)A.query(x)) * (n - x + 1) + (ll)B.query(x) * x) % P;
		ans = (ans + res * a[x]) % P, A.Add(x + 1, n, x), B.Add(1, x - 1, n - x + 1);
	}
	write(ans);
	return 0;
}
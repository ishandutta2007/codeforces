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

const int N = 5005;
ll f[N], cnt[N], vis[N], nc[N], n;
inline ll C(ll x) { return x * (x - 1) / 2; }
ll del(ll x, int t) {
	if (x == 0) return vis[t]; 
	for (int i = 2;i <= 200; i++) 
		if (x == C(i)) return i;
	return 0;
}

ll Tp, Sp, T, S;

void query(int x, ll &T, ll &S) {
	putchar('+'), putchar(' '), write(x);
	fflush(stdout), read(T), read(S);
}

int main() {
	read(n), read(Tp), read(Sp); ll d = 0;
	query(2, Tp, Sp);
	query(1, T, S), d = S - Sp;
	Tp = T, Sp = S, query(3, T, S);
	ll dd = S - Sp;
	Tp = T, Sp = S, query(1, T, S);
	vis[1] = 1, cnt[1] = del(T - Tp, 1) - 1;
	cnt[2] = S - Sp - d - 1;
	cnt[3] = d / (cnt[2] + 1);
	if (n == 4) {
		cnt[4] = dd - (cnt[1] + 1) * (cnt[2] + 1);
		cnt[4] /= (cnt[2] + 1);
		putchar('!'); putchar(' ');
		for (int i = 1;i <= n; i++) write(cnt[i], ' ');
		return 0;
	}
	nc[1] = cnt[1] + 2, nc[2] = cnt[2] + 1, nc[3] = cnt[3] + 1;
	dd -= (cnt[1] + 1) * (cnt[2] + 1); vis[4] = dd ? 1 : 0;
	for (int i = 4;i < n; i++) {
		Tp = T, Sp = S, query(i, T, S);
		ll res = S - Sp; res -= nc[i-1] * nc[i-2];
		if (res > 0) vis[i + 1] = 1;
		cnt[i] = del(T - Tp, i);
		nc[i] = cnt[i] + 1;
	}
	S -= Sp + nc[n-2] * nc[n-3];
	cnt[n] = S / nc[n-2];
	putchar('!'); putchar(' ');
	for (int i = 1;i <= n; i++) write(cnt[i], ' ');
	return 0;
}

/*

5
1 6
1 12
2 18
5 24
8 32
8 48

*/
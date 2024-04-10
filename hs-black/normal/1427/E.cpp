
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

const ll inf = 1ll << 60;
const int N = 200050;
ll ans[N][3], q;
#include <set>
set<ll> s;
ll a[N], bit[N], n;
inline bool oper(ll x, ll y, bool op) {
	if (x + y >= inf) return 0;
	ll t = op ? (x ^ y) : (x + y);
	if (s.find(t) != s.end()) return 0;
	s.insert(t); a[++n] = t;
	ans[++q][0] = x, ans[q][1] = y, ans[q][2] = op;
	return 1;
}

bool chk(ll x) {
	for (int i = 60;i >= 0; i--) {
		if (x >> i & 1) {
			if (bit[i]) x ^= bit[i];
			else return 1;
		}
	}
	return 0;
}

void insert(ll x) {
	for (int i = 60;i >= 0; i--) {
		if (x >> i & 1) {
			if (bit[i]) oper(bit[i], x, 1), x ^= bit[i];
			else { bit[i] = x; break; }
		}
	}
}

int main() {
	srand((ll)new char);
	read(a[1]), s.insert(a[1]), insert(a[1]), n = 1;
	for (int i = 2;i <= 20; i++) 
		if (oper(a[n], a[n], 0) && chk(a[n])) insert(a[n]);
	while (s.find(1) == s.end()) {
		int x = rand() % n + 1, y = rand() % n + 1;
		if (oper(a[x], a[y], 0) && chk(a[n])) insert(a[n]);
	}
	write(q);
	for (int i = 1;i <= q; i++) 
		write(ans[i][0], ' '), putchar(ans[i][2] ? '^' : '+'), putchar(' '), write(ans[i][1]);
	return 0;
}
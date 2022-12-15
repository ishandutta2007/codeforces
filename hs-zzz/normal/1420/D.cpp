
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

const int P = 998244353;
const int N = 400050;
int n, k; ll fac[N], inv[N];

inline ll C(int n, int m) {
	if (n < 0 || m > n) return 0;
	return fac[n] * inv[m] % P * inv[n-m] % P;
}

struct node {
	int l, r;
	bool operator < (const node &i) const {
		return l < i.l;
	}
}p[N];

priority_queue<int> q;
int main() {
	read(n), read(k);
	inv[0] = fac[0] = inv[1] = fac[1] = 1;
	for (int i = 2;i <= n; i++) 
		inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2;i <= n; i++)
		fac[i] = fac[i-1] * i % P, inv[i] = inv[i-1] * inv[i] % P;
	for (int i = 1;i <= n; i++) read(p[i].l), read(p[i].r);
	sort(p + 1, p + n + 1);
	ll ans = 0;
	for (int i = 1;i <= n; i++) {
		q.push(-p[i].r);
		while (-q.top() < p[i].l) q.pop();
		ans = (ans + C(q.size() - 1, k - 1)) % P;
	}
	write(ans);
	return 0;
}
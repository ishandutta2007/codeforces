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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 200500;
const int P = 998244353;
ll d[N], a[N], sum[N], s[N], n;
void add(int x) {
	for (; x <= n; x += x & -x) d[x]++;
}

int query(int x) {
	int res = 0;
	for (; x; x -= x & -x) res += d[x];
	return res;
}

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P, mi >>= 1;
	}
	return res;
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) {
		read(a[i]);
		if (~a[i]) sum[a[i]] = s[i] = 1;
	}
	for (int i = 1;i <= n; i++) 
		sum[i] = sum[i-1] + sum[i],
		s[i] = s[i-1] + s[i];
		
	ll ans = 0, m = fpw(n - s[n], P - 2), k = n - s[n];
	for (int i = 1;i <= n; i++)
		if (~a[i]) ans += s[i] - query(a[i]) - 1, add(a[i]);
	ans = (ans + k * (k - 1) % P * fpw(4, P - 2)) % P;
	for (int i = 1;i <= n; i++) {
		if (a[i] == -1) continue;
		ans += (n-a[i]-(sum[n] - sum[a[i]])) * (i - s[i]) % P * m % P;
		ans += (a[i] - sum[a[i]]) * (n - i - (s[n] - s[i])) % P * m;
		ans %= P;
	}
	write(ans);
	return 0;
}
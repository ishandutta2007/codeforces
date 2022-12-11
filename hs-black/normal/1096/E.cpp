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


const int N = 10005, Maxn = 10000;
const int P = 998244353;
int s, r, p;
ll inv[N], jie[N], ans;

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P, mi >>= 1;
	}
	return res;
}

ll C(ll n, ll m) {
	if (n < m) return 0;
	return jie[n] * inv[m] % P * inv[n-m] % P;
}

ll solve(ll S, ll m, ll lim) {
	if (S == 0) return 1;
	ll res = 0;
	for (int i = 0;i <= m && S + m - 1 >= i * lim; i++)
		if (i & 1) res -= C(m, i) * C(S - i * lim + m - 1, m - 1); 
		else res += C(m, i) * C(S - i * lim + m - 1, m - 1);
	res = (res % P + P) % P;
	return res;
}

int main() {
	read(p), read(s), read(r);
	jie[0] = 1;
	for (int i = 1;i <= Maxn; i++) jie[i] = jie[i-1] * i % P;
	inv[Maxn] = fpw(jie[Maxn], P - 2);
	for (int i = Maxn; i; i--) inv[i-1] = inv[i] * i % P;
	
	for (int i = r;i <= s; i++) 
		for (int j = 1;j * i <= s && j <= p; j++) {
			if ((p - j ) *(i - 1) + j * i < s) continue;
			ans = (ans + fpw(j, P - 2) * solve(s - j * i, p - j, i) % P * C(p - 1, j - 1)) % P;
		}
	
	write(fpw(C(s - r + p - 1, p - 1), P - 2) * ans % P);
	
	return 0;
}
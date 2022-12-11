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

const int P = 1e9+7;
const int N = 5005;
ll S[N][N], mi[N], n, k;

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P, mi >>= 1;
	}
	return res;
}

ll C(ll n, ll m) {
	ll up = 1, dw = 1;
	for (ll i = n;i >= n - m + 1; i--)
		up = up * i % P;
	for (ll i = 1;i <= m; i++) dw = dw * i % P;
	return up * fpw(dw, P - 2) % P;
}

int main() {
	read(n), read(k); S[1][1] = 1;
	for (int i = 2;i <= k; i++) 
		for (int j = 1;j <= i; j++) 
			S[i][j] = (j * S[i-1][j] + S[i-1][j-1]) % P;
	ll ans = 0, fac = 1;
	for (int i = 1;i <= min(n, k); i++) {
		fac = fac * i % P;
		ans = (ans + S[k][i] * fac % P * C(n, i) % P * fpw(2, n - i)) % P;
//		if (i % 100 == 0) write(i);
	}
	
	write(ans);
	return 0;
}
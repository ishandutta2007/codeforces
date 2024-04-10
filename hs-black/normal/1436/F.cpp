
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
const int N = 200050;
ll cnt[N], mul[N], sum[N], dp[N];
int lim, m;
ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res *  x % P;
	return res;
}
int main() {
	read(m);
	for (int i = 1, x, t;i <= m; i++) 
		read(x), read(t), cnt[x] += t, Mx(lim, x);
	for (int i = lim;i >= 1; i--) {
		sum[i] = cnt[i] * i % P;
		mul[i] = cnt[i] * i % P * i % P;
		ll res = cnt[i], S = sum[i], M = mul[i], r2;
		for (int j = i + i;j <= lim; j += i) res += cnt[j], S += sum[j], M += mul[j];
		r2 = res % P, S %= P, M %= P;
		if (res > P - 1) res = res % (P - 1) + P - 1;
		ll t1 = res >= 3 ? fpw(2, res - 3) : 0, t2 = res >= 2 ? fpw(2, res - 2) : 0;
		dp[i] = (S * S % P - M) * (t2 + (r2 - 2) * t1 % P) % P;
		dp[i] = (dp[i] + (r2 - 1) * t2 % P * M) % P;
		for (int j = i + i;j <= lim; j += i) dp[i] = dp[i] - dp[j];
		dp[i] = (dp[i] % P + P) % P;
	}
	write(dp[1]);
	return 0;
}

/*

4
1 1
2 1
3 1
6 1


*/
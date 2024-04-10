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
ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P, mi >>= 1;
	}
	return res;
}

ll fac[100], cnt[100], num;
void divide(ll n) {
	for (ll i = 2;i * i <= n; i++) {
		if (n % i) continue;
		fac[++num] = i;
		while (n % i == 0) cnt[num]++, n /= i;
	}
	if (n != 1) fac[++num] = n, cnt[num] = 1;
}

ll dp[20005][50], inv[200], ans, res, n, k;
int main() {
	read(n), read(k), divide(n);
	inv[0] = inv[1] = ans = 1;
	for (int i = 2;i <= 100; i++)
		inv[i] = inv[P % i] * (P - P / i) % P;
	for (int i = 1;i <= num; i++) {
		memset(dp, 0, sizeof(dp));
		dp[0][cnt[i]] = 1, res = 0;
		for (int a = 1;a <= k; a++)
			for (int b = 0;b <= cnt[i]; b++)
				for (int c = b;c <= cnt[i]; c++)
					dp[a][b] = (dp[a-1][c] * inv[c+1] + dp[a][b]) % P;
		for (int a = 0;a <= cnt[i]; a++) 
			res = (res + dp[k][a] * fpw(fac[i] % P, a)) % P;
//		cout << res << endl;
		ans = ans * res % P;
	}
	write(ans);
}
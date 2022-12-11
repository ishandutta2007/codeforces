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

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int P = 998244353;
ll n, p;

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P, mi >>= 1;
	}
	return res;
}

const int N = 2005;
ll H[N], C[N][N], Ans[N];

/*

Ans[i] = (i = 1 to n) H[i] * C[n][i] * (i * (i - 1) / 2 + (n - i) * i + Ans[i] + Ans[n-i])
Ans[i] - H[n] * C[n][n] * ((n * (n - 1) / 2) + Ans[n])
Ans[n] * (1 - H[n]) = 

*/

int main() {
	read(n); ll a, b; read(a), read(b); p = a * fpw(b, P - 2) % P;
	C[0][0] = 1;
	for (int i = 1;i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1;j <= i; j++)
			C[i][j] = (C[i-1][j-1] * fpw(P - p + 1, i - j) + C[i-1][j] * fpw(p, j)) % P;
	}
	H[1] = 1;
	for (int i = 2;i <= n; i++) {
		for (int j = 1;j < i; j++) 
			H[i] -= H[j] * C[i][j] % P;
		H[i] = (H[i] % P + P  + 1) % P;
	}
	
	for (int i = 2;i <= n; i++) {
		ll tmp = 0;
		for (int j = 1;j < i; j++)
			tmp = (tmp + H[j] * C[i][j] % P * ((j * (j - 1) / 2 + (i - j) * j + Ans[j] + Ans[i-j]) % P)) % P;
		tmp = (tmp + H[i] * (i * (i - 1) / 2)) % P;
		Ans[i] = tmp * fpw(1 - H[i], P - 2) % P;
	}
	printf ("%lld\n", (Ans[n] + P) % P);
	return 0;
}
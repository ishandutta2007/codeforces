#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long

using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c=getchar();
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
}

const int N = 2200000;
const int P = 1e9+7;
const int inv2 = (P+1)/2;
ll mi[N], bl[N];
ll f[N], n, m;
char s[N];

inline void FWT_xor(ll *f, ll opt = 1) {
    for (int p = 2, k = 1;p <= m; p <<= 1, k <<= 1) 
        for (int i = 0;i < m; i += p) 
            for (int j = 0;j < k; j++) {
                ll x = f[i+j], y = f[i+j+k];
                f[i+j] = (x + y) % P;
                f[i+j+k] = (x + P - y) % P;
                if (opt==-1) f[i+j] = f[i+j] * inv2 % P, f[i+j+k] = f[i+j+k] * inv2 % P;
            }
}

int main() {
	read(n); m = 1 << n;
	scanf ("%s", s);
	for (int i = 0;i < m; i++) f[i] = s[i] - '0';
	mi[0] = 1;
	for (int i = 1;i <= 30; i++) mi[i] = mi[i-1] << 1;
	for (int i = 1;i <= m; i++) bl[i] = bl[i - (i&-i)] + 1;
	FWT_xor(f, 1);
	for (int i = 0;i < m; i++) f[i] = f[i] * f[i] % P;
	FWT_xor(f, -1); ll ans = f[0] * m % P;
	for (int i = 1;i < m; i++) ans = (ans + f[i] * mi[n-bl[i]]) % P;
	cout << ans * 3 % P << endl;
	return 0;
}
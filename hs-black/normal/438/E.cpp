#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int P = 998244353;
const int G = 3, Gi = (P+1) / G;
const int INV2 = (P+1) / 2;
const int N = 300500;

int read(void) {
	int x = 0, f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return f ? -x : x;
}


ll fpw(ll di, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * di % P;
		di = di * di % P;
		mi >>= 1;
	}
	return res;
}

int lim, r[N], n, L;
ll f[N], g[N], A[N], C[N], D[N];

void NTT(ll *a, int type) {
    for (int i = 0;i < lim; i++)
    if (i < r[i]) swap(a[i], a[r[i]]);
    for (int mid = 1;mid < lim; mid <<= 1) {
        ll wn = fpw(type == 1 ? G : Gi, (P-1)/(mid<<1));
        for (int j = 0;j < lim;j += (mid << 1)) {
            ll w = 1;
            for (int k = 0;k < mid; k++, w = (w * wn) % P) {
                ll x = a[j+k], y = w * a[j+k+mid] % P;
                a[j+k] = (x + y) % P, a[j+k+mid] = (x - y + P) % P;
            }
        }
    }
    if (type == 1) return;
    ll inv = fpw(lim, P-2);
    for (int i = 0;i < lim; i++)
    a[i] = a[i] * inv % P;
}
ll B[N];
void Inv(int deg, ll *a, ll *b) {
	b[0] = fpw(a[0], P-2);
	int len;
	for (len = 1;len < (deg<<1);len <<= 1) {
		lim = len << 1;
		for (int i = 0;i < len; i++) A[i] = a[i], B[i] = b[i];
		for (int i = 0;i < lim; i++) 
			r[i] = (r[i>>1]>>1) | ((i&1)?len:0);
		NTT(A, 1), NTT(B, 1);
		for (int i = 0;i < lim; i++)
			b[i] = (2 - A[i] * B[i] % P + P) * B[i] % P;
		NTT(b, -1);
		for (int i = len;i < lim; i++) b[i] = 0;
	}
	for (int i = 0;i < len; i++) A[i] = B[i] = 0;
	for (int i = deg;i < len; i++) b[i] = 0;
}
		


void Sqrt(int deg, ll *a, ll *b) {
	b[0] = 1;
	ll len;
	for (len = 1;len < (deg << 1);len <<= 1) {
		lim = len << 1;
		for (int i = 0;i < len; i++) C[i] = a[i];
		Inv(len, b, D);
		NTT(C, 1), NTT(D, 1);
		for (int i = 0;i < lim; i++) C[i] = C[i] * D[i] % P;
		NTT(C, -1);
		for (int i = 0;i < len; i++) b[i] = (b[i] + C[i]) * INV2 % P;
		for (int i = len;i < lim; i++) b[i] = 0;
	}
}

		
int m;
 
int main() {
	n = read(), m = read();
	f[0] = 1;
	for (int i = 1;i <= n; i++) f[read()] = P-4;
	n = m + 1;
	Sqrt(n, f, g);
	g[0] += 1;
	for (int i = 0;i <= m; i++) D[i] = 0;
	Inv(n, g, D);
	for (int i = 1;i <= m; i++) printf ("%lld\n", D[i] * 2 % P);
	return 0;
}
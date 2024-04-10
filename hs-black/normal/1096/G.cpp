#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int N = 2200000;
const int P = 998244353;
const int G = 3, Gi = (P+1)/G;

ll fpw(ll x, ll mi) {
    ll res = 1;
    while (mi) {
        if (mi & 1) res = res * x % P;
        x = x * x % P;
        mi >>= 1;
    }
    return res;
}

ll lim, r[N];

void NTT(ll *a, int type) {
    for (int i = 0;i < lim; i++)
        if (r[i] > i) swap(a[i], a[r[i]]);
    for (int j = 1;j < lim; j <<= 1) {
        ll wn = fpw(type == 1 ? G : Gi, (P-1)/(j<<1));
        for (int i = 0;i < lim; i += (j<<1)) {
            ll w = 1;
            for (int k = 0;k < j; k++, w = w * wn % P) {
                ll x = a[i+k], y = a[i+k+j] * w % P;
                a[i+k] = (x + y) % P;
                a[i+k+j] = (x - y + P) % P;
            }
        }
    }
    if (type == 1) return;
    ll inv = fpw(lim, P-2);
    for (int i = 0;i < lim; i++) a[i] = a[i] * inv % P;
}

ll A[N], B[N], n, k;

void mul(ll *a, ll *b) {
    for (int i = 0;i < lim; i++) a[i] = a[i] * b[i] % P;
}

int main() {
    cin >> n >> k;
    for (int i = 1;i <= k; i++) {
        int x; scanf ("%d", &x);
        A[x] = 1;
    }
    B[0] = 1; 
    int t = n / 2 * 9; lim = 1;
    while (lim <= t) lim <<= 1;
    t = lim >> 1;
    for (int i = 0;i < lim; i++) 
        r[i] = (r[i>>1]>>1) | ((i&1) ? t : 0);
    NTT(A, 1), NTT(B, 1); t = n / 2;
    while (t) {
        if (t & 1) mul(B, A);
        mul(A, A);
        t >>= 1;
    } NTT(B, -1);
    ll ans = 0;
    for (int i = 0;i < lim; i++) ans = (ans + B[i] * B[i]) % P;
    cout << ans << endl;
    return 0;
}
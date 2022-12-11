#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 600040;
const int P = 998244353;
const int G = 3, Gi = (P + 1) / G;
int n, m, k;
char s[N], t[N];

ll fpw(ll x, ll mi) {
    ll res = 1;
    while (mi) {
        if (mi & 1) res = res * x % P;
        mi >>= 1;
        x = x * x % P;
    }
    return res;
}

int L, lim = 1, r[N];
ll A[N], B[N], C[N];
void NTT(ll *a, int type) {
    for (int i = 0;i < lim; i++) 
        if (r[i] > i) swap(a[i], a[r[i]]);
    for (int j = 1;j < lim; j <<= 1) {
        ll wn = fpw(type == 1 ? G : Gi, (P-1) / (j << 1));
        for (int i = 0;i < lim; i += j << 1) {
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

void calc(char c) {
    int cnt = 0;
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    for (int i = 0;i < k; i++) cnt += (s[i] == c);
    for (int i = 0;i <= n; i++) {
        if (i + k <= n) cnt += (s[i + k] == c);
        if (i - k - 1 >= 0) cnt -= (s[i - k - 1] == c);
        B[i] = cnt > 0 ? 1 : 0;
    }
    for (int i = 0;i <= m; i++) C[i] = (t[i] == c);
    NTT(B, 1), NTT(C, 1);
    for (int i = 0;i < lim; i++) B[i] = B[i] * C[i] % P;
    NTT(B, -1);
    for (int i = 0;i <= n - m; i++) A[i] += B[i+m];
}

int main() {
    cin >> n >> m >> k; n--, m--;
    scanf ("%s", s); scanf ("%s", t);
    while (lim <= n + m) lim <<= 1, L++;
    for (int i = 0;i < lim; i++)   
        r[i] = (r[i>>1]>>1) | ((i&1) << (L-1));
    reverse(t, t + m + 1); int ans = 0;
    calc('A'); calc('T'); calc('C'); calc('G');
    for (int i = 0;i <= n - m; i++) ans += (A[i] == m + 1);
    cout << ans << endl;
    return 0;
}
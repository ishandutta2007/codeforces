#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N = 2000500;
template <typename T>
void read(T &x) {
    x = 0; char c = getchar();
    while (!isdigit(c)) c=getchar();
    for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
}

int st[50], n, m;
inline void write(int x, char ed = ' ') {
    if (!x) {putchar(48); putchar(ed); return;}
    int top = 0;
    for (;x ; x /= 10) st[++top] = x % 10;
    while (top) putchar(st[top--] ^ 48);
    putchar(ed);
}

ll Mx(ll x, ll y) {return x > y ? x : y;}
ll Mn(ll x, ll y) {return x > y ? y : x;}
inline int to(int x) {return 1 << x;}

char s0[N];
ll q[N], f[N], s[N], lim;
void FWT_or(ll *f, int opt = 1) {
    for (int l = 1, p = 2;l < lim;l <<= 1, p <<= 1) 
        for (int i = 0;i < lim; i += p) 
            for (int k = 0;k < l; k++) {
                ll x = f[i+k], y = f[i+k+l];
                f[i+k] = x + y, f[i+k+l] = x - y;
                if (opt == -1) f[i+k] /= 2, f[i+k+l] /= 2;
            }
}


int main() {    
    read(n), read(m);
    lim = (1 << n);
    for (int i = 1;i < lim; i++) f[i] = f[i - (i & -i)] + 1;
    for (int i = 1;i < lim; i++) f[i] = Mn(f[i], n - f[i]);
    for (int i = 1;i <= n; i++) {
        scanf ("%s", s0 + 1);
        for (int j = 1;j <= m; j++) 
            if (s0[j] == '1') s[j] |= to(i-1);
    }
    for (int i = 1;i <= m; i++) q[s[i]]++;
    FWT_or(f), FWT_or(q);
    for (int i = 0;i < lim; i++) f[i] *= q[i];
    FWT_or(f, -1);
    ll ans = (ll)n * m;
    for (int i = 0;i < lim; i++) ans = Mn(ans, f[i]);
    cout << ans << endl;
    return 0;
}
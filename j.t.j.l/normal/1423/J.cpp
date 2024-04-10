#pragma GCC optimize("Ofast")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int a[555];
const int L = 7;

int f[111][111];

void upd(int &x, int y) {
    x += y;
    if (x >= MM) x -= MM;
}

const int NICO = 16;
const int UMI = 4;
ll gg[8][8][1 << (NICO / 2)];
int g[8][8][1 << NICO];
int n;

void gao(ll m, int _) {
    n = 0;
    while (n < NICO / 2) {
        n++;
        a[n] = m % 2;
        m = m / 2;
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j <= L; j++) f[i][j] = 0;
    f[0][_] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= L; j++) {
            if (f[i][j]) {
                int o = (j ^ a[i + 1]) & 1;
                for (int k = o; k < 8; k += 2) {
                    upd(f[i + 1][(j + k) >> 1], f[i][j]);
                }
            }
        }
    }
}

void prework() {
    for (int _ = 0; _ <= L; _++) {
        for (int m = 0; m < (1 << (NICO / 2)); m++) {
            gao(m, _);
            for (int i = 0; i <= L; i++) {
                gg[_][i][m] = f[n][i];
            }
        }
    }
    int kke = NICO / 2;
    int umi = 1 << (NICO / 2);
    umi -= 1;
    for (int m = 0; m < (1 << NICO); m++) {
        for (int i = 0; i <= L; i++)
            for (int k = 0; k <= L; k++) {
                ll tmp = 0;
                for (int j = 0; j <= L; j++) {
                    tmp += (gg[i][j][m & umi] * gg[j][k][m >> kke]);
                }
                g[i][k][m] = tmp % MM;
            }
    }
}

ll h[10][111];

inline void upd2(ll &x, ll y) {
    x = (x + y) % MM;
}

void solve(int casi){
    ll m;
    scanf("%lld", &m);
    // m = casi * 8 + 6;
    
    if (m % 8 == 0 || m % 8 == 1) {
        ll u = m / 8 * 2 + 1;
        u %= MM; u = u * u % MM;
        printf("%lld\n", u);
        return ;
    } else if (m % 8 == 2 || m % 8 == 3) {
        ll u = m / 8 * 2 + 1;
        u %= MM; u = u * (u + 1) % MM;
        printf("%lld\n", u);
        return ;
    } else if (m % 8 == 4 || m % 8 == 5) {
        ll u = m / 8 * 2 + 1;
        u %= MM; u = (u + 1) * (u + 1) % MM;
        printf("%lld\n", u);
        return ;
    } else if (m % 8 == 6 || m % 8 == 7) {
        ll u = m / 8 * 2 + 1;
        u %= MM; u = (u + 1) * (u + 2) % MM;
        printf("%lld\n", u);
        return ;
    } 
    // m = 1000000000ll * 1000000000ll; // + casi;
    for (int u = 0; u <= UMI; u++)
        for (int i = 0; i <= L; i++) h[u][i] = 0;
    h[0][0] = 1;
    int MAKI = (1 << NICO) - 1;
    int u = 0;
    for (u = 0; u < UMI; u++) {
        for (int i = 0; i <= L; i++) if (h[u][i])
            for (int j = 0; j <= L; j++) {
                upd2(h[u + 1][j], h[u][i] * g[i][j][m & MAKI]);
            }
        m >>= NICO;
        if (m == 0) break;
    }
    printf("%lld\n", h[min(UMI, u + 1)][0]);
}

int main(){
    prework();
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}

// int main(){
//     prework();
//     int T = 1;
//     // scanf("%d", &T);
//     T = 10;
//     for (int i = 1; i <= T; i++)
//         solve(i);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

#define N 531111
typedef long long ll;
#define MOD 2013265921LL
#define GEN 440564289LL
#define IGEN 1713844692LL
#define EX 27

ll ipow(ll b, ll e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    if (e & 1) return ipow(b, e - 1) * b % MOD;
    return ipow(b * b % MOD, e >> 1);
}

ll GENS[EX+1];
ll IGENS[EX+1];
void initfft() {
    assert(ipow(GEN, 1 << EX) == 1);
    assert(ipow(GEN, 1 << EX - 1) == MOD - 1);
    assert(GEN * ll(IGEN) % MOD == 1);
    GENS[EX] = GEN;
    IGENS[EX] = IGEN;
    for (int i = EX-1; i >= 0; i--) {
         GENS[i] =  GENS[i+1] *  GENS[i+1] % MOD;
        IGENS[i] = IGENS[i+1] * IGENS[i+1] % MOD;
    }
    assert(GENS[0] == 1);
    assert(IGENS[0] == 1);
    assert(GENS[1] == MOD - 1);
    assert(IGENS[1] == MOD - 1);
}

void fft(ll *a, ll *b, int e, int m, ll *roots) {
    if (e == 0) return;
    int j = 0;
    for (int i = 0; i < m; i += 2) b[j++] = a[i];
    for (int i = 1; i < m; i += 2) b[j++] = a[i];
    ll w = roots[e--];
    m >>= 1;
    fft(b  , a  , e, m, roots);
    fft(b+m, a+m, e, m, roots);
    ll pw = 1;
    for (int i = 0, j = m; i < m; i++, j++) {
        ll pd = b[j] * pw;
        a[i] = (b[i] + pd) % MOD;
        a[j] = (b[i] - pd) % MOD;
        pw = pw * w % MOD;
    }
}




char s[N];
ll A[N*4];
ll B[N*4];
ll C[N*4];
int n;
void mul() {
    int k = 0;
    while (1 << k <= n) k++;
    k++;
    int m = 1 << k;
    for (int i = 0; i < m; i++) {
        C[i] = 0;
    }
    for (int i = n; i < m; i++) A[i] = B[i] = 0;
    fft(A, C, k, m, GENS);
    fft(B, C, k, m, GENS);
    for (int i = 0; i < m; i++) {
        C[i] = A[i] * B[i] % MOD;
    }
    fft(C, A, k, m, IGENS);
    ll sc = ipow((MOD + 1 >> 1), k);
    for (int i = 0; i < m; i++) {
        C[i] = C[i] * sc % MOD;
        if (C[i] < 0) C[i] += MOD;
    }
    // for (int i = 0; i < 2*n; i++) C[i] = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         C[i + j] += A[i] * B[j];
    //     }
    // }
}


// C[i - (n - 1) + j] += A[i] * B[n - 1 - j]
// C[i - j] += (s[i] == 'K') * (s[j] == 'V')
// C[i + j] += (s[i] == 'K') * (s[-j] == 'V')
// C[i + j - (n-1)] += (s[i] == 'K') * (s[n-1-j] == 'V')

void solve() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++) {
        A[i] = s[i] == 'K';
        B[i] = s[n - 1 - i] == 'V';
    }
    // printf("%s\n", s);

    mul();
    // for (int i = 0; i < n; i++) printf("%lld ", A[i]); puts("");
    // for (int i = 0; i < n; i++) printf("%lld ", B[i]); puts("");
    // for (int i = 0; i < 2*n; i++) printf("%lld ", C[i]); puts("");
    vector<int> valid;
    for (int l = 1; l <= n; l++) {
        bool good = true;
        for (int s = l; s < n; s += l) {
            if (C[s + n - 1] || C[n - 1 - s]) {
                good = false;
                break;
            }
        }
        if (good) valid.push_back(l);
    }

    printf("%d\n", int(valid.size()));
    for (int i = 0; i < valid.size(); i++) {
        printf("%d%c", valid[i], " \n"[i == valid.size() - 1]);
    }
}

int main() {
    initfft();
    int z;
    scanf("%d", &z);
    while (z--) solve();
}
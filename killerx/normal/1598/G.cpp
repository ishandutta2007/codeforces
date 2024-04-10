#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 5e5 + 5;

const int mul = 10;
const int modn = 25;
int mod[modn];

using i64 = long long;

std::random_device rd;
std::mt19937_64 rng(rd());

i64 rand(i64 l, i64 r) {
    return std::uniform_int_distribution <i64> (l, r)(rng);
}

bool is_p(i64 x) {
    for (i64 i = 2; i * i <= x; ++ i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

i64 rand_p(i64 l, i64 r) {
    i64 x;
    do x = rand(l, r); while (!is_p(x));
    return x;
}

struct __INIT {
    __INIT() {
        rep(i, modn) mod[i] = rand_p(1e3, 1e9);
    }
} __init;

inline int exgcd(int a, int b, int &x, int &y) {
    if (!b) return x = 1, y = 0, a;
    else {
        int d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
}

inline int inv(int x, int n) {
    int a, b;
    exgcd(x, n, a, b);
    return (a % n + n) % n;
}

int arrn, sumn;
char arr[mxn], sum[mxn];

inline void report(int l, int m, int r) {
    int carry = 0;
    for (int x = 0; x < sumn; ++ x) {
        int a = x >= m - l ? 0 : arr[m - x - 1];
        int b = x >= r - m ? 0 : arr[r - x - 1];
        if ((a + b + carry) % 10 != sum[sumn - 1 - x]) return ;
        carry = (a + b + carry) / 10;
    }
    printf("%d %d\n", l + 1, m);
    printf("%d %d\n", m + 1, r);
    exit(0);
}

int pw[modn][mxn];
int ipw[modn][mxn];
int harr[modn][mxn];
int rharr[modn][mxn];
int hsum[modn];
int z[mxn];

void init() {
    static int temps[mxn + mxn], tempz[mxn + mxn];
    int n = 0;
    rep(i, sumn) temps[n ++] = sum[i];
    rep(i, arrn) temps[n ++] = arr[i];
    for (int i = 1, l = 0, r = 0; i < n; ++ i) {
        if (i <= r) tempz[i] = std::min(r - i + 1, tempz[i - l]);
        for (; i + tempz[i] < n && temps[i + tempz[i]] == temps[tempz[i]]; ++ tempz[i]);
        if (i + tempz[i] - 1 > r) l = i, r = i + tempz[i] - 1;
    }
    for (int i = sumn; i < n; ++ i) z[i - sumn] = std::min(sumn, tempz[i]);
    rep(s, modn) {
        rep(i, mxn) pw[s][i] = i ? 1LL * pw[s][i - 1] * mul % mod[s] : 1;
        int imul = inv(mul, mod[s]);
        rep(i, mxn) ipw[s][i] = i ? 1LL * ipw[s][i - 1] * imul % mod[s] : 1;
        rep(i, arrn) harr[s][i + 1] = (1LL * harr[s][i] * mul + arr[i]) % mod[s];
        for (int i = arrn - 1; ~i; -- i) rharr[s][i] = (rharr[s][i + 1] + 1LL * pw[s][arrn - 1 - i] * arr[i]) % mod[s];
        hsum[s] = 0;
        rep(i, sumn) hsum[s] = (1LL * hsum[s] * mul + sum[i]) % mod[s];
    }
}

int get_arr(int s, int l, int r) {
    return (harr[s][r] + mod[s] - 1LL * pw[s][r - l] * harr[s][l] % mod[s]) % mod[s];
}

int main() {
    scanf("%s", arr);
    arrn = strlen(arr);
    scanf("%s", sum);
    sumn = strlen(sum);
    rep(i, arrn) arr[i] -= '0';
    rep(i, sumn) sum[i] -= '0';
    init();
    #define check(l, m, r) { \
        bool ok = true; \
        rep(s, modn) if ((get_arr(s, l, m) + get_arr(s, m, r)) % mod[s] != hsum[s]) { \
            ok = false; break; \
        } \
        if (ok) report(l, m, r); \
    }
    for (int i = 0; i + sumn <= arrn; ++ i) {
        int x = z[i];
        int len = sumn - x;
        for (int l = len; l >= len - 1 && l > 0; -- l) {
            if (i - l >= 0) check(i - l, i, i + sumn);
            if (i + sumn + l <= arrn) check(i, i + sumn, i + sumn + l);
        }
    }
    for (int i = 0; i + (sumn - 1) * 2 <= arrn; ++ i) {
        check(i, i + sumn - 1, i + (sumn - 1) * 2);
    }
    assert(false);
    return 0;
}
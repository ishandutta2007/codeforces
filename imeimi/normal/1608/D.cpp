#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int t(char c) {
    if (c == '?') return 0;
    if (c == 'B') return 1;
    if (c == 'W') return 2;
    return -1;
}

const int mod = 998244353;

int mul(int x, int y) {
    return 1ll * x * y % mod;
}

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = mul(r, x);
        x = mul(x, x);
        p >>= 1;
    }
    return r;
}


int n;
int cnt[3][3];
int f[100005], r[100005];
int nCr(int n, int k) {
    return mul(f[n], mul(r[k], r[n - k]));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) f[i] = mul(f[i - 1], i);
    r[n] = pw(f[n], mod - 2);
    for (int i = n; i >= 1; --i) r[i - 1] = mul(r[i], i);
    for (int i = 1; i <= n; ++i) {
        char S[10];
        cin >> S;
        ++cnt[t(S[0])][t(S[1])];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (i < cnt[1][1] || i < cnt[2][2]) continue;
        int needB = i - cnt[1][1], leftB = cnt[0][1] + cnt[1][0] + cnt[0][0];
        int needW = i - cnt[2][2], leftW = cnt[0][2] + cnt[2][0] + cnt[0][0];
        if (needB > leftB || needW > leftW) continue;
        ans = (ans + mul(nCr(leftB, needB), nCr(leftW, needW))) % mod;
    }
    if (cnt[1][1] == 0 && cnt[2][2] == 0) {
        ans = (ans + mod - pw(2, cnt[0][0])) % mod;
        if (cnt[1][2] == 0 && cnt[1][0] == 0 && cnt[0][2] == 0) {
            ans = (ans + 1) % mod;
        }
        if (cnt[2][1] == 0 && cnt[2][0] == 0 && cnt[0][1] == 0) {
            ans = (ans + 1) % mod;
        }
    }
    printf("%d\n", ans);
    return 0;
}
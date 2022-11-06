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
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, k;
char in[200002];
bool no[200001];
int L[200001];
int R[200001];

int getL(int i) {
    if (no[i]) return 0;
    if (L[i] > 0) return L[i];
    return L[i] = getL((i + n - 2) % n + 1) + 1;
}

int getR(int i) {
    if (no[i]) return 0;
    if (R[i] > 0) return R[i];
    return R[i] = getR(i % n + 1) + 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> k >> in + 1;
    bool all = 1;
    for (int i = 1; i <= n; ++i) {
        int j = i % n + 1;
        if (in[i] == in[j]) {
            no[i] = no[j] = 1;
            all = 0;
        }
    }
    if (all) {
        if (k & 1) {
            for (int i = 1; i <= n; ++i) {
                in[i] ^= 'W' ^ 'B';
            }
        }
        printf(in + 1);
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (no[i]) continue;
        int l = getL(i), r = getR(i);
        int x = min({ l, r, k });
        debug("X[%d]=%d\n", i, x);
        if (x & 1) in[i] ^= 'W' ^ 'B';
    }
    printf(in + 1);
    return 0;
}
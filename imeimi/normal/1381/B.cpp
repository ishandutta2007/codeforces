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
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

const int inf = 1e8;
int n;
int P[4002];
int L[16005];
int R[16005];
bool solve() {
    cin >> n;
    for (int i = 1; i <= n + n; ++i) cin >> P[i];
    P[n + n + 1] = n + n + 1;
    memset(L, 0, sizeof(L));
    L[1] = 1;
    for (int i = 2; i <= n + n + 1; ++i) {
        memcpy(R, L, sizeof(L));
        int j;
        for (j = i - 1; j > 0; --j) {
            if (P[j] > P[i]) break;
        }
        for (int k = -n; k <= i; ++k) {
            if (R[i - k] > j) L[i + k] = i;
        }
    }
    return L[n + n + 1] == n + n + 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        printf(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
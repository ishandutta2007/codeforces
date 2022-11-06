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

int n;
int A[100001];
int B[100001];
bool solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= n; ++i) cin >> B[i];
    int L = n + 1, R = 0;
    for (int i = 1; i <= n; ++i) {
        B[i] -= A[i];
        if (B[i] < 0) return 0;
        if (B[i] > 0) L = min(L, i), R = max(R, i);
    }
    if (!R) return 1;
    for (int i = L + 1; i <= R; ++i) {
        if (B[i] != B[L]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf(solve() ? "YES\n" : "NO\n");
    return 0;
}
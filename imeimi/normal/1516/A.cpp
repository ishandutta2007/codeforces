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

int n, k, A[105];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        for (int i = 1; i < n; ++i) {
            int a = min(k, A[i]);
            k -= a;
            A[i] -= a;
            A[n] += a;
            printf("%d ", A[i]);
        }
        printf("%d\n", A[n]);
    }
    return 0;
}
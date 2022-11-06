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

int gcd(int x, int y) {
    for (; y; swap(x, y)) x %= y;
    return x;
}

int A[100001], B[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int m = 1e9 + 5, n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            B[i] = A[i];
            m = min(m, A[i]);
        }
        sort(A + 1, A + n + 1);
        bool pos = 1;
        for (int i = 1; i <= n; ++i) {
            if (A[i] == B[i]) continue;
            if (A[i] % m) pos = 0;
        }
        printf(pos ? "YES\n" : "NO\n");
    }
    return 0;
}
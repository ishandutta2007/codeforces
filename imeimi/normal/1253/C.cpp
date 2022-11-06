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

int n, m;
llong A[200000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> A[i];
    sort(A, A + n);
    llong ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= m) A[i] += A[i - m];
        ans += A[i];
        printf("%lld ", ans);
    }
    return 0;
}
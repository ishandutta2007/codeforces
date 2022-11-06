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

int n;
int A[200001];
int solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    int i;
    for (i = n; i > 1; --i) {
        if (A[i - 1] < A[i]) break;
    }
    for ( ; i > 1; --i) {
        if (A[i - 1] > A[i]) break;
    }
    return i - 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}
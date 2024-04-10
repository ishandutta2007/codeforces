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
int P[200001];
int A[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> P[i];
        A[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (A[i]) continue;
        A[i] = 1;
        for (int j = P[i]; j != i; j = P[j]) ++A[i];
        for (int j = P[i]; j != i; j = P[j]) A[j] = A[i];
    }
    for (int i = 1; i <= n; ++i) printf("%d ", A[i]);
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
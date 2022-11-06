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
int A[100001], B[100001];

bool check(int x) {
    for (int i = 1; i <= x; ++i) {
        if (A[i] >= A[n + i - x - 1]) return 0;
    }
    for (int i = 1; i <= x + x + 1; ++i) {
        B[i] = (i & 1) ? A[n + i / 2 - x] : A[i / 2];
    }
    for (int i = x + x + 2; i <= n; ++i) B[i] = A[i - x - 1];
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    sort(A + 1, A + (n + 1));
    int s = 0, e = (n - 1) / 2;
    while (s < e) {
        int m = (s + e + 1) / 2;
        if (check(m)) s = m;
        else e = m - 1;
    }
    check(s);
    printf("%d\n", s);
    for (int i = 1; i <= n; ++i) printf("%d ", B[i]);
    return 0;
}
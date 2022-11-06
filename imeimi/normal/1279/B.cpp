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

int n, s;
int A[100001];

int solve() {
    int cnt = 0, sum = 0;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (sum + A[i] <= s) ++cnt, sum += A[i];
        else break;
    }
    int mx = 0, del = 0;
    for (int i = 1; i <= min(cnt + 1, n); ++i) {
        if (mx < A[i]) mx = A[i], del = i;
    }
    sum -= mx;
    int ans = cnt - 1;
    for (int i = cnt + 1; i <= n; ++i) {
        if (sum + A[i] <= s) ++ans, sum += A[i];
        else break;
    }
    if (cnt < ans) return del;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}
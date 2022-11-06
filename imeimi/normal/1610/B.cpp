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
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int A[200005];

bool check(int n, int x) {
    for (int i = 1, j = n; i <= n; ++i, --j) {
        while (i <= n && A[i] == x) ++i;
        if (i > n) break;
        while (A[j] == x) --j;
        if (A[i] != A[j]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        bool ans = true;
        for (int i = 1; i <= n; ++i) {
            if (A[i] != A[n - i + 1]) {
                ans = check(n, A[i]) || check(n, A[n - i + 1]);
                break;
            }
        }
        printf(ans ? "YES\n" : "NO\n");
    }
    return 0;
}
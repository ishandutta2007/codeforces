#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 2e5 + 10;
lint n, A[M];


struct Seg {
    lint T[M << 2];

    lint init(int lo = 1, int hi = n, int idx = 1) {
        if (lo == hi) return T[idx] = A[lo];
        return T[idx] = __gcd(init(lo, lo + hi >> 1, idx << 1),
            init(1 + (lo + hi >> 1), hi, idx << 1 | 1));
    }
    lint query(lint a, lint b, lint lo = 1, lint hi = n, lint idx = 1) {
        if (b < lo || a > hi) return 0LL;
        if (a <= lo && hi <= b) return T[idx];
        return __gcd(query(a, b, lo, lo + hi >> 1, idx << 1),
            query(a, b, 1 + (lo + hi >> 1), hi, idx << 1 | 1));
    }
} S;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    if (n <= 2) {
        if (n == 2 && abs(A[1] - A[2]) == 1) {
            cout << 1 << '\n'; return;
        }
        cout << n << '\n'; return;
    }
    for (int i = 1; i < n; i++) {
        A[i] = abs(A[i] - A[i + 1]);
    }
    n -= 1; S.init(); 

    int ans = 1;
    for (int i = 1, r = 1; i <= n; i++) {
        r = max(r, i); lint g = S.query(i, r);
        while (g != 1 && r + 1 <= n && __gcd(g, A[r + 1]) != 1) {
            g = __gcd(g, A[r + 1]);
            r += 1;
        }
        if (g != 1) ans = max(ans, r - i + 2);
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
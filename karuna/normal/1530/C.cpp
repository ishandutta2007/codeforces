#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 1e5 + 10, INF = 1e9 + 10;

int n, A[M], B[M];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    sort(A + 1, A + 1 + n, greater<int>());
    sort(B + 1, B + 1 + n, greater<int>());

    for (int i = 1; i <= n; i++) {
        A[i] += A[i - 1]; B[i] += B[i - 1];
    }
    int lo = 0, hi = INF;
    while (lo < hi) {
        int mid = lo + hi >> 1;
        int k = (n + mid) - (n + mid) / 4;

        lint a = 0, b = 0;
        if (k - mid >= 0 && k - mid <= n) a = A[k - mid] + mid * 100LL;
        else a = k * 100LL;
        if (k >= n) b = B[n];
        else b = B[k];

        if (a >= b) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
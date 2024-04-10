#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int M = 1e5 + 10;

int n, A[M];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        sort(A + 1, A + 1 + n);

        lint ans = 0, s = 0;
        for (int i = 2; i <= n; i++) {
            ans += A[i] - A[i - 1];
            ans += s - 1LL * (i - 1) * A[i];
            s += A[i];
        }
        cout << ans << '\n';
    }
}
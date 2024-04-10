#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int M = 4e5 + 10;

int n, A[M];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        lint ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        A[n + 1] = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (A[i] >= A[i - 1]) ans += A[i] - A[i - 1];
            else ans += A[i - 1] - A[i];
        }
        for (int i = 1; i <= n; i++) {
            if (A[i] > max(A[i - 1], A[i + 1]))
                ans -= A[i] - max(A[i - 1], A[i + 1]);
        }
        cout << ans << '\n';
    }
}
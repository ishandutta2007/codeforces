#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 1e5 + 10;

int A[101];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, f = 1; cin >> n >> x;
        for (int i = 1; i <= n; i++) cin >> A[i];
        sort(A + 1, A + 1 + n);
        for (int i = 1, s = 0; i <= n; i++) {
            s += A[i];
            if (x == s) {
                if (A[i] == A[n]) {
                    f = 0;
                    break;
                }
                else {
                    swap(A[i], A[n]);
                    break;
                }
            }
        }
        if (f) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << A[i] << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }
}
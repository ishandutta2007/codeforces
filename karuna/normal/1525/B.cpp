#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

int t, n, A[55];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];
        int f = 0;
        for (int i = 1; i <= n; i++) {
            if (i != A[i]) f = 1;
        }
        if (f == 0) {
            cout << 0 << '\n';
        }
        else if (A[n] == n || A[1] == 1) {
            cout << 1 << '\n';
        }
        else if (A[1] == n && A[n] == 1) {
            cout << 3 << '\n';
        }
        else cout << 2 << '\n';

    }
}
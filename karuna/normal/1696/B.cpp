#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> A(n + 2);
        for (int i = 1; i <= n; i++) cin >> A[i];
        int ans = n;
        for (int i = 1; i <= n; i++) {
            if (A[i] == 0) ans -= 1;
        }
        for (int i = 1; i < n; i++) {
            if (A[i] && A[i + 1]) ans -= 1;
        }
        cout << min(ans, 2) << '\n';
    }
}
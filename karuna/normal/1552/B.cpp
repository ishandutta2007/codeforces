#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 5e4 + 10;
int n, A[5][M];

bool comp(int i, int j) {
    int count = 0;
    for (int k = 0; k < 5; k++) {
        if (A[k][j] < A[k][i]) count += 1;
    }
    return count >= 3;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[j][i];
        }
    }
    int mx = 1;
    for (int i = 2; i <= n; i++) {
        if (comp(mx, i)) mx = i;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) if (i != mx) {
        if (comp(i, mx)) count += 1;
    }
    if (count == n - 1) cout << mx << '\n';
    else cout << -1 << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
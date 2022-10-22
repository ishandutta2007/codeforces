#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 2e5 + 10;
int n, A[M], Chk[M], B[M], C[M];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) {
        Chk[i] = 0; B[i] = 0; C[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (Chk[A[i]] == 0) {
            Chk[A[i]] = 1; B[i] = 1;
            ans += 1;
        }
    }
    vector<int> X, Y;
    for (int i = 1; i <= n; i++) {
        if (Chk[i] == 0) {
            if (B[i] == 0) X.push_back(i);
            else Y.push_back(i);
        }
    }
    if (Y.size() != 0 || X.size() != 1) {
        if (X.size() == 1) {
            A[X[0]] = Y.back(); Y.pop_back();
            B[X[0]] = 1; Y.push_back(X[0]);
        }
        else {
            sort(X.begin(), X.end());
            for (int i = 0; i < X.size(); i++) {
                A[X[i]] = (i + 1 == X.size() ? X[0] : X[i + 1]);
                B[X[i]] = 1;
            }
        }
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) {
            if (B[i]) cout << A[i] << ' ';
            else cout << Y.back() << ' ', Y.pop_back();
        }
        cout << '\n';
    }
    else {
        int x = X.back(), y = 0;
        for (int i = 1; i <= n; i++) {
            if (B[i] == 1 && A[i] == A[x]) {
                y = i; break;
            }
        }
        A[x] = A[y]; A[y] = x;
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) {
            cout << A[i] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
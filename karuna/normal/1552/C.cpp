#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 110;
int Chk[M << 1]; pint A[M];
void solve() {
    int n, k; cin >> n >> k;
    memset(Chk, 0, sizeof Chk);
    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        A[i].va = x; A[i].vb = y;
        Chk[x] = 1; Chk[y] = 1;
    }
    vector<int> V;
    for (int i = 1; i <= 2 * n; i++) {
        if (!Chk[i]) V.push_back(i);
    }
    int x = n - k;
    for (int i = 0; i < x; i++) {
        A[k + 1 + i] = pint(V[i], V[i + x]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> X; 
            X.push_back(A[i].va); X.push_back(A[i].vb);
            X.push_back(-A[j].va); X.push_back(-A[j].vb);

            sort(X.begin(), X.end(), [&](int a, int b) {
                return abs(a) < abs(b);
            });
            if (X[0] * X[1] < 0 && X[1] * X[2] < 0 && X[2] * X[3] < 0) ans += 1;
        }
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
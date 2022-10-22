#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 510;
void solve() {
    string S, T; cin >> S >> T;
    int t = T.size();

    int f = 0;
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < T.size(); j++) {
            if (i + j >= S.size()) continue;
            if (S.substr(i, j + 1) != T.substr(0, j + 1)) break;

            string X = T.substr(j + 1); reverse(X.begin(), X.end());
            if (i + 2 * j + 1 - t < 0) continue;
            if (S.substr(i + 2 * j + 1 - t, t - j - 1) != X) continue;

            f = 1; break;
        }
        if (f == 1) break;
    }
    cout << (f ? "YES\n" : "NO\n");
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
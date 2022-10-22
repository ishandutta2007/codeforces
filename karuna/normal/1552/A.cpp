#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

void solve() {
    int n; string S; cin >> n >> S;
    string T; T = S;
    sort(T.begin(), T.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] != T[i]) ans += 1;
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
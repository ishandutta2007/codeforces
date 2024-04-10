#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string S; cin >> S;
        int ans = 0;
        for (int i = 0; i < S.size(); i++) {
            ans = max(ans, S[i] - '0');
        }
        cout << ans << '\n';
    }
}
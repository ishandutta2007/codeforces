#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n;
        string s;
        cin >> n >> s;
        int tx = 1, ty = 1;
        for (char c : s)
            (c == 'D' ? tx : ty) += 1;
        LL ans = (n - tx + 1) * (n - ty + 1) + s.size();
        int ok = 0;
        for (int i = 0; i < s.size(); i += 1) {
            if (i and s[i] != s[i - 1]) ok = 1;
            if (ok) ans += n - (s[i] == 'R' ? tx : ty);
        }
        if (ok) cout << ans << "\n";
        else cout << n << "\n";
    }
}
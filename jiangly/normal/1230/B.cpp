#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve(int case_id) {
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 1) {
        cout << "0\n";
        return;
    }
    string s;
    cin >> s;
    --s[0];
    for (char &c : s) {
        if (k == 0)
            break;
        if (c != '0') {
            c = '0';
            --k;
        }
    }
    ++s[0];
    cout << s << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}
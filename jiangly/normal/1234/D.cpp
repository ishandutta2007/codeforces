#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve(int case_id) {
    string s;
    int q;
    cin >> s >> q;
    set<int> pos[26];
    for (int i = 0; i < int(s.length()); ++i)
        pos[s[i] - 'a'].insert(i);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p;
            char c;
            cin >> p >> c;
            --p;
            pos[s[p] - 'a'].erase(p);
            s[p] = c;
            pos[c - 'a'].insert(p);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            int ans = 0;
            for (int i = 0; i < 26; ++i) {
                auto it = pos[i].lower_bound(l);
                if (it != pos[i].end() && *it < r)
                    ++ans;
            }
            cout << ans << "\n";
        }
    }
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
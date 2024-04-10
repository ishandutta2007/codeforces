#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int ans = 0, x = 0, y = 0;
        string s;
        cin >> s;
        set<pair<pair<int, int>, pair<int, int>>> st;
        for (auto c : s) {
            int x2 = x, y2 = y;
            if (c == 'S') x2--;
            if (c == 'N') x2++;
            if (c == 'W') y2--;
            if (c == 'E') y2++;
            if (st.find({{x, y}, {x2, y2}}) == st.end()) {
                ans += 5;
            }
            else ans += 1;
            st.insert({{x, y}, {x2, y2}});
            st.insert({{x2, y2}, {x, y}});
            x = x2, y = y2;
        }
        cout << ans << endl;
    }
}
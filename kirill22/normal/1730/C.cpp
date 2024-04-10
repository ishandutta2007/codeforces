#include "bits/stdc++.h"

using namespace std;

void solve() {
    string s;
    cin >> s;
    string res = "";
    map<int, int> cnt;
    for (auto c : s) {
        cnt[c - '0']++;
    }
    multiset<int> st;
    int j = 0;
    for (int i = 0; i < 10; i++) {
        while (cnt[i]) {
            int x = s[j] - '0';
            if (x > i) {
                st.insert(min(9, x + 1));
            } else {
                res += (char) ('0' + x);
            }
            cnt[x]--;
            j++;
        }
        while ((int) st.size() && *st.begin() == i) {
            res += (char) ('0' + i);
            st.erase(st.begin());
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
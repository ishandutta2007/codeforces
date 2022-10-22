#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        set<char> st;
        int ans = 1;
        for (auto c : s) {
            st.insert(c);
            if ((int) st.size() >= 4) {
                ans++;
                st.clear();
                st.insert(c);
            }
        }
        cout << ans << '\n';
    }
}
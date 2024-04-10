#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<string> st;
        set<string> st2;
        string s, u;
        bool ans = false;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            u = s;
            reverse(u.begin(), u.end());
            if (!ans) {
                if (s == u) {
                    ans = true;
                }
                if (st.count(u)) {
                    ans = true;
                }
                if (s.length() == 3) {
                    u.pop_back();
                    if (st.count(u)) {
                        ans = true;
                    }
                } else {
                    if (st2.count(u)) {
                        ans = true;
                    }
                }
            }
            st.insert(s);
            if (s.length() == 3) {
                st2.insert(s.substr(0, 2));
            }
        }
        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
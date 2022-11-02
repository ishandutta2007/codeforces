#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int ans[MAXN];

main() {
    int n;
    cin >> n;
    vector<int> st;
    vector<int> q(2 * n);
    int cur = 0;
    for (int i = 0; i < 2 * n; ++i) {
        char t;
        cin >> t;
        if (t == '+') {
            q[i] = -1;
            st.push_back(cur);
            cur++;
        } else {
            int x;
            cin >> x;
            if (st.empty()) {
                cout << "NO";
                return 0;
            }
            ans[st.back()] = x;
            st.pop_back();
            q[i] = x;
        }
    }
    set<int> s;
    cur = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (q[i] == -1) {
            s.insert(ans[cur]);
            cur++;
        } else {
            int mn = *s.begin();
            s.erase(mn);
            if (mn != q[i]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
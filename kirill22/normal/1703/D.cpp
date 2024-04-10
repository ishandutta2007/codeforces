#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<string> a;
        vector<string> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            a.insert(b[i]);
        }
        for (int i = 0; i < n; i++) {
            int ans = 0;
            for (int j = 1; j < (int) b[i].size(); j++) {
                string l = b[i].substr(0, j), r = b[i].substr(j);
                if (a.find(l) != a.end() && a.find(r) != a.end()) {
                    ans = 1;
                }
            }
            cout << ans;
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int ans = numeric_limits<int>::max();
    for (int p = 0; p < (int)v[0].size(); p++) {
        auto target = v[0].substr(p) + v[0].substr(0, p);
        int needed = p;
        for (int i = 1; i < n; i++) {
            bool found = false;
            for (int q = 0; q < (int)v[0].size(); q++) {
                auto tt = v[i].substr(q) + v[i].substr(0, q);
                if (tt == target) {
                    found = true;
                    needed += q;
                    break;
                }
            }
            if (!found) {
                cout << -1 << endl;
                return 0;
            }
        }
        ans = min(ans, needed);
    }
    cout << ans << endl;
}
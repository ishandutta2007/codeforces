#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int x, s;
    cin >> x >> s;
    if (x == s && s == 0) {
        cout << 0;
        return 0;
    }
    if (x > s) {
        cout << -1;
        return 0;
    }
    vector<int> ans;
    ans.push_back(x);
    s -= x;
    for (int j = 62; j >= 0; j--) {
        if ((x & (1ll << j)) == 0) {
            int c = s / (1ll << j);
            if (c % 2 == 1) c--;
            for (int i = 0; i < c; i++) {
                if (i < ans.size()) {
                    ans[i] += (1ll << j);
                }
                else ans.push_back(1ll << j);
            }
            s -= c * (1ll << j);
        }
        else {
            int c = s / (1ll << j);
            if (c % 2 == 1) c--;
            for (int i = 1; i <= c; i++) {
                if (i < ans.size()) {
                    ans[i] += (1ll << j);
                }
                else ans.push_back(1ll << j);
            }
            s -= c * (1ll << j);
        }
    }
    if (s != 0) {
        cout << -1;
        return 0;
    }
    cout << ans.size() << endl;
    for (auto el : ans) cout << el << " ";
}
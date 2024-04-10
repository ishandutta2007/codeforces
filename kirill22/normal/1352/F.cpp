#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q; while (q--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        if (n0 == 0 && n2 == 0) {
            string ans = "1";
            while (n1--) {
                if (ans.back() == '1') ans += "0";
                else ans += "1";
            }
            cout << ans << endl;
            continue;
        }
        string ans = "";
        for (int i = 0; i < n0 + 1 && n0; i++) ans += "0";
        for (int i = 0; i < n2 + 1 && n2; i++) ans += "1";
        if (n0 > 0 && n2 > 0) n1--;
        while (n1--) {
            if (ans.back() == '1') ans += "0";
            else ans += "1";
        }
        cout << ans << endl;
    }
}
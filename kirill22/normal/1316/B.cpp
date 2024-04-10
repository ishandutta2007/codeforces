#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        string s;
        cin >> n >> s;
        string ans = "";
        int k = 1e18;
        for (int i = 0; i < n; i++) {
            int x = n - i;
            string t = s.substr(i, n - i), t2 = s.substr(0, i);
            if (x % 2 == 0) {
                t += t2;
            }
            else {
                reverse(t2.begin(), t2.end());
                t += t2;
            }
            //cout << t << endl;
            if (k == 1e18) {
                ans = t;
                k = i + 1;
            }
            else if (t < ans) {
                ans = t;
                k = i + 1;
            }
            else if (t == ans && k > i + 1) {
                ans = t;
                k = i + 1;
            }
        }
        cout << ans << endl << k << endl;
    }
}
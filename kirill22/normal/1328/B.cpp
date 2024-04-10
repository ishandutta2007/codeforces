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
        int n, k;
        cin >> n >> k;
        string s = "";
        for (int i = 0; i < n; i++) s += 'a';
        for (int i = 1; i < n; i++) {
            if (k > i) {
                k -= i;
                continue;
            }
            s[n - i - 1] = 'b';
            s[n - k] = 'b';
            break;
        }
        cout << s << endl;
    }
}
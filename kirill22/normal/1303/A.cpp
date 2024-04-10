#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long

unordered_map<int, int> a;

signed main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int si = 0, l = 1e18, r = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                si++;
                l = min(l, i);
                r = max(r, i);
            }
            a[i * si] = si;
        }
        if (si == 0) {
            cout << 0 << endl;
        }
        else {
            cout << r - l + 1 - si << endl;
        }
    }
}
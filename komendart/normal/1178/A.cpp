#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ans;
    int A = 0, B = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[0] >= a[i] * 2) {
            ans.push_back(i + 1);
            A += a[i];
        } else {
            B += a[i];
        }
    }
    if (A <= B) {
        cout << 0 << '\n';
    } else {
        cout << sz(ans) << '\n';
        for (auto i: ans) {
            cout << i << ' ';
        }
    }
}
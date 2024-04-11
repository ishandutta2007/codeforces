#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    int one = 0, two = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x == 1) ++one;
        else ++two;
    }
    
    if (one == 0 || two == 0) {
        for (int i = 0; i < one; ++i) cout << 1 << ' ';
        for (int i = 0; i < two; ++i) cout << 2 << ' ';
    } else {
        cout << 2 << ' ' << 1 << ' ';
        --one; --two;
        for (int i = 0; i < two; ++i) cout << 2 << ' ';
        for (int i = 0; i < one; ++i) cout << 1 << ' ';
    }
}
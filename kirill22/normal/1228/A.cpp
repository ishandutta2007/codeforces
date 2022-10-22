#include<bits/stdc++.h>

using namespace std;

#define int long long

bool f (int x) {
    vector<int> a;
    if (x == 0) {
        a.push_back(0);
    }
    while (x > 0) {
        a.push_back(x % 10);
        x /= 10;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] == a[i + 1]) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (f(i)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
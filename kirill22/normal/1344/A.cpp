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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool f = true;
        map<int, int> b;
        for (int i = 0; i < n; i++) {
            b[((i + a[i]) % n + n) % n]++;
        }
        if (b.size() != n) f = false;
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
}
#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    while (cin >> n) {
        vector<int> a(n), b(n), used(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        bool f = false;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            int tmp = 0;
            bool fi = true;
            for (int j = i; j < i + n; j++) {
                tmp += b[j % n];
                used[j % n] = true;
                if (tmp < a[j % n]) {
                    fi = false;
                    break;
                }
                tmp = min(b[j % n], tmp - a[j % n]);
            }
            f = f | fi;
        }
        cout << (f ? "YES\n" : "NO\n");
    }
}
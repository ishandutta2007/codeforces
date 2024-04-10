#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define all(a) a.begin(), a.end()

signed main() {
    int q;
    cin >> q;
    while (q--) {
        bool f = true;
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.rbegin(), a.rend());
        int tmp = 0, s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i];
            if (s / (i + 1) < x) break;
            tmp++;
        }
        cout << tmp << '\n';
    }
}